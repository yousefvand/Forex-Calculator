#include "positionsizecalculator.h"
#include "ui_positionsizecalculator.h"

PositionSizeCalculator::PositionSizeCalculator(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PositionSizeCalculator)
{
    ui->setupUi(this);
}

PositionSizeCalculator::~PositionSizeCalculator() {
    delete ui;
}
