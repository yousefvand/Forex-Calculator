#include <QMessageBox>
#include "pipcalculator.h"
#include "ui_pipcalculator.h"

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

void PipCalculator::calculatePipValue() {
    double lotSize = ui->lotSizeInput->text().toDouble();
    double exchangeRate = ui->exchangeRateInput->text().toDouble(); // TODO: Read exchange rate from online APIs

    QString baseCurrency = ui->baseCurrencyCombo->currentText();
    QString quoteCurrency = ui->quoteCurrencyCombo->currentText();

    if (lotSize <= 0 || exchangeRate <= 0) {
        QMessageBox::warning(this, "Invalid Input", "Lot size and exchange rate must be positive numbers.");
        return;
    }

    // Determine pip size (0.01 for JPY pairs, 0.0001 otherwise)
    double pipSize = (quoteCurrency == "JPY") ? 0.01 : 0.0001;

    // Calculate pip value
    double pipValue = (pipSize * lotSize) / exchangeRate;
    ui->pipValueResult->setText(tr("%1 %2").arg(pipValue).arg(quoteCurrency));
}

void PipCalculator::on_quoteCurrencyCombo_activated(int index)
{
    Q_UNUSED(index);
    QString quoteCurrency = ui->quoteCurrencyCombo->currentText();

    if (quoteCurrency == "JPY") {
        ui->pipSizeCombo->setCurrentIndex(1);
    } else {
        ui->pipSizeCombo->setCurrentIndex(0);
    }
}

