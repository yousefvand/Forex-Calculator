#pragma once

#include <QWidget>

namespace Ui {
class RiskManagementCalculator;
}

class RiskManagementCalculator : public QWidget {
    Q_OBJECT

public:
    explicit RiskManagementCalculator(QWidget *parent = nullptr);
    ~RiskManagementCalculator();

private slots:
    void calculateRisk();

private:
    Ui::RiskManagementCalculator *ui;
};

