#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto label = new QLabel(QString::number(i), this);
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("font-size: 21px;");

    auto btn = new QPushButton("Click", this);

    auto layout = new QVBoxLayout;
    layout->addWidget(label);
    layout->addWidget(btn);

    auto central = new QWidget(this);
    central->setLayout(layout);
    setCentralWidget(central);

    connect(btn, &QPushButton::clicked, this, [this, label] { label->setText(QString::number(++(this->i))); });
}

MainWindow::~MainWindow()
{
    delete ui;
}
