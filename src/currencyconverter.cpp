#include "currencyconverter.h"
#include "ui_currencyconverter.h"
#include <QMessageBox>

CurrencyConverter::CurrencyConverter(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CurrencyConverter)
{
    ui->setupUi(this);

    // Populate combo boxes with currencies
    QStringList currencies = {"USD", "EUR", "GBP", "JPY", "AUD", "CAD", "CHF", "NZD"};
    ui->comboBoxFromCurrency->addItems(currencies);
    ui->comboBoxToCurrency->addItems(currencies);

    // Default values
    ui->lineEditExchangeRate->setText("1.0");
    ui->lineEditConvertedAmount->setReadOnly(true);  // Converted amount should not be editable

    // Connect button click to conversion logic
    connect(ui->pushButtonConvert, &QPushButton::clicked, this, &CurrencyConverter::convertCurrency);

    // Swap button logic (Optional)
    connect(ui->comboBoxFromCurrency, SIGNAL(currentIndexChanged(int)), this, SLOT(swapCurrencies()));
}

CurrencyConverter::~CurrencyConverter() {
    delete ui;
}

// Conversion Logic
void CurrencyConverter::convertCurrency() {
    // Get user input
    double amount = ui->lineEditAmount->text().toDouble();
    double exchangeRate = ui->lineEditExchangeRate->text().toDouble();

    // Validation
    if (amount <= 0) {
        QMessageBox::warning(this, "Invalid Amount", "Please enter a valid amount to convert.");
        return;
    }

    if (exchangeRate <= 0) {
        QMessageBox::warning(this, "Invalid Exchange Rate", "Exchange rate must be greater than zero.");
        return;
    }

    // Perform currency conversion
    double convertedAmount = amount * exchangeRate;

    // Display result in read-only field
    ui->lineEditConvertedAmount->setText(QString::number(convertedAmount, 'f', 2));
}

// Optional: Swap "From" and "To" currencies
void CurrencyConverter::swapCurrencies() {
    int fromIndex = ui->comboBoxFromCurrency->currentIndex();
    int toIndex = ui->comboBoxToCurrency->currentIndex();

    ui->comboBoxFromCurrency->setCurrentIndex(toIndex);
    ui->comboBoxToCurrency->setCurrentIndex(fromIndex);
}
