#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pipcalculator.h"
#include "margincalculator.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create action group for calculator radio buttons
    calculatorGroup = new QActionGroup(this);
    calculatorGroup->addAction(ui->actionPip_calculator);
    calculatorGroup->addAction(ui->actionMargin_calculator);

    // Make the actions checkable (radio behavior)
    for (QAction *action : calculatorGroup->actions()) {
        action->setCheckable(true);
    }
    ui->actionPip_calculator->setChecked(true);  // Default selection

    // Connect each action to slot
    connect(calculatorGroup, &QActionGroup::triggered, this, &MainWindow::switchCalculator);

    // Show Pip Calculator by default
    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow() {
    delete ui;
}

// Slot to switch calculator based on action
void MainWindow::switchCalculator() {
    if (ui->actionPip_calculator->isChecked()) {
        ui->stackedWidget->setCurrentIndex(0);  // Show PipCalculator page
    } else if (ui->actionMargin_calculator->isChecked()) {
        ui->stackedWidget->setCurrentIndex(1);  // Show MarginCalculator page
    }
}
