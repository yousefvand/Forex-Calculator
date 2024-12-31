#pragma once

#include <QWidget>

namespace Ui {
class FibonacciCalculator;
}

class FibonacciCalculator : public QWidget {
    Q_OBJECT

public:
    explicit FibonacciCalculator(QWidget *parent = nullptr);
    ~FibonacciCalculator();

private:
    Ui::FibonacciCalculator *ui;
};
