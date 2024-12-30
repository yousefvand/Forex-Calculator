#include "pipcalculator.h"
#include "ui_pip_calculator.h"
#include <QMessageBox>

PipCalculator::PipCalculator(QWidget *parent)
    : QWidget(parent), ui(new Ui::PipCalculator) {

    ui->setupUi(this);

    QStringList currencies = {"USD", "EUR", "JPY", "GBP", "AUD", "CAD", "CHF", "NZD"};
    ui->baseCurrencyCombo->addItems(currencies);
    ui->quoteCurrencyCombo->addItems(currencies);

    connect(ui->calculateButton, &QPushButton::clicked, this, &PipCalculator::calculatePipValue);
}

PipCalculator::~PipCalculator() {
    delete ui;
}

// Pip Calculation with Error Handling
void PipCalculator::calculatePipValue() {
    double lotSize = ui->lotSizeInput->text().toDouble();
    double exchangeRate = ui->exchangeRateInput->text().toDouble();

    QString baseCurrency = ui->baseCurrencyCombo->currentText();
    QString quoteCurrency = ui->quoteCurrencyCombo->currentText();

    // Error handling for invalid input
    if (lotSize <= 0 || exchangeRate <= 0) {
        QMessageBox::warning(this, "Invalid Input", "Lot size and exchange rate must be positive numbers.");
        return;
    }

    // Determine pip size (0.01 for JPY pairs, 0.0001 otherwise)
    double pipSize = (quoteCurrency == "JPY") ? 0.01 : 0.0001;
    // TODO: Show on interface

    // Calculate pip value
    double pipValue = (pipSize * lotSize) / exchangeRate;
    ui->pipValueResult->setText(tr("Pip Value: %1 %2").arg(pipValue).arg(quoteCurrency));
}
