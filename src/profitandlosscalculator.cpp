#include "profitandlosscalculator.h"
#include "ui_profitandlosscalculator.h"
#include <QMessageBox>
#include <cmath>

ProfitAndLossCalculator::ProfitAndLossCalculator(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ProfitAndLossCalculator)
{
    ui->setupUi(this);

    // Profit/Loss field should be read-only
    ui->lineEditProfitLoss->setReadOnly(true);

    // Connect the Calculate button to the slot
    connect(ui->pushButtonCalculate, &QPushButton::clicked, this, &ProfitAndLossCalculator::calculateProfitLoss);
}

ProfitAndLossCalculator::~ProfitAndLossCalculator() {
    delete ui;
}

// Profit and Loss Calculation Logic
void ProfitAndLossCalculator::calculateProfitLoss() {
    double entryPrice = ui->lineEditEntryPrice->text().toDouble();
    double exitPrice = ui->lineEditExitPrice->text().toDouble();
    double lotSize = ui->lineEditLotSize->text().toDouble();
    double pipValue = ui->lineEditPipValue->text().toDouble();

    // Validation - Ensure all fields are filled with positive values
    if (entryPrice <= 0 || exitPrice <= 0 || lotSize <= 0 || pipValue <= 0) {
        QMessageBox::warning(this, "Invalid Input", "All fields must have positive values.");
        return;
    }

    // Calculate profit/loss
    double profitLoss = (exitPrice - entryPrice) * lotSize * pipValue;

    // Display result with 2 decimal places
    ui->lineEditProfitLoss->setText(QString::number(profitLoss, 'f', 2));
}
