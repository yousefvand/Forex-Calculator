#pragma once

#include <QWidget>

namespace Ui {
class RiskRewardCalculator;
}

class RiskRewardCalculator : public QWidget {
    Q_OBJECT

public:
    explicit RiskRewardCalculator(QWidget *parent = nullptr);
    ~RiskRewardCalculator();

private slots:
    void calculateRiskReward();  // Slot to handle calculation

private:
    Ui::RiskRewardCalculator *ui;
};
