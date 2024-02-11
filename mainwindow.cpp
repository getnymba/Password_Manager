#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QObject>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int count = 1;

        // todo: database row count show here
    //QObject::connect(ui->updateButton, &QPushButton::clicked, this, &MainWindow::updatePasswordCount);
    ui->PasswordCount->display(count);

        //todo: build check security funciton
    ui->SecureLevel->setValue(80);
}
MainWindow::~MainWindow()
{
    delete ui;
}
