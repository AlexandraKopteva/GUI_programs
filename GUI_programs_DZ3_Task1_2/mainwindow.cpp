#include "mainwindow.h"
#include "ui_mainwindow.h"

#include"linkfilter.h"
#include"contextmenu.h"
#include<QtCore>
/*
 *DZ_3
1.Написать программу "Текстовый редактор", используя виджет QTextEdit, с возможностью отмены изменений.
 Информацию об изменениях хранить в контейнере (например, в QStack).
 Постарайтейсь не использовать встроенные возможности виджета, а именно методы redo(), undo().
+2. Добавить в Текстовый редактор файл описания. Текстовый файл с описанием разместить в ресурсах программы.
Для вызова описания разместить на форме соответствующую кнопку (о программе).
+3. Добавить в Текстовый редактор возможность открывать текстовые файлы (с расширением .txt).
+4. Добавить в Текстовый редактор возможность сохранить содержимое текстового поля.
 Если оно сохраняется в бинарный файл, сохранять имя автора, разместив поле QLineEdit,
а если в тестовом виде - запись в этом поле игнорировать.
*/
/*
DZ_4
2. Создать  фильтр  в  текстовом  редакторе,  перехватывающий  вызовы  контекстного  меню.
Добавить режим «Открыть только для чтения», блокирующий любые правки.
*/

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // QObject::installEventFilter();
    //begin filter
    linkfilter* filterlink=new linkfilter(this);
    this->installEventFilter(filterlink);
    connect(filterlink, SIGNAL(linckClicked()), this, SLOT(linkCliced));
    //end filter
    str_filter =trUtf8("Текстовый файл (*.txt);;Двоичный файл(*.original)");
  }

  MainWindow::~MainWindow()
  {
      delete ui;
  }  

//Этот сигнал испускается всякий раз, когда изменяется текст.
void MainWindow::on_textEdit_textChanged()
{
    stack.push(ui->textEdit->toPlainText());
}

void MainWindow::on_action_triggered()
{
    ui->statusbar->showMessage("Открытие файла");
    QString s = QFileDialog::getOpenFileName(this, "Заголовок окна", QDir::current().path(), str_filter);
       if (s.length() > 0)
       {
           int index = s.indexOf(".txt");
           QFile file(s);
           if (file.open(QFile::ReadOnly | QFile::ExistingOnly))
           {
               if (index != -1 && s.length() - 4 == index)
               {
                   QTextStream stream(&file);
                   ui->textEdit->setPlainText(stream.readAll());
               }
               else
               {
                   QDataStream stream(&file);
                   QByteArray b = QString("BI").toUtf8();
                   char mH[15];
                   stream.readRawData(mH, b.length());
                   if (memcmp(mH, b.data(), b.length())) // если не совпадает заголовок, то открытие недопустимо
                   {
                       file.close();
                       return;
                   }
                   uint amount = 0;
                   stream.readRawData(reinterpret_cast<char*>(&amount), sizeof amount);
                   b.resize(amount);
                   stream.readRawData(b.data(), amount);
                   QString usedS = trUtf8(b.data());
                   QString str = "";
                   uint pos = 0;
                   uint mm = 1;
                   for (;!stream.atEnd();) { // atEnd() true конец файла
                       char ch;
                       stream.readRawData(&ch, 1);
                       bool bl = (ch & 0x80) ? false : true;
                       int rValue = (ch & 0x7F);
                       pos += mm * rValue;
                       mm *= 128;
                       if (bl)
                       {
                           mm = 1;
                           str += usedS.at(pos);
                           pos = 0;
                       }
                   }
                   ui->textEdit->setPlainText(str);
               }
           }
           file.seek(0);
           auto pp = file.readAll();
           file.close();
       }
}

void MainWindow::on_action_2_triggered()
{
    ui->statusbar->showMessage("Открытие файла только для чтения");
    ui->textEdit->setReadOnly(true);
    QString filename =QFileDialog::getOpenFileName(this, "Пример фильтра", QDir::currentPath(), "Text(*.txt)");
    if(filename.length()){
        QFile file (filename);
        if (file.open(QIODevice::ReadOnly)){
            QTextStream stream(&file);
            filename = stream.read(file.size());
            ui->textEdit->setText(filename);
        }
    } else {//Пользователь нажал кнопку "Отмена"
        ui->textEdit->setText("Вы нажали кнопку \"Отмена!\"");
    }

}

void MainWindow::on_action_3_triggered()
{
    QApplication::quit();
}

void MainWindow::on_action_4_triggered()
{
    QFile file (":/resources.rc");
    if (file.open(QIODevice::ReadOnly)){
        QTextStream stream(&file);
        QString str = stream.read(file.size());
        ui->textEdit->setText(str);
    }
}

void MainWindow::on_action_6_triggered()
{
    QString s = QFileDialog::getSaveFileName(this, "Заголовок окна", QDir::current().path(), str_filter);
       if (s.length() > 0) {
           int index = s.indexOf(".txt"); // определяем, есть ли в названии строка ".txt"
           QFile file(s);
           if (file.open(QFile::WriteOnly))
           {
               if (index != -1)  {         // если текстовый файл (выполняются 2 условия)
                   QTextStream stream(&file);
                   stream << ui->textEdit->toPlainText();
               } else {                      //бинарный файл
                   QDataStream stream(&file);
                   QByteArray b = QString("BI").toUtf8();
                   stream.writeRawData(b.data(), b.length());
                  //теперь посчитаем, сколько раз каждый символ встречается в тексте.
                   QHash<QChar, int>symbamount;
                   symbamount.clear();
                   QString str = ui->textEdit->toPlainText();
                   //считываем имя автора
                   QString QLineEditSTR=ui->lineEdit->text();
                   str=str+QLineEditSTR;
                   int amount = str.length();
                   QString usedS = "";
                   for (int i = 0; i < amount; ++i) {
                       QChar ch = str.at(i);
                       int index = usedS.indexOf(ch);
                       if (index == -1)
                       {
                           symbamount[ch] = 0;
                           usedS += ch;
                       }
                       else{
                          symbamount[ch]++;
                       }
                   }
                   //
                   for (int i = 0; i < amount; ++i) {
                       QChar chi = usedS[i];
                       for (int j = i + 1; j < amount; ++j) {
                       QChar chj = usedS[j];
                           if (symbamount[chi] < symbamount[chj])
                           {
                               usedS[i] = chj;
                               usedS[j] = chi;
                               chi = chj;
                           }
                       }
                   }
                   symbamount.clear();
                   b = usedS.toUtf8();
                   amount = b.length();
                   stream.writeRawData(reinterpret_cast<char*>(&amount), sizeof amount);
                   stream.writeRawData(b.data(), amount);
                   amount = str.length();
                   for (int i = 0; i < amount; i++) {
                       int index = usedS.indexOf(str.at(i));
                       for (bool w = true; w;) {
                           char wr = index % 128;
                           index /= 128;
                           if (index) {
                               wr |= 0x80;
                               stream.writeRawData(&wr, 1); // старший бит  сообщает, что значение состоит еще из 1 байта
                           }
                           else {
                               stream.writeRawData(&wr, 1);
                               w = false;
                           }
                       }
                   }
               }
               file.close();
           }
       }
}

void MainWindow::on_action_7_triggered()
{
    if (!stack.empty()){
        stack.pop();
        if (stack.empty())
        ui->textEdit->setText("");
        else
        ui->textEdit->setText(stack.pop());
    }
}
