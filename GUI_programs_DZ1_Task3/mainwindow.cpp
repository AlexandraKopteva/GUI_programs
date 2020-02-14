#include "mainwindow.h"
#include "ui_mainwindow.h"

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
//для добавления фиксированной строки, замены на готовый текст
//Из простого текста нужно переносить 2 способами:
//добавлeние строки и замена всего текста
//Add
void MainWindow::on_pushButton_clicked()
{
    QString strNew = ui->textEdit->toPlainText();
    QString str=ui->plainTextEdit->toPlainText();
    ui->textEdit->setHtml(strNew+"<br>"+str);
}
//Replace
void MainWindow::on_pushButton_2_clicked()
{
    QString str=ui->plainTextEdit->toPlainText();
    ui->textEdit->setHtml(str);
}
