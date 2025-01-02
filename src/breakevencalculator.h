#pragma once

#include <QWidget>

namespace Ui {
class BreakEvenCalculator;
}

class BreakEvenCalculator : public QWidget {
    Q_OBJECT

public:
    explicit BreakEvenCalculator(QWidget *parent = nullptr);
    ~BreakEvenCalculator();

private slots:
    void calculateBreakEven();

private:
    Ui::BreakEvenCalculator *ui;
};
