#include "compoundinterestcalculator.h"
#include "ui_compoundinterestcalculator.h"

CompoundInterestCalculator::CompoundInterestCalculator(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CompoundInterestCalculator)
{
    ui->setupUi(this);
}

CompoundInterestCalculator::~CompoundInterestCalculator() {
    delete ui;
}

