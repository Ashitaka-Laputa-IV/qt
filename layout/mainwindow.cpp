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

    layout->addWidget(new QLabel("Lable", central));
    layout->addWidget(new QPushButton("ButtonA", central));
    layout->addWidget(new QPushButton("ButtonB", central));

    layout->setAlignment(Qt::AlignCenter);

    setCentralWidget(central);

    setWindowTitle("Layout");
}

MainWindow::~MainWindow()
{
    delete ui;
}
