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
int SquareEquality(double &a, double &b, double &c, double* x1, double* x2)
{
    double D,D_;
    D = b * b - 4. * a*c;
    D_= 4. * a*c-b*b;
    if (a == 0.0) {
        *x1 = -c / b;
        return 0;
    }
    else if (D > 0.0) {
        *x1 = (-b - sqrt(D)) / (2 * a);
        *x2 = (-b + sqrt(D)) /(2 * a);
        return 1;
    }
    else if (D == 0.0) {
        *x1 =*x2 =  (-b / (2 * a));
        return 0;
    }
    else if(D < 0.0) {
       // *x1 = (-b - i*sqrt(D_)) / (2 * a);
        //*x2 = (-b + i*sqrt(D_)) /(2 * a);
        return -1;
    }
}

void MainWindow::on_pushButton_clicked()
{
    double y1, y2;
    //считали текст в переменные
    QString a_value=ui->lineEdit->text();
    QString b_value=ui->lineEdit_2->text();
    QString c_value=ui->lineEdit_3->text();
    double a1=a_value.toDouble();
    double b1=b_value.toDouble();
    double c1=c_value.toDouble();
    QString str1,str2,strx1="x1=",strx2="x2=";
    int result;
    result = SquareEquality(a1, b1, c1, &y1, &y2);
    //вывод результата
    switch (result) {
        case 0:
        strx1=strx1.append(str1.number(y1));
        ui->lineEdit_4->setText(strx1);
            break;
        case 1:
        strx1=strx1.append(str1.number(y1));
        strx2=strx2.append(str2.number(y2));
        ui->lineEdit_4->setText(strx1+" and "+strx2);
            break;
        case -1:
           str1="Complex roots";
           ui->lineEdit_4->setText(str1);
            break;
        default:
            printf("Exceptional answer: %d", result);
        }
}
