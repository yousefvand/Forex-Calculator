#pragma once

#include <QWidget>

namespace Ui {
class ProfitAndLossCalculator;
}

class ProfitAndLossCalculator : public QWidget {
    Q_OBJECT

public:
    explicit ProfitAndLossCalculator(QWidget *parent = nullptr);
    ~ProfitAndLossCalculator();

private:
    Ui::ProfitAndLossCalculator *ui;
};
