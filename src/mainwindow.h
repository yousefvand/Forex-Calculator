#pragma once

#include <QMainWindow>
#include <QActionGroup>

class BreakEvenCalculator;
class CompoundInterestCalculator;
class CurrencyConverter;
class FibonacciCalculator;
class LotSizeCalculator;
class MarginCalculator;
class PipCalculator;
class PositionSizeCalculator;
class ProfitAndLossCalculator;
class RiskManagementCalculator;
class RiskRewardCalculator;
class SwapCalculator;
class VolatilityCalculator;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void switchCalculator();  // Slot for switching calculators

    void on_aboutForexCalculator_triggered();

    void on_aboutQt_triggered();

private:
    Ui::MainWindow* ui;
    QActionGroup* calculatorGroup;  // Group for radio buttons

    BreakEvenCalculator* breakEvenCalculator;
    CompoundInterestCalculator* compoundInterestCalculator;
    CurrencyConverter* currencyConverter;
    FibonacciCalculator* fibonacciCalculator;
    LotSizeCalculator* lotSizeCalculator;
    MarginCalculator* marginCalculator;
    PipCalculator* pipCalculator;
    PositionSizeCalculator* positionSizeCalculator;
    ProfitAndLossCalculator* profitAndLossCalculator;
    RiskManagementCalculator* riskManagementCalculator;
    RiskRewardCalculator* riskRewardCalculator;
    SwapCalculator* swapCalculator;
    VolatilityCalculator* volatilityCalculator;
};

