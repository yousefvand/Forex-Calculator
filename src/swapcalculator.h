#pragma once

#include <QWidget>

namespace Ui {
class SwapCalculator;
}

class SwapCalculator : public QWidget {
    Q_OBJECT

public:
    explicit SwapCalculator(QWidget *parent = nullptr);
    ~SwapCalculator();

private:
    Ui::SwapCalculator *ui;
};
