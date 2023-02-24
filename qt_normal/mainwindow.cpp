#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QGridLayout>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auto l = new QLabel(this);
    l->setText(QString::fromLocal8Bit("你好"));
    this->setCentralWidget(l);
}

MainWindow::~MainWindow()
{
    delete ui;
}
