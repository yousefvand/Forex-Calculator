#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::About)
{
    ui->setupUi(this);

    this->setFixedSize(this->size());

    connect(ui->closeButton, &QPushButton::clicked, this, &QDialog::accept);
}

About::~About()
{
    delete ui;
}
