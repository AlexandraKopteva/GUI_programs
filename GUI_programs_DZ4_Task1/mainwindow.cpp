#include "mainwindow.h"
#include "ui_mainwindow.h"

/*
1. Создать  программу,  в  которой  будет  поле  ввода.
После  ввода  строки  и  нажатия  клавиши  Enter, строка переносится в заголовок окна.
*/

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_editingFinished()
{
    QString title = ui->lineEdit->text();
     this->setWindowTitle(title);
}
