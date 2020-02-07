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
double Area(double &a, double &b, double *angle)
{
    double ar=sqrt(a*a+b*b-2*a*b*qCos(*angle));
    return ar;
}
double Radian(double &r)
{
    return r=((r*180)/M_PI);
}

void MainWindow::on_pushButton_clicked()
{
    QString side1=ui->lineEdit->text();
    QString side2=ui->lineEdit_2->text();
    QString angle=ui->lineEdit_3->text();
    double sideVal1=side1.toDouble();
    double sideVal2=side2.toDouble();
    double angleVal=angle.toDouble();
    if(ui->radioButton_2->isChecked())
    {
        angleVal=Radian(angleVal);
    }
    QString str;
    ui->lineEdit_4->setText(str.number(Area(sideVal1, sideVal2, &angleVal)));
}
