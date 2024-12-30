#pragma once

#include <QMainWindow>
#include <QActionGroup>

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

private:
    Ui::MainWindow *ui;
    QActionGroup *calculatorGroup;  // Group for radio buttons
};

