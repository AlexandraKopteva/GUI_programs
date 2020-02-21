#include "windowswidget.h"
#include "contextmenu.h"


WindowsWidget::WindowsWidget(QWidget *parent) : QWidget(parent)
{
    QGridLayout *gridLayout = new QGridLayout(this);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

    textEdit = new ContextMenu(this);
    textEdit->setObjectName(QString::fromUtf8("textEdit"));
    textEdit->setUndoRedoEnabled(false);

    gridLayout->addWidget(textEdit, 0, 0, 1, 1);
    QHBoxLayout *horizontalLayout = new QHBoxLayout();
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

    label = new QLabel(this);
    label->setObjectName(QString::fromUtf8("label"));
    label->setTextFormat(Qt::RichText);

    horizontalLayout->addWidget(label);

    lineEdit = new QLineEdit(this);
    lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
    lineEdit->setText("Author Name");

    horizontalLayout->addWidget(lineEdit);

    gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

}
WindowsWidget::~WindowsWidget()
{
    delete label;
    delete lineEdit;
    delete textEdit;
}
