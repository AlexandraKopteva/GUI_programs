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
#include<QTextCursor>
#include<QtCore>
#include<QProgressBar>
#include<QPrinter>
#include<QPrintDialog>
#include<QPushButton>
#include<QFont>
#include<QFontDialog>
#include<QToolBar>
#include<QList>
#include<QTextTableFormat>

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
    void insertTable(int n, int m);

private slots:
    void on_textEdit_textChanged();

    void on_action_3_triggered();

    void on_action_4_triggered();

    void on_action_6_triggered();

    void on_action_7_triggered();

    void on_action_9_triggered();

    void on_action_10_triggered();

    void on_action_11_triggered();

    void on_action_triggered();

    void on_action_DayNight_triggered();
    void on_actionTextRight_triggered();

    void on_actionTextLeft_triggered();

    void on_actionTextCenter_triggered();

    void on_action_table_triggered();

    void on_action_Number_triggered();

    void on_action_date_2_triggered();

    void on_action_time_2_triggered();

private:
    void closeEvent(QCloseEvent* event) override;

    Ui::MainWindow *ui;
    QString str_filter;
    QStack<QString> stack;
    QList<QString> list;
    QTextEdit* curEdit;
    QPushButton* changeTable;
    bool DayNight = false;
};
#endif // MAINWINDOW_H

