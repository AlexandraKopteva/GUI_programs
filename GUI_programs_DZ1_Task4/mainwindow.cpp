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

/*
. Получите QTextDocument из виджета QTextEdit
(метод document). С помощью списка методов и
переменных выберите, какие наиболее интересны
 для редактирования текста. Ознакомьтесь с работой
 подсказчика кода Qt Creator (Ctrl+Space).
*/
void MainWindow::on_pushButton_clicked()
{
   QTextEdit *editor = new QTextEdit;
   QTextDocument *doc=ui->textEdit->document();
   QString str=ui->textEdit->toPlainText();
   if(ui->pushButton)
   {
       ui->textEdit->clear();
   }
}

void MainWindow::on_pushButton_4_clicked()
{
    if(ui->pushButton_4)
    {
        ui->textEdit->selectAll();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if(ui->pushButton_2)
       {
           ui->textEdit->copy();
       }
}

void MainWindow::on_pushButton_3_clicked()
{
    if(ui->pushButton_3)
       {
           ui->textEdit->cut();
       }
}

void MainWindow::on_pushButton_6_clicked()
{
    if(ui->pushButton_6)
       {
           ui->textEdit->paste();
       }
}
