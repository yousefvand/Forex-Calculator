#include "riskmanagementcalculator.h"
#include "ui_riskmanagementcalculator.h"
#include <QMessageBox>
#include <cmath>

RiskManagementCalculator::RiskManagementCalculator(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RiskManagementCalculator)
{
    ui->setupUi(this);

    // Set default risk percentage
    ui->doubleSpinBoxRisk->setDecimals(2);
    ui->doubleSpinBoxRisk->setRange(0.01, 100.00);
    ui->doubleSpinBoxRisk->setSingleStep(0.01);
    ui->doubleSpinBoxRisk->setValue(1.0);  // Default to 1%

    // Position size field should be read-only
    ui->lineEditPositionSize->setReadOnly(true);

    // Connect Calculate button to the slot
    connect(ui->pushButtonCalculate, &QPushButton::clicked, this, &RiskManagementCalculator::calculateRisk);
}

RiskManagementCalculator::~RiskManagementCalculator() {
    delete ui;
}

// Risk Management Calculation Logic
void RiskManagementCalculator::calculateRisk() {
    double accountSize = ui->lineEditAccountSize->text().toDouble();
    double riskPercentage = ui->doubleSpinBoxRisk->value() / 100.0;  // Convert % to decimal
    double stopLossPips = ui->lineEditStopLoss->text().toDouble();
    double pipValue = ui->lineEditPipValue->text().toDouble();

    // Validation to ensure all fields have positive values
    if (accountSize <= 0 || stopLossPips <= 0 || pipValue <= 0) {
        QMessageBox::warning(this, "Invalid Input", "Please ensure all fields contain valid positive values.");
        return;
    }

    // Calculate position size
    double riskAmount = accountSize * riskPercentage;
    double positionSize = riskAmount / (stopLossPips * pipValue);

    // Display result with 2 decimal places
    ui->lineEditPositionSize->setText(QString::number(positionSize, 'f', 2));
}
