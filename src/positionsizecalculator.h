#pragma once

#include <QWidget>

namespace Ui {
class PositionSizeCalculator;
}

class PositionSizeCalculator : public QWidget {
    Q_OBJECT

public:
    explicit PositionSizeCalculator(QWidget *parent = nullptr);
    ~PositionSizeCalculator();

private:
    Ui::PositionSizeCalculator *ui;
};
