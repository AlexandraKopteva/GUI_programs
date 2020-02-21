#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<iostream>
#include <QMainWindow>
#include<QStack>
#include<QFile>
#include<QTextStream>
#include<QFileDialog>
#include<QFileSystemModel>
#include<QInputDialog>
#include<QMessageBox>
#include<QTextEdit>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void open();

public slots:

private slots:

    void on_textEdit_textChanged();

    void on_action_3_triggered();

    void on_action_4_triggered();

    void on_action_6_triggered();

    void on_action_7_triggered();

    void on_action_9_triggered();

    void on_action_10_triggered();

    void on_action_11_triggered();

private:
    Ui::MainWindow *ui;
    QString str_filter;
    QStack<QString> stack;
    QTextEdit* curEdit;
    QPushButton* changeTable;
};
#endif // MAINWINDOW_H

