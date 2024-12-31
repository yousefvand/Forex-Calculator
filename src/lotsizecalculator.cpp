#include "lotsizecalculator.h"
#include "ui_lotsizecalculator.h"

LotSizeCalculator::LotSizeCalculator(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LotSizeCalculator)
{
    ui->setupUi(this);
}

LotSizeCalculator::~LotSizeCalculator() {
    delete ui;
}

