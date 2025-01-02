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

private slots:
    void calculateVolatility();

private:
    Ui::VolatilityCalculator *ui;
    double calculateTrueRange(double high, double low, double prevClose);
    double calculateAverageTrueRange(const QList<double>& highPrices, const QList<double>& lowPrices, const QList<double>& closePrices, int period);
};
