#pragma once

#include <QWidget>

namespace Ui {
class CompoundInterestCalculator;
}

class CompoundInterestCalculator : public QWidget {
    Q_OBJECT

public:
    explicit CompoundInterestCalculator(QWidget *parent = nullptr);
    ~CompoundInterestCalculator();

private slots:
    void calculateCompoundInterest();

private:
    Ui::CompoundInterestCalculator *ui;
};

