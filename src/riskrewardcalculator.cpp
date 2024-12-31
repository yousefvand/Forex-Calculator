#include "riskrewardcalculator.h"
#include "ui_riskrewardcalculator.h"

RiskRewardCalculator::RiskRewardCalculator(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RiskRewardCalculator)
{
    ui->setupUi(this);
}

RiskRewardCalculator::~RiskRewardCalculator() {
    delete ui;
}
