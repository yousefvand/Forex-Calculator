#pragma once

#include <QWidget>

namespace Ui {
class CurrencyConverter;
}

class CurrencyConverter : public QWidget {
    Q_OBJECT

public:
    explicit CurrencyConverter(QWidget *parent = nullptr);
    ~CurrencyConverter();

private slots:
    void convertCurrency();
    void swapCurrencies();

private:
    Ui::CurrencyConverter *ui;
};

