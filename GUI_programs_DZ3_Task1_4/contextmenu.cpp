#include "contextmenu.h"
#include<QApplication>
#include<QClipboard>

ContextMenu::ContextMenu(QWidget* parent) :QTextEdit(parent)
{
    menu = new QMenu(this);
    QAction *copyAction = menu->addAction("Копировать");
    QAction *pastAction = menu->addAction("Вставить");
    connect(copyAction, SIGNAL(triggered()), this, SLOT(copyText()));
    connect(pastAction, SIGNAL(triggered()), this, SLOT(pastText()));
}

ContextMenu::~ContextMenu()
{
}
void ContextMenu::contextMenuEvent(QContextMenuEvent *event)
{
   menu->exec(event->globalPos());                 // Размещаем контекстное меню по экранным координатам
}

void ContextMenu::copyText()
{
   QString str = this->textCursor().selectedText(); // Получаем выделенный текст
   qApp->clipboard()->setText(str);                 // Копируем текст
}
void ContextMenu::pastText()
{
   QString str = qApp->clipboard()->text();          // Извлекаем из буфера обмена
   this->textCursor().insertText(str);               // Вставляем текст в позицию курсора
}
