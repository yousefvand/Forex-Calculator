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

private:
    Ui::BreakEvenCalculator *ui;
};
