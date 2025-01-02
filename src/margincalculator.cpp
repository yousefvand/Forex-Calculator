#include "margincalculator.h"
#include "ui_margincalculator.h"
#include <QMessageBox>

MarginCalculator::MarginCalculator(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MarginCalculator)
{
    ui->setupUi(this);

    // Populate leverage options
    QStringList leverageOptions = {"10:1", "25:1", "50:1", "100:1", "200:1", "500:1"};
    ui->comboBoxLeverage->addItems(leverageOptions);

    // Set initial exchange rate to 1.0 (for same currency pairs)
    ui->lineEditExchangeRate->setText("1.0");
    ui->lineEditRequiredMargin->setReadOnly(true);

    // Connect Calculate button to slot
    connect(ui->pushButtonCalculate, &QPushButton::clicked, this, &MarginCalculator::calculateMargin);
}

MarginCalculator::~MarginCalculator() {
    delete ui;
}

// Margin Calculation Logic
void MarginCalculator::calculateMargin() {
    double tradeSize = ui->lineEditTradeSize->text().toDouble();
    double exchangeRate = ui->lineEditExchangeRate->text().toDouble();

    // Extract leverage ratio from comboBox (e.g., 100:1 -> 100)
    QString leverageText = ui->comboBoxLeverage->currentText();
    double leverage = leverageText.split(":")[0].toDouble();

    // Validation - Ensure inputs are positive
    if (tradeSize <= 0 || leverage <= 0 || exchangeRate <= 0) {
        QMessageBox::warning(this, "Invalid Input", "Please ensure all fields contain valid positive values.");
        return;
    }

    // Calculate required margin
    double requiredMargin = (tradeSize / leverage) * exchangeRate;

    // Display result with 2 decimal places
    ui->lineEditRequiredMargin->setText(QString::number(requiredMargin, 'f', 2));
}
