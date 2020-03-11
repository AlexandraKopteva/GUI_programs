#include "mainwindow.h"
#include "ui_mainwindow.h"

/*
2. В просмотрщик файлов добавить таймер, который будет проверять изменение списка дисков.
Если  список  дисков  изменился,  нужно  запустить  поток,  который  будет  искать  файл
конфигурации (произвольного формата, можно использовать autorun.inf), содержащий путь к
приложению  для  запуска.  Для  проверки  подключить  флеш-карту  к  ПК:  при  срабатывании
таймера поток должен искать файл конфигурации на ней.
*/

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *pTime = new QTimer(this);
    controller = new Controller(this);
    connect(pTime, SIGNAL(timeout()), this, SLOT(updateListDisks()));
    pTime->start(5000);

    QFileInfoList fileInf = QDir::drives();
    for (auto disk : fileInf)
    {
        disksList.append(disk.absolutePath());
    }
    disksLstSize = disksList.size()-1;
    connect(controller, SIGNAL(changFindPath(QString)), this, SLOT(changStatusLabel(QString)));
    connect(controller, SIGNAL(genPathOfFile(QString)), this, SLOT(printFindFile(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::updateListDisks()
{
    QFileInfoList fileInf = QDir::drives();
    bool isFound = false;
    if (disksLstSize < fileInf.size()-1)
    {
        for (auto disk : fileInf)
        {
            isFound = false;
            for (auto oldDisk : disksList)
                if (disk == oldDisk)
                    isFound = true;
            if (!isFound)
            {
                controller->startFind(disk.absolutePath(), "autorun.inf");
                disksList.append(disk.absolutePath());
            }
        }
        disksLstSize = disksList.size()-1;
    }
    else if (disksLstSize > fileInf.size()-1)
    {
        for (auto disk : fileInf)
        {
            disksList.clear();
            disksList.append(disk.absolutePath());
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    QFileDialog dialog;
    QString path;
    dialog.setFileMode(QFileDialog::Directory);
    if(dialog.exec()) {
            path = dialog.getExistingDirectory();
            ui->plainTextEdit->setPlainText(path);
            QDir dir(path);
            dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks | QDir::Dirs);
            QFileInfoList list = dir.entryInfoList();
            QString result = "";
            for (QFileInfoList::iterator iter = list.begin(),
                 end = list.end(); iter < end; iter++)
            {
                result += (*iter).fileName() + "\n";
            }
            ui->plainTextEdit_2->setPlainText(result);
        }
}

void MainWindow::on_plainTextEdit_textChanged()
{
    QDir dir = (ui->plainTextEdit->toPlainText());
    QFileInfoList list = dir.entryInfoList();
    QString result = "";
    for (QFileInfoList::iterator iter = list.begin(),
         end = list.end(); iter < end; iter++)
    {
        result += (*iter).fileName() + "\n";
    }
    ui->plainTextEdit_2->setPlainText(result);
}

void MainWindow::printFindFile(QString str)
{
    qDebug() << str;
    QFile file(str);
    if (file.open(QIODevice::ReadOnly))
    {
        QProcess *p = new QProcess(this);
        QByteArray byteArray = file.readAll();
        QString cmd = tr(byteArray.data());
        p->start(cmd);
        file.close();
    }
}
