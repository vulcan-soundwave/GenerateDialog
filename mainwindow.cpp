#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    CDialog *dialog = new CDialog();
    dialog->exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}
