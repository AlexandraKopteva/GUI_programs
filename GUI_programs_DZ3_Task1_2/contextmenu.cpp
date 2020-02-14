#include "contextmenu.h"
/*
ContextMenu::ContextMenu(QWidget* pwgt = nullptr) : QTextEdit(pwgt)
{
    setReadOnly(true);
    m_pmnu = new QMenu(this);
    m_pmnu->addAction("&Qther");
    connect(m_pmnu,  SIGNAL(triggered(QAction*)), this, SLOT(slotActivated(QAction*)));
}
*/
ContextMenu::~ContextMenu()
{

}

void ContextMenu::slotActivated(QAction* pAction)
{
    QString str = pAction->text().remove("&");

}
