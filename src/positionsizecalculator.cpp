#include "positionsizecalculator.h"
#include "ui_positionsizecalculator.h"
#include <QMessageBox>
#include <cmath>

PositionSizeCalculator::PositionSizeCalculator(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PositionSizeCalculator)
{
    ui->setupUi(this);

    ui->lineEditPositionSize->setReadOnly(true);

    // Connect the Calculate button to the slot
    connect(ui->pushButtonCalculate, &QPushButton::clicked, this, &PositionSizeCalculator::calculatePositionSize);
}

PositionSizeCalculator::~PositionSizeCalculator() {
    delete ui;
}

// Position Size Calculation Logic
void PositionSizeCalculator::calculatePositionSize() {
    double accountSize = ui->lineEditAccountSize->text().toDouble();
    double riskPercentage = ui->doubleSpinBoxRisk->value() / 100.0;  // Convert % to decimal
    double stopLossPips = ui->lineEditStopLoss->text().toDouble();
    double pipValue = ui->lineEditPipValue->text().toDouble();

    // Validation to ensure fields are not zero or negative
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
