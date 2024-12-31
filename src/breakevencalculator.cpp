#include "breakevencalculator.h"
#include "ui_breakevencalculator.h"

BreakEvenCalculator::BreakEvenCalculator(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BreakEvenCalculator)
{
    ui->setupUi(this);
}

BreakEvenCalculator::~BreakEvenCalculator() {
    delete ui;
}
