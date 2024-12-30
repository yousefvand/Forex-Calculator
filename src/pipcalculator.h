#pragma once

#include <QWidget>

namespace Ui {
class PipCalculator;
}

class PipCalculator : public QWidget {
    Q_OBJECT

public:
    explicit PipCalculator(QWidget *parent = nullptr);
    ~PipCalculator();

private slots:
    void calculatePipValue();

private:
    Ui::PipCalculator *ui;
};
