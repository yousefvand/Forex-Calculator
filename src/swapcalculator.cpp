#include "swapcalculator.h"
#include "ui_swapcalculator.h"
#include <QMessageBox>

SwapCalculator::SwapCalculator(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SwapCalculator)
{
    ui->setupUi(this);

    // Default trade type (Long)
    ui->comboBoxTradeType->addItems({"Long", "Short"});

    // Set minimum nights to 1
    ui->spinBoxNights->setMinimum(1);

    // Swap Fee field should be read-only
    ui->lineEditSwapFee->setReadOnly(true);

    // Connect Calculate button to the slot
    connect(ui->pushButtonCalculate, &QPushButton::clicked, this, &SwapCalculator::calculateSwap);
}

SwapCalculator::~SwapCalculator() {
    delete ui;
}

// Swap Calculation Logic
void SwapCalculator::calculateSwap() {
    double lotSize = ui->lineEditLotSize->text().toDouble();
    double pipValue = ui->lineEditPipValue->text().toDouble();
    double swapRateLong = ui->lineEditSwapRateLong->text().toDouble();
    double swapRateShort = ui->lineEditSwapRateShort->text().toDouble();
    int nights = ui->spinBoxNights->value();
    QString tradeType = ui->comboBoxTradeType->currentText();

    // Validation to ensure values are positive
    if (lotSize <= 0 || pipValue <= 0 || nights <= 0) {
        QMessageBox::warning(this, "Invalid Input", "Lot size, pip value, and nights must be positive.");
        return;
    }

    double swapRate = (tradeType == "Long") ? swapRateLong : swapRateShort;

    // Calculate Swap Fee
    double swapFee = lotSize * pipValue * swapRate * nights;

    // Display result with 2 decimal places
    ui->lineEditSwapFee->setText(QString::number(swapFee, 'f', 2));
}
