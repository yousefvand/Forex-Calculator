#pragma once

#include <QWidget>
#include <QVector>

namespace Ui {
class FibonacciCalculator;
}

class FibonacciCalculator : public QWidget {
    Q_OBJECT

public:
    explicit FibonacciCalculator(QWidget *parent = nullptr);
    ~FibonacciCalculator();

private slots:
    void calculateFibonacci();

private:
    Ui::FibonacciCalculator *ui;
    QVector<quint64> generateFibonacciSequence(int n);
    quint64 calculateNthFibonacci(int n);
    QString formatWithCommas(quint64 number);
};

