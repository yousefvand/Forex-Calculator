#include "fibonaccicalculator.h"
#include "ui_fibonaccicalculator.h"
#include <QMessageBox>

FibonacciCalculator::FibonacciCalculator(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FibonacciCalculator)
{
    ui->setupUi(this);

    // Populate mode combo box
    ui->comboBoxMode->addItem("Full Sequence");
    ui->comboBoxMode->addItem("Nth Fibonacci Number");

    // Connect Calculate button to slot
    connect(ui->pushButtonCalculate, &QPushButton::clicked, this, &FibonacciCalculator::calculateFibonacci);
}

FibonacciCalculator::~FibonacciCalculator() {
    delete ui;
}

// Calculate Fibonacci Logic
void FibonacciCalculator::calculateFibonacci() {
    int n = ui->lineEditNthTerm->text().toInt();

    if (n <= 0) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a positive integer for N.");
        return;
    }

    QString result;
    if (ui->comboBoxMode->currentText() == "Full Sequence") {
        QVector<quint64> sequence = generateFibonacciSequence(n);
        for (int i = 0; i < sequence.size(); ++i) {
            result += formatWithCommas(sequence[i]) + ", ";
        }
        result.chop(2);  // Remove trailing comma and space
    } else {
        quint64 nthFibonacci = calculateNthFibonacci(n);
        result = QString("Fibonacci number at position %1 is %2").arg(n).arg(formatWithCommas(nthFibonacci));
    }

    ui->textEditResult->setText(result);
}

// Generate Fibonacci Sequence (up to nth term)
QVector<quint64> FibonacciCalculator::generateFibonacciSequence(int n) {
    QVector<quint64> sequence;
    sequence.append(0);
    if (n > 1) sequence.append(1);

    for (int i = 2; i < n; ++i) {
        quint64 next = sequence[i - 1] + sequence[i - 2];
        sequence.append(next);
    }

    return sequence;
}

// Calculate the Nth Fibonacci Number (iterative)
quint64 FibonacciCalculator::calculateNthFibonacci(int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;

    quint64 a = 0, b = 1, next = 0;
    for (int i = 3; i <= n; ++i) {
        next = a + b;
        a = b;
        b = next;
    }
    return b;
}

// Format Number with Commas (for readability)
QString FibonacciCalculator::formatWithCommas(quint64 number) {
    QString numStr = QString::number(number);
    int pos = numStr.length() - 3;
    while (pos > 0) {
        numStr.insert(pos, ',');
        pos -= 3;
    }
    return numStr;
}
