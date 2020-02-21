#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(350, 380);
    //w.setStyleSheet("QMenu  {font: bold 14 px; background-color:#B0C4DE; }QMenuBar  {font: bold 14 px; background-color:#00BFFF;} QMainWindow{background-color:#4682B4;}");
    w.setStyleSheet("QMenu  {font: bold 14 px; background-color:#778899; }QMenuBar  {font: bold 14 px; background-color:#808080;} QMainWindow{background-color:#DCDCDC;}");
    w.show();
    return a.exec();
}
