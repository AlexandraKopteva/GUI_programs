#ifndef WINDOWSWIDGET_H
#define WINDOWSWIDGET_H

#include"contextmenu.h"
#include <QWidget>
#include <QGridLayout>
#include <QTextStream>
#include <QLineEdit>
#include <QPrinter>
#include <QWidget>
#include <QLabel>

class WindowsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WindowsWidget(QWidget *parent = nullptr);
    ~WindowsWidget();
signals:

public slots:
private:
    QLineEdit *lineEdit;
    QLabel *label;
    ContextMenu* textEdit;
};
#endif // WINDOWSWIDGET_H
