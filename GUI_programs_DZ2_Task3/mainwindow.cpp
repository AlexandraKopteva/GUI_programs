#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QStandardItemModel(this);
    ui->tableView->setModel(model);

    QList<QStandardItem*>list;
    list.append(new QStandardItem("№"));
    list.append(new QStandardItem("Имя компьютера"));
    list.append(new QStandardItem("IP адрес"));
    list.append(new QStandardItem("MAC адрес"));
    model->appendRow(list);
    QList<QStandardItem*>list1;
    list1.append(new QStandardItem("1"));
    list1.append(new QStandardItem("User_1"));
    list1.append(new QStandardItem("192.168.1.1"));
    list1.append(new QStandardItem("00-aa-00-76-c8-09"));
    model->appendRow(list1);
    QList<QStandardItem*>list2;
    list2.append(new QStandardItem("2"));
    list2.append(new QStandardItem("User_2"));
    list2.append(new QStandardItem("192.168.1.2"));
    list2.append(new QStandardItem("00-aa-00-64-c8-09"));
    model->appendRow(list2);
    QList<QStandardItem*>list3;
    list3.append(new QStandardItem("3"));
    list3.append(new QStandardItem("User_3"));
    list3.append(new QStandardItem("192.168.1.3"));
    list3.append(new QStandardItem("00-tr-00-64-c8-04"));
    model->appendRow(list3);
    QList<QStandardItem*>list4;
    list4.append(new QStandardItem("4"));
    list4.append(new QStandardItem("User_4"));
    list4.append(new QStandardItem("192.168.1.4"));
    list4.append(new QStandardItem("00-av-00-52-c5-03"));
    model->appendRow(list4);

    //QItemSelectionModel *selectionModel = ui->tableView->selectionModel();
    //
    QVariant test;
    QBrush brush = test.value<QBrush>(); //преобразование
    model->setData(model->index(0,0), QBrush(brush), Qt::BackgroundRole); //покраска

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->tableView->setStyleSheet(
                        "QTableView::item:selected:active {"
                        "background: rgb(140, 233, 248);"
                        "selection-color: #606;"
                        "}"
                        "QTableView::item:selected:!active {"
                        "background: rgb(11,230,11);"
                        "border: 1px solid transparent;"
                        "selection-color: #606;"
                        "}"
                        );
}
