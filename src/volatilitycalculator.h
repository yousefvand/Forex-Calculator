#pragma once

#include <QWidget>

namespace Ui {
class VolatilityCalculator;
}

class VolatilityCalculator : public QWidget {
    Q_OBJECT

public:
    explicit VolatilityCalculator(QWidget *parent = nullptr);
    ~VolatilityCalculator();

private:
    Ui::VolatilityCalculator *ui;
};
