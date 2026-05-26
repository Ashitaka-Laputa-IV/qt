#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWidget *central = new QWidget(this);

    QVBoxLayout *layout = new QVBoxLayout(central);

    auto label = new QLabel("Lable", central);
    label->setAlignment(Qt::AlignCenter);

    auto btn_a = new QPushButton("ButtonA", central);
    auto btn_b = new QPushButton("ButtonB", central);

    layout->addWidget(label);
    layout->addWidget(btn_a);
    layout->addWidget(btn_b);

    layout->setAlignment(Qt::AlignCenter);

    setCentralWidget(central);

    setWindowTitle("Layout");
}

MainWindow::~MainWindow()
{
    delete ui;
}
