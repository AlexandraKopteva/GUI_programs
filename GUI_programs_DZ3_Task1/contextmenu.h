#ifndef CONTEXTMENU_H
#define CONTEXTMENU_H

#include <QtGui>
#include<QTextEdit>
#include<QMenu>
#include<QtCore>

class ContextMenu : public QTextEdit
{
Q_OBJECT
private:
    QMenu* m_pmnu;

protected:
    virtual void contextMenuEvent(QContextMenuEvent* pe)
    {
        m_pmnu->exec(pe->globalPos());
    }

public:
    ContextMenu(QWidget* pwgt = nullptr): QTextEdit(pwgt)
    {
        setReadOnly(true);
        m_pmnu = new QMenu(this);
        m_pmnu->addAction("&Qther_1");
        m_pmnu->addAction("&Qther_2");
        connect(m_pmnu,  SIGNAL(triggered(QAction*)), this, SLOT(slotActivated(QAction*)));
    }
    ~ContextMenu();
public slots:
    void slotActivated(QAction* pAction);
};

#endif // CONTEXTMENU_H
