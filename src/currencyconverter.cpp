#include "currencyconverter.h"
#include "ui_currencyconverter.h"

CurrencyConverter::CurrencyConverter(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CurrencyConverter)
{
    ui->setupUi(this);
}

CurrencyConverter::~CurrencyConverter() {
    delete ui;
}

