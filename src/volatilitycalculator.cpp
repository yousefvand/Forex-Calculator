#include "volatilitycalculator.h"
#include "ui_volatilitycalculator.h"

VolatilityCalculator::VolatilityCalculator(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::VolatilityCalculator)
{
    ui->setupUi(this);
}

VolatilityCalculator::~VolatilityCalculator() {
    delete ui;
}
