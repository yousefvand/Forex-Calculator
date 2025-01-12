#include "breakevencalculator.h"
#include "ui_breakevencalculator.h"
#include <QMessageBox>

BreakEvenCalculator::BreakEvenCalculator(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BreakEvenCalculator)
{
    ui->setupUi(this);

    // Connect the Calculate button to the slot
    connect(ui->pushButtonCalculate, &QPushButton::clicked, this, &BreakEvenCalculator::calculateBreakEven);
}

BreakEvenCalculator::~BreakEvenCalculator() {
    delete ui;
}

// Calculation Logic for Break Even
void BreakEvenCalculator::calculateBreakEven() {
    double entryPrice = ui->lineEditEntryPrice->text().toDouble();
    double stopLoss = ui->lineEditStopLoss->text().toDouble();
    double takeProfit = ui->lineEditTakeProfit->text().toDouble();
    double lotSize = ui->lineEditLotSize->text().toDouble();
    double commission = ui->lineEditCommission->text().toDouble();
    double spread = ui->lineEditSpread->text().toDouble();
    double swap = ui->lineEditSwap->text().toDouble();
    double riskPercent = ui->doubleSpinBoxRisk->value();
    double accountBalance = ui->lineEditAccountBalance->text().toDouble();

    // Validate required fields
    if (entryPrice == 0 || lotSize == 0 || accountBalance == 0 || riskPercent == 0) {
        QMessageBox::warning(this, "Input Error", "Entry Price, Lot Size, Account Balance, and Risk Percent cannot be zero.");
        return;
    }

    // Calculate total cost
    double totalCost = commission + (spread / 10.0) + swap;

    // Calculate the maximum risk amount based on account balance and risk percent
    double maxRiskAmount = (accountBalance * riskPercent) / 100.0;

    // Calculate break-even price
    double breakEvenPrice = entryPrice + (totalCost / lotSize);

    // Calculate risk per trade (entry - stop loss) and adjust for risk percentage
    double riskPerTrade = entryPrice - stopLoss;
    double allowedLotSize = maxRiskAmount / riskPerTrade;

    // Calculate risk-reward ratio
    double riskRewardRatio = (takeProfit - entryPrice) / riskPerTrade;

    // Update output fields
    ui->lineEditBreakEvenPrice->setText(QString::number(breakEvenPrice, 'f', 2));
    ui->lineEditTotalCost->setText(QString::number(totalCost, 'f', 2));
    ui->lineEditRiskRewardRatio->setText(QString::number(riskRewardRatio, 'f', 2));
    ui->lineEditAllowedLotSize->setText(QString::number(allowedLotSize, 'f', 2));
}
