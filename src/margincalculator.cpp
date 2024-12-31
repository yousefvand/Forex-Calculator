#include "margincalculator.h"
#include "ui_margincalculator.h"

MarginCalculator::MarginCalculator(QWidget *parent)
    : QWidget(parent)  // QWidget here
    , ui(new Ui::MarginCalculator)
{
    ui->setupUi(this);
}

MarginCalculator::~MarginCalculator() {
    delete ui;
}
