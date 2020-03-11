#ifndef CONTEXTMENU_H
#define CONTEXTMENU_H

#include <QtGui>
#include<QtCore>
//
#include<QTextEdit>
#include<QMenu>
#include<QMainWindow>
#include<QObject>
#include<QContextMenuEvent>

class ContextMenu : public QTextEdit
{
Q_OBJECT

public:
    explicit ContextMenu(QWidget* parent = nullptr);
    ~ContextMenu();

protected:
     void contextMenuEvent(QContextMenuEvent* event) override;
signals:

public slots:
    void copyText();
    void pastText();
private:
    QMenu* menu;
};

#endif // CONTEXTMENU_H
