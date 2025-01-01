#include "compoundinterestcalculator.h"
#include "ui_compoundinterestcalculator.h"
#include <QMessageBox>
#include <cmath>

CompoundInterestCalculator::CompoundInterestCalculator(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CompoundInterestCalculator)
{
    ui->setupUi(this);

    // Connect Calculate button to the calculation slot
    connect(ui->pushButtonCalculate, &QPushButton::clicked, this, &CompoundInterestCalculator::calculateCompoundInterest);
}

CompoundInterestCalculator::~CompoundInterestCalculator() {
    delete ui;
}

// Compound Interest Calculation Logic
void CompoundInterestCalculator::calculateCompoundInterest() {
    // Get values from the input fields
    double principal = ui->lineEditPrincipal->text().toDouble();
    double interestRate = ui->lineEditInterestRate->text().toDouble() / 100.0;  // Convert percentage to decimal
    int compoundFrequency = ui->lineEditCompoundFrequency->text().toInt();
    double timeYears = ui->lineEditTimeYears->text().toDouble();

    // Validation - Ensure no invalid or negative values
    if (principal <= 0 || interestRate <= 0 || compoundFrequency <= 0 || timeYears <= 0) {
        QMessageBox::warning(this, "Invalid Input", "All fields must have positive values.");
        return;
    }

    // Apply the compound interest formula
    double amount = principal * std::pow(1 + (interestRate / compoundFrequency), compoundFrequency * timeYears);

    // Display the calculated result (formatted to 2 decimal places)
    ui->lineEditFinalAmount->setText(QString::number(amount, 'f', 2));
}
