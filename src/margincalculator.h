#pragma once

#include <QWidget>

namespace Ui {
class MarginCalculator;
}

class MarginCalculator : public QWidget {
    Q_OBJECT

public:
    explicit MarginCalculator(QWidget *parent = nullptr);
    ~MarginCalculator();

private slots:
    void calculateMargin();  // Slot to handle margin calculation

private:
    Ui::MarginCalculator *ui;
};

