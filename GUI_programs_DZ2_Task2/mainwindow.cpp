#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //
    model = new QStandardItemModel(this);
    ui->listView->setModel(model);

    model->appendRow(new QStandardItem(QIcon(":/icon_c++.png"),"C++"));
    model->appendRow(new QStandardItem(QIcon(":/icon_c.png"),"C#"));
    model->appendRow(new QStandardItem(QIcon(":/icon_java.png"),"Java"));
    model->appendRow(new QStandardItem(QIcon(":/icon_js.png"),"JavaScript"));
    model->appendRow(new QStandardItem(QIcon(":/icon_php.png"),"PHP"));
    model->appendRow(new QStandardItem(QIcon(":/icon_python.png"),"Python"));

    //Это свойство указывает, разрешен ли для этого виджета просмотр событий.
    ui->listView->setAcceptDrops(true);
    //Это свойство определяет, поддерживает ли представление перетаскивание его собственных элементов.
    ui->listView->setDragEnabled(true);
    //Это свойство содержит действие удаления, которое будет использоваться по умолчанию в QAbstractItemView :: drag ().
    ui->listView->setDefaultDropAction(Qt::MoveAction);
    /*
     Это свойство содержит режим просмотра QListView.
     Это свойство изменит другие неустановленные свойства
     в соответствии с установленным режимом просмотра.
 Специфичные для QListView свойства, которые уже были установлены,
не будут изменены, если не была вызвана clearPropertyFlags ().
Установка режима просмотра включит или отключит перетаскивание
в зависимости от выбранного движения. Для ListMode стандартным
 движением является Static (перетаскивание отключено);
для IconMode стандартным движением является Free (перетаскивание включено).
    */
    if (ui->checkBox->isChecked())
        ui->listView->setViewMode(QListView::IconMode);
    else
        ui->listView->setViewMode(QListView::ListMode);
     /*
    for(int i=0; i<str.size(); i++)
    {
    item->setText(list[i]);
    item->setIcon(QPixmap(str[i]));
    model->setItem(i,item);
    }
    //С++, Python, Java, C#, PHP, JavaScript
    */
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked()
{
 model->appendRow(new QStandardItem(QIcon(":/icon_.png"), "Новый элемент"));
}
void MainWindow::on_pushButton_2_clicked()
{
    QModelIndexList indexes = ui->listView->selectionModel()->selectedRows();
       while (!indexes.isEmpty())
       {
           model->removeRows(indexes.last().row(), 1);
           indexes.removeLast();
       }
}
void MainWindow::on_checkBox_clicked()
{
    if (ui->checkBox->isChecked())
        ui->listView->setViewMode(QListView::IconMode);
    else
        ui->listView->setViewMode(QListView::ListMode);
    ui->listView->setAcceptDrops(true);
    ui->listView->setDragEnabled(true);
    ui->listView->setDefaultDropAction(Qt::MoveAction);
}
