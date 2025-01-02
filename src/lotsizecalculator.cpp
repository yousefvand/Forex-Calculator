#include "lotsizecalculator.h"
#include "ui_lotsizecalculator.h"
#include <QMessageBox>
#include <cmath>

LotSizeCalculator::LotSizeCalculator(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LotSizeCalculator)
{
    ui->setupUi(this);

    // Set default risk percentage to 1%
    ui->doubleSpinBoxRisk->setRange(0.01, 100.0);
    ui->doubleSpinBoxRisk->setValue(1.0);

    // Lot size field should be read-only
    ui->lineEditLotSize->setReadOnly(true);

    // Connect the Calculate button to the slot
    connect(ui->pushButtonCalculate, &QPushButton::clicked, this, &LotSizeCalculator::calculateLotSize);
}

LotSizeCalculator::~LotSizeCalculator() {
    delete ui;
}

// Lot Size Calculation Logic
void LotSizeCalculator::calculateLotSize() {
    double accountSize = ui->lineEditAccountSize->text().toDouble();
    double riskPercentage = ui->doubleSpinBoxRisk->value() / 100.0;  // Convert % to decimal
    double stopLossPips = ui->lineEditStopLoss->text().toDouble();
    double pipValue = ui->lineEditPipValue->text().toDouble();

    // Validation to ensure fields are not zero or negative
    if (accountSize <= 0 || stopLossPips <= 0 || pipValue <= 0) {
        QMessageBox::warning(this, "Invalid Input", "All fields must have positive values.");
        return;
    }

    // Calculate lot size
    double riskAmount = accountSize * riskPercentage;
    double lotSize = riskAmount / (stopLossPips * pipValue);

    // Display result with 2 decimal places
    ui->lineEditLotSize->setText(QString::number(lotSize, 'f', 2));
}
