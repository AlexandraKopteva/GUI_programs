#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //QWidget::setLayout();
    w.setStyleSheet("QMenu  {font: bold 14 px; background-color:#B0C4DE; }QMenuBar  {font: bold 14 px; background-color:#00BFFF;} QMainWindow{background-color:#4682B4;}");
    w.show();
    return a.exec();
}
