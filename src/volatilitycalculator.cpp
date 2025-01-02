#include "volatilitycalculator.h"
#include "ui_volatilitycalculator.h"
#include <QMessageBox>
#include <cmath>

// TODO: Maybe add chart later
VolatilityCalculator::VolatilityCalculator(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::VolatilityCalculator)
{
    ui->setupUi(this);

    // Default period to 14 (standard in ATR)
    ui->spinBoxPeriod->setMinimum(1);
    ui->spinBoxPeriod->setValue(14);

    // Volatility field should be read-only
    ui->lineEditVolatility->setReadOnly(true);

    // Connect Calculate button to the slot
    connect(ui->pushButtonCalculate, &QPushButton::clicked, this, &VolatilityCalculator::calculateVolatility);
}

VolatilityCalculator::~VolatilityCalculator() {
    delete ui;
}

// True Range Calculation
double VolatilityCalculator::calculateTrueRange(double high, double low, double prevClose) {
    return std::max({high - low, std::abs(high - prevClose), std::abs(low - prevClose)});
}

// Average True Range (ATR) Calculation
double VolatilityCalculator::calculateAverageTrueRange(const QList<double>& highPrices, const QList<double>& lowPrices, const QList<double>& closePrices, int period) {
    double totalTR = 0;
    for (int i = 1; i < highPrices.size(); ++i) {
        double tr = calculateTrueRange(highPrices[i], lowPrices[i], closePrices[i - 1]);
        totalTR += tr;
    }
    return totalTR / period;
}

// Main Volatility Calculation Logic
void VolatilityCalculator::calculateVolatility() {
    QStringList highList = ui->textEditHighPrices->toPlainText().split(',', Qt::SkipEmptyParts);
    QStringList lowList = ui->textEditLowPrices->toPlainText().split(',', Qt::SkipEmptyParts);
    QStringList closeList = ui->textEditClosePrices->toPlainText().split(',', Qt::SkipEmptyParts);

    if (highList.size() < 2 || lowList.size() < 2 || closeList.size() < 2) {
        QMessageBox::warning(this, "Invalid Input", "Please enter at least 2 prices for each field.");
        return;
    }

    QList<double> highPrices, lowPrices, closePrices;

    for (const QString& value : highList)
        highPrices.append(value.toDouble());
    for (const QString& value : lowList)
        lowPrices.append(value.toDouble());
    for (const QString& value : closeList)
        closePrices.append(value.toDouble());

    int period = ui->spinBoxPeriod->value();

    if (highPrices.size() != lowPrices.size() || highPrices.size() != closePrices.size()) {
        QMessageBox::warning(this, "Mismatched Data", "Ensure all price lists are the same length.");
        return;
    }

    double volatility = calculateAverageTrueRange(highPrices, lowPrices, closePrices, period);

    ui->lineEditVolatility->setText(QString::number(volatility, 'f', 2));
}
