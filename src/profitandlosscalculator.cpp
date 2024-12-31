#include "profitandlosscalculator.h"
#include "ui_profitandlosscalculator.h"

ProfitAndLossCalculator::ProfitAndLossCalculator(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ProfitAndLossCalculator)
{
    ui->setupUi(this);
}

ProfitAndLossCalculator::~ProfitAndLossCalculator() {
    delete ui;
}
