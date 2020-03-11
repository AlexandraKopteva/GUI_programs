#ifndef MYTABLE_H
#define MYTABLE_H

#include <QDialogButtonBox>
#include <QPushButton>
#include <QGridLayout>
#include <QSpinBox>
#include <QDialog>
#include <QWidget>

#include <QLabel>

struct SizeNM {
    int n;
    int m;
    SizeNM() {}
    SizeNM(int l, int k) : n(l), m(k) {}
};

class MyTable : public QDialog
{
    Q_OBJECT
public:
    MyTable(QWidget *parent = nullptr);
    ~MyTable();
    SizeNM getSize();
private:
    QSpinBox *n;
    QSpinBox *m;
};
#endif // MYTABLE_H
