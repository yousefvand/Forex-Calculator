#pragma once

#include <QWidget>

namespace Ui {
class LotSizeCalculator;
}

class LotSizeCalculator : public QWidget {
    Q_OBJECT

public:
    explicit LotSizeCalculator(QWidget *parent = nullptr);
    ~LotSizeCalculator();

private:
    Ui::LotSizeCalculator *ui;
};
