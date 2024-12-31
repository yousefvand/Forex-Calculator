#include "riskmanagementcalculator.h"
#include "ui_riskmanagementcalculator.h"

RiskManagementCalculator::RiskManagementCalculator(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RiskManagementCalculator)
{
    ui->setupUi(this);
}

RiskManagementCalculator::~RiskManagementCalculator() {
    delete ui;
}
