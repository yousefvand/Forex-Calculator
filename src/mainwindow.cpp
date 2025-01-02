#include "utils.h"
#include "about.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "breakevencalculator.h"
#include "compoundinterestcalculator.h"
#include "currencyconverter.h"
#include "fibonaccicalculator.h"
#include "lotsizecalculator.h"
#include "margincalculator.h"
#include "pipcalculator.h"
#include "positionsizecalculator.h"
#include "profitandlosscalculator.h"
#include "riskmanagementcalculator.h"
#include "riskrewardcalculator.h"
#include "swapcalculator.h"
#include "volatilitycalculator.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(this->size());

    breakEvenCalculator = new BreakEvenCalculator(this);
    compoundInterestCalculator = new CompoundInterestCalculator(this);
    currencyConverter = new CurrencyConverter(this);
    fibonacciCalculator = new FibonacciCalculator(this);
    lotSizeCalculator = new LotSizeCalculator(this);
    marginCalculator = new MarginCalculator(this);
    pipCalculator = new PipCalculator(this);
    positionSizeCalculator = new PositionSizeCalculator(this);
    profitAndLossCalculator = new ProfitAndLossCalculator(this);
    riskManagementCalculator = new RiskManagementCalculator(this);
    riskRewardCalculator = new RiskRewardCalculator(this);
    swapCalculator = new SwapCalculator(this);
    volatilityCalculator = new VolatilityCalculator(this);

    ui->stackedWidget->removeWidget(ui->stackedWidget->widget(0));
    ui->stackedWidget->removeWidget(ui->stackedWidget->widget(0));

    ui->stackedWidget->addWidget(breakEvenCalculator);          // Index 0
    ui->stackedWidget->addWidget(compoundInterestCalculator);   // Index 1
    ui->stackedWidget->addWidget(currencyConverter);            // Index 2
    ui->stackedWidget->addWidget(fibonacciCalculator);          // Index 3
    ui->stackedWidget->addWidget(lotSizeCalculator);            // Index 4
    ui->stackedWidget->addWidget(marginCalculator);             // Index 5
    ui->stackedWidget->addWidget(pipCalculator);                // Index 6
    ui->stackedWidget->addWidget(positionSizeCalculator);       // Index 7
    ui->stackedWidget->addWidget(profitAndLossCalculator);      // Index 8
    ui->stackedWidget->addWidget(riskManagementCalculator);     // Index 9
    ui->stackedWidget->addWidget(riskRewardCalculator);         // Index 10
    ui->stackedWidget->addWidget(swapCalculator);               // Index 11
    ui->stackedWidget->addWidget(volatilityCalculator);         // Index 12

    // Create action group for calculator radio buttons
    calculatorGroup = new QActionGroup(this);
    calculatorGroup->addAction(ui->actionBreak_Even_Calculator);
    calculatorGroup->addAction(ui->actionCompound_Interest_Calculator);
    calculatorGroup->addAction(ui->actionCurrency_Converter);
    calculatorGroup->addAction(ui->actionFibonacci_Calculator);
    calculatorGroup->addAction(ui->actionLot_Size_Calculator);
    calculatorGroup->addAction(ui->actionMargin_calculator);
    calculatorGroup->addAction(ui->actionPip_calculator);
    calculatorGroup->addAction(ui->actionPosition_Size_Calculator);
    calculatorGroup->addAction(ui->actionProfit_and_Loss_Calculator);
    calculatorGroup->addAction(ui->actionRisk_Management_Calculator);
    calculatorGroup->addAction(ui->actionRisk_Reward_Calculator);
    calculatorGroup->addAction(ui->actionSwap_Calculator);
    calculatorGroup->addAction(ui->actionVolatility_Calculator);

    for (QAction *action : calculatorGroup->actions()) {
        action->setCheckable(true);
    }

    // Connect each action to slot
    connect(calculatorGroup, &QActionGroup::triggered, this, &MainWindow::switchCalculator);

    for (QAction *action : calculatorGroup->actions()) {
        action->setChecked(false);
    }

    QString calculator = Settings::instance()->loadSetting("Calculator", "LastUsed", "BreakEvenCalculator").toString();
    if (calculator == "BreakEvenCalculator") {
        ui->actionBreak_Even_Calculator->setChecked(true);
    }
    if (calculator == "CompoundInterestCalculator") {
        ui->actionCompound_Interest_Calculator->setChecked(true);
    }
    if (calculator == "CurrencyConverter") {
        ui->actionCurrency_Converter->setChecked(true);
    }
    if (calculator == "FibonacciCalculator") {
        ui->actionFibonacci_Calculator->setChecked(true);
    }
    if (calculator == "LotSizeCalculator") {
        ui->actionLot_Size_Calculator->setChecked(true);
    }
    if (calculator == "MarginCalculator") {
        ui->actionMargin_calculator->setChecked(true);
    }
    if (calculator == "PipCalculator") {
        ui->actionPip_calculator->setChecked(true);
    }
    if (calculator == "PositionSizeCalculator") {
        ui->actionPosition_Size_Calculator->setChecked(true);
    }
    if (calculator == "ProfitAndLossCalculator") {
        ui->actionProfit_and_Loss_Calculator->setChecked(true);
    }
    if (calculator == "RiskManagementCalculator") {
        ui->actionRisk_Management_Calculator->setChecked(true);
    }
    if (calculator == "RiskRewardCalculator") {
        ui->actionRisk_Reward_Calculator->setChecked(true);
    }
    if (calculator == "SwapCalculator") {
        ui->actionSwap_Calculator->setChecked(true);
    }
    if (calculator == "VolatilityCalculator") {
        ui->actionVolatility_Calculator->setChecked(true);
    }

    switchCalculator();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::switchCalculator() {
    if (ui->actionBreak_Even_Calculator->isChecked()) {
        ui->stackedWidget->setCurrentIndex(0);
        this->setWindowTitle("Break Even Calculator");
        Settings::instance()->saveSetting("Calculator", "LastUsed", "BreakEvenCalculator");
    } else if (ui->actionCompound_Interest_Calculator->isChecked()) {
        ui->stackedWidget->setCurrentIndex(1);
        this->setWindowTitle("Compound Interest Calculator");
        Settings::instance()->saveSetting("Calculator", "LastUsed", "CompoundInterestCalculator");
    } else if (ui->actionCurrency_Converter->isChecked()) {
        ui->stackedWidget->setCurrentIndex(2);
        this->setWindowTitle("Currency Converter");
        Settings::instance()->saveSetting("Calculator", "LastUsed", "CurrencyConverter");
    } else if (ui->actionFibonacci_Calculator->isChecked()) {
        ui->stackedWidget->setCurrentIndex(3);
        this->setWindowTitle("Fibonacci Calculator");
        Settings::instance()->saveSetting("Calculator", "LastUsed", "FibonacciCalculator");
    } else if (ui->actionLot_Size_Calculator->isChecked()) {
        ui->stackedWidget->setCurrentIndex(4);
        this->setWindowTitle("Lot Size Calculator");
        Settings::instance()->saveSetting("Calculator", "LastUsed", "LotSizeCalculator");
    } else if (ui->actionMargin_calculator->isChecked()) {
        ui->stackedWidget->setCurrentIndex(5);
        this->setWindowTitle("Margin Calculator");
        Settings::instance()->saveSetting("Calculator", "LastUsed", "MarginCalculator");
    } else if (ui->actionPip_calculator->isChecked()) {
        ui->stackedWidget->setCurrentIndex(6);
        this->setWindowTitle("Pip Calculator");
        Settings::instance()->saveSetting("Calculator", "LastUsed", "PipCalculator");
    } else if (ui->actionPosition_Size_Calculator->isChecked()) {
        ui->stackedWidget->setCurrentIndex(7);
        this->setWindowTitle("Position Size Calculator");
        Settings::instance()->saveSetting("Calculator", "LastUsed", "PositionSizeCalculator");
    } else if (ui->actionProfit_and_Loss_Calculator->isChecked()) {
        ui->stackedWidget->setCurrentIndex(8);
        this->setWindowTitle("Profit and Loss Calculator");
        Settings::instance()->saveSetting("Calculator", "LastUsed", "ProfitAndLossCalculator");
    } else if (ui->actionRisk_Management_Calculator->isChecked()) {
        ui->stackedWidget->setCurrentIndex(9);
        this->setWindowTitle("Risk Management Calculator");
        Settings::instance()->saveSetting("Calculator", "LastUsed", "RiskManagementCalculator");
    } else if (ui->actionRisk_Reward_Calculator->isChecked()) {
        ui->stackedWidget->setCurrentIndex(10);
        this->setWindowTitle("Risk Reward Calculator");
        Settings::instance()->saveSetting("Calculator", "LastUsed", "RiskRewardCalculator");
    } else if (ui->actionSwap_Calculator->isChecked()) {
        ui->stackedWidget->setCurrentIndex(11);
        this->setWindowTitle("Swap Calculator");
        Settings::instance()->saveSetting("Calculator", "LastUsed", "SwapCalculator");
    } else if (ui->actionVolatility_Calculator->isChecked()) {
        ui->stackedWidget->setCurrentIndex(12);
        this->setWindowTitle("Volatility Calculator");
        Settings::instance()->saveSetting("Calculator", "LastUsed", "VolatilityCalculator");
    }
}

void MainWindow::on_aboutForexCalculator_triggered()
{
    About dialog(this);
    dialog.exec();
}

void MainWindow::on_aboutQt_triggered()
{
    QMessageBox::aboutQt(this, tr("About Qt"));
}

