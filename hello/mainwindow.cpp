#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QLabel *label = new QLabel("Hello Qt Wor1d!", this);
    setStyleSheet("background-color: green; "
                  "color: white; "
                  "font-family: 'Microsoft Yahei';"
                  "font-size: 24px; ");
    label->setAlignment(Qt::AlignCenter);

    setCentralWidget(label);
}

MainWindow::~MainWindow()
{
    delete ui;
}
