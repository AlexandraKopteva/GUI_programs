#include "mainwindow.h"
#include "ui_mainwindow.h"

#include"linkfilter.h"
#include"contextmenu.h"
#include"mytable.h"
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

/*
 *DZ_3
+1.Написать программу "Текстовый редактор", используя виджет QTextEdit, с возможностью отмены изменений.
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
DZ_5
+1. Добавить  в текстовый редактор выбор из нескольких таблиц стилей.
DZ_6
+1. Добавить меню в текстовый редактор.
+2. Добавить  в  текстовый  редактор  печать,  класс  печати.
Учтите,  что  строка  может  не  помещаться по ширине страницы.
Реализовать разбиение текста на дополнительные строки.
+-3. Новая  строка  должна  разделяться  горизонтальной  линией  (тег <hr>).
Добавить  опцию  нумерации абзацев. +Добавить возможность вставки таблиц.
-4. * Добавить в текстовый редактор поддержку многодокументного интерфейса.
DZ_7
1. В проект "Текстовый редактор" (можно взять из предыдущих ДЗ) добавить:
-a. возможность копировать формат фрагмента текста и применять к другому фрагменту.
+b. возможность выравнивания текста по правому и левому краю, а также по центру.
+c. возможность выбора шрифта
//Сделать
1. применить компоновщика, чтобы виджеты растягивались вместе с самим окном.
2. mdiArea, по идее необходимо было создать пользовательский виджет
 - текстовый редактор и уже экземпляры этих виджетов добавлять в mdiArea.
Под словами создать пользоватльский виджет я имею ввиду взять ваш готовый
тектовый редактор и поместить его в отдельный класс унаследованный от QWidget.
*/

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);    
    //
    linkfilter* filterlink=new linkfilter(this);
    this->installEventFilter(filterlink);
    connect(filterlink, SIGNAL(linckClicked()), this, SLOT(linkCliced));
    str_filter =trUtf8("Текстовый файл (*.txt);;Двоичный файл(*.original)");
    //
    //Меню   QStatusBar
    QStatusBar *statusBar=this->statusBar();
    statusBar->addWidget(new QLabel("Text 1",this));
    statusBar->addWidget(new QLabel("Text 2",this));
    statusBar->addWidget(new QProgressBar(this));

    /*
    QAction* newAct=new QAction(this);
    QToolBar* fileToolBar=new QToolBar(this);
    fileToolBar = addToolBar("File");
    fileToolBar->addAction(newAct);
    //многодокументный интерфейс
    mdiArea =new QMdiArea(this);
    QWidget* centralW=new QWidget(this);
    setCentralWidget(centralW);
    QGridLayout* lay= new QGridLayout(this);
    centralW->setLayout(lay);
    lay->addWidget(mdiArea, 1,0,10,10);
    mdiArea->addSubWindow(new QTextEdit(this));
    //
    QDockWidget *dockWidget = new QDockWidget(("Dock Widget"), this);
    dockWidget->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    dockWidget->setWidget(mdiArea);
    addDockWidget(Qt::LeftDockWidgetArea, dockWidget);
    */
  }

MainWindow::~MainWindow()
{
    delete ui;
}
//Этот сигнал испускается всякий раз, когда изменяется текст.
void MainWindow::on_textEdit_textChanged()
{
    stack.push(ui->textEdit->toPlainText());
    //list.push_back(ui->textEdit->toPlainText());
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

void MainWindow::on_action_9_triggered()
{
    QTextEdit* txt=new QTextEdit(this);
    QPrinter printer;
    QPrintDialog dlg(&printer, this);
    dlg.setWindowTitle("Print");
    if (dlg.exec() != QDialog::Accepted) return;
    curEdit->print(&printer);
}

void MainWindow::on_action_10_triggered()
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

void MainWindow::on_action_11_triggered()
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

void MainWindow::on_action_triggered()
{
    QFont font = ui->textEdit->textCursor().charFormat().font(); // получаем текущий шрифт
    QFontDialog fntDlg(font,this);
    bool b[] = {true};
    font = fntDlg.getFont(b); // Запускаем диалог настройки шрифта
    if (b[0])                 // Если нажата кнопка OK, применяем новые настройки шрифта
    {
        QTextCharFormat fmt;
        fmt.setFont(font);
        ui->textEdit->textCursor().setCharFormat(fmt);
    }
}

void MainWindow::on_action_DayNight_triggered()
{
    if (DayNight) {
        setStyleSheet("QMenu  {font: bold 14 px; background-color:#B0C4DE; }QMenuBar  {font: bold 14 px; background-color:#00BFFF;} QMainWindow{background-color:#4682B4;}");
        DayNight = false;
    } else {
        setStyleSheet("QMenu  {font: bold 14 px; background-color:#98FB98; }QMenuBar  {font: bold 14 px; background-color:#3CB371;} QMainWindow{background-color:#2E8B71;}");
        DayNight = true;
    }
}
void   MainWindow::closeEvent(QCloseEvent* event)
{
    QMessageBox msgBox(this);
    msgBox.setText(tr("Вы уверены, что хотите закрыть программу?"));
    msgBox.setIcon(QMessageBox::Question);
    msgBox.addButton(tr("Да"), QMessageBox::YesRole);       // Добавлен 1-м - вернётся 0
    msgBox.addButton(tr("Нет"), QMessageBox::NoRole);       // Добавлен 2-м - 1
    msgBox.addButton(tr("Отмена"), QMessageBox::RejectRole);// Добавлен 3-м - 2
    int result = msgBox.exec();  // Значение r зависит от порядка добавления кнопок
    if(result==0)
    {
        event->accept();
    }else{
        event->ignore();
    }
}

void MainWindow::on_actionTextRight_triggered()
{
    //реализация с HTML
    QStringList list1;
    list1.clear();
    QList<QString>::iterator iter1;
    QString str= ui->textEdit->document()->toPlainText();
    list1 = str.split("\n");
    QString str1="<p align=\"right\">", str2="<\\p>";

    if (!list1.isEmpty()){
        for (iter1 = list1.begin(); iter1 != list1.end(); ++iter1)
        {
            *iter1=str1+(*iter1)+str2;
        }
    }
    str.clear();
    if (!list1.isEmpty()){
        for (iter1 = list1.begin(); iter1 != list1.end(); ++iter1)
        {
            str=str+(*iter1);
        }
        ui->textEdit->document()->setHtml(str);
    }
    //встроенный механизм))
    /*
     QTestCursor cursor = ui->textEdit->textCursor();
     QTextBlockFormat textBlockFormat =cursor.blockFormat();
     textBlockFormat.setAlignment(Qt::AlignRight);
     cursor.mergeBlockFormat(textBlockFormat);
     ui->textEdit->setTextCursor(cursor);
     */
}
void MainWindow::on_actionTextLeft_triggered()
{
    QStringList list1;
    list1.clear();
    QList<QString>::iterator iter1;
    QString str= ui->textEdit->document()->toPlainText();
    list1 = str.split("\n");
    QString str1="<p align=\"left\">", str2="<\\p>";

    if (!list1.isEmpty()){
        for (iter1 = list1.begin(); iter1 != list1.end(); ++iter1)
        {
            *iter1=str1+(*iter1)+str2;
        }
    }
    str.clear();
    if (!list1.isEmpty()){
        for (iter1 = list1.begin(); iter1 != list1.end(); ++iter1)
        {
            str=str+(*iter1);
        }
        ui->textEdit->document()->setHtml(str);
    }
    /*
     QTestCursor cursor = ui->textEdit->textCursor();
     QTextBlockFormat textBlockFormat =cursor.blockFormat();
     textBlockFormat.setAlignment(Qt::AlignLeft);
     cursor.mergeBlockFormat(textBlockFormat);
     ui->textEdit->setTextCursor(cursor);
     */
}
void MainWindow::on_actionTextCenter_triggered()
{
    QStringList list1;
    list1.clear();
    QList<QString>::iterator iter1;
    QString str= ui->textEdit->document()->toPlainText();
    list1 = str.split("\n");
    QString str1="<p align=\"center\">", str2="<\\p>";

    if (!list1.isEmpty()){
        for (iter1 = list1.begin(); iter1 != list1.end(); ++iter1)
        {
            *iter1=str1+(*iter1)+str2;
        }
    }
    str.clear();
    if (!list1.isEmpty()){
        for (iter1 = list1.begin(); iter1 != list1.end(); ++iter1)
        {
            str=str+(*iter1);
        }
        ui->textEdit->document()->setHtml(str);
    }
    /*
     QTestCursor cursor = ui->textEdit->textCursor();
     QTextBlockFormat textBlockFormat =cursor.blockFormat();
     textBlockFormat.setAlignment(Qt::AlignCenter);
     cursor.mergeBlockFormat(textBlockFormat);
     ui->textEdit->setTextCursor(cursor);
     */
}
//Таблица
void MainWindow::insertTable(int n, int m)
{
    QTextTableFormat format;
    format.setWidth(500);
    format.setAlignment(Qt::AlignCenter);
    format.setBorder(1);
    format.setBorderStyle(QTextFrameFormat::BorderStyle_Solid);
    format.setPadding(1);
    format.setCellPadding(1);
    format.setCellSpacing(0);
    ui->textEdit->textCursor().insertTable(n, m, format);
}

void MainWindow::on_action_table_triggered()
{
    MyTable* dialog = new MyTable(this);
    if (dialog->exec() == QDialog::Accepted) {
        SizeNM s = dialog->getSize();
        ui->textEdit->textCursor().insertTable(s.n, s.m);
    }
}

void MainWindow::on_action_Number_triggered()
{
    QString str= ui->textEdit->document()->toPlainText();
    int count = 1;
    if (str.size() && str[0]!="\n")
    {
        str.insert(0,QString::number(count) + ".");
        count++;
    }
    for (int i=0;i<str.size();i++)
    {
        if (str[i] == "\n" && ((i+1) < str.size()) && str[i+1] != "\n")
        {
            str.insert(i+1,QString::number(count) + ".");
            count++;
        }
    }
    ui->textEdit->setPlainText(str);
}
