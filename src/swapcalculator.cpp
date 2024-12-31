#include "swapcalculator.h"
#include "ui_swapcalculator.h"

SwapCalculator::SwapCalculator(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SwapCalculator)
{
    ui->setupUi(this);
}

SwapCalculator::~SwapCalculator() {
    delete ui;
}
