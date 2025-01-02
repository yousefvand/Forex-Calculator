#include "riskrewardcalculator.h"
#include "ui_riskrewardcalculator.h"
#include <QMessageBox>
#include <cmath>

RiskRewardCalculator::RiskRewardCalculator(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RiskRewardCalculator)
{
    ui->setupUi(this);

    // Risk-Reward field should be read-only
    ui->lineEditRiskReward->setReadOnly(true);

    // Connect Calculate button to the slot
    connect(ui->pushButtonCalculate, &QPushButton::clicked, this, &RiskRewardCalculator::calculateRiskReward);
}

RiskRewardCalculator::~RiskRewardCalculator() {
    delete ui;
}

// Risk-Reward Calculation Logic
void RiskRewardCalculator::calculateRiskReward() {
    double entryPrice = ui->lineEditEntryPrice->text().toDouble();
    double stopLoss = ui->lineEditStopLoss->text().toDouble();
    double targetPrice = ui->lineEditTargetPrice->text().toDouble();

    // Validation to ensure prices are valid and logical
    if (entryPrice <= 0 || stopLoss <= 0 || targetPrice <= 0) {
        QMessageBox::warning(this, "Invalid Input", "All fields must have positive values.");
        return;
    }

    if (stopLoss >= entryPrice) {
        QMessageBox::warning(this, "Invalid Stop Loss", "Stop loss must be below entry price.");
        return;
    }

    if (targetPrice <= entryPrice) {
        QMessageBox::warning(this, "Invalid Target Price", "Target price must be above entry price.");
        return;
    }

    // Calculate Risk-Reward Ratio
    double risk = entryPrice - stopLoss;
    double reward = targetPrice - entryPrice;
    double ratio = reward / risk;

    // Display result with 2 decimal places
    ui->lineEditRiskReward->setText(QString::number(ratio, 'f', 2));
}
