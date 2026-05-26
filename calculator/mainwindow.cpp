#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto inputA = new QLineEdit(this);
    auto inputB = new QLineEdit(this);
    auto labelPlus = new QLabel("+", this);
    auto btnCalc = new QPushButton("=", this);
    auto labelRes = new QLabel("Res", this);

    inputA->setPlaceholderText("num1");
    inputB->setPlaceholderText("num2");

    labelRes->setStyleSheet("font-size: 20px");
    labelRes->setAlignment(Qt::AlignCenter);

    auto layoutTop = new QHBoxLayout;
    layoutTop->addWidget(inputA);
    layoutTop->addWidget(labelPlus);
    layoutTop->addWidget(inputB);
    layoutTop->addWidget(btnCalc);
    layoutTop->addWidget(labelRes);

    auto central = new QWidget(this);
    central->setLayout(layoutTop);
    setCentralWidget(central);

    connect(btnCalc,
            &QPushButton::clicked,
            this,
            [inputA, inputB, labelRes] () {
                bool ok1, ok2;
                auto num1 = inputA->text().toInt(&ok1);
                auto num2 = inputB->text().toInt(&ok2);
                if (ok1 && ok2) {
                    int sum = num1 + num2;
                    labelRes->setText(QString::number(sum));
                }
                else {
                    labelRes->setText("Error Input");
                }
            });
}

MainWindow::~MainWindow()
{
    delete ui;
}
