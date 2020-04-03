#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"controller.h"
#include<QFileInfoList>
#include<QFileDialog>
#include <QTimer>
#include<QDir>
#include<QProcess>
#include<QtGlobal>
#include<QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_clicked();

    void on_plainTextEdit_textChanged();

    void updateListDisks();
    void printFindFile(QString);

private:

    Ui::MainWindow *ui;
    QStringList disksList;
    int disksLstSize;
    Controller *controller;
};
#endif // MAINWINDOW_H
