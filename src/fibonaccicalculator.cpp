#include "fibonaccicalculator.h"
#include "ui_fibonaccicalculator.h"

FibonacciCalculator::FibonacciCalculator(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FibonacciCalculator)
{
    ui->setupUi(this);
}

FibonacciCalculator::~FibonacciCalculator() {
    delete ui;
}
