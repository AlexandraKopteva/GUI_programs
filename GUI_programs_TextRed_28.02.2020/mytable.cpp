#include "mytable.h"

MyTable::MyTable(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("Таблица");
    setFixedSize(200, 100);
    QGridLayout *layout = new QGridLayout(this);
    setLayout(layout);
    n = new QSpinBox (this);
    m = new QSpinBox (this);
    n->setValue(1);
    m->setValue(1);
    layout->addWidget(n, 1, 1, 1, 2);
    layout->addWidget(m, 1, 3, 1, 2);

    QPushButton *ok = new QPushButton ("&Ok");
    QPushButton *cancel = new QPushButton ("&Cancel");
    connect(ok, SIGNAL(clicked()), SLOT(accept()));
    connect(cancel, SIGNAL(clicked()), SLOT(reject()));
    layout->addWidget(cancel, 2, 1, 1, 2);
    layout->addWidget(ok, 2, 3, 1, 2);

    QLabel* row=new QLabel("Строк");
    QLabel* col=new QLabel("Столбцов");
    layout->addWidget(row, 0, 1, 1, 2);
    layout->addWidget(col, 0, 3, 1, 2);
}

MyTable::~MyTable()
{
    delete n;
    delete m;
}

SizeNM MyTable::getSize()
{
    return SizeNM(n->value(), m->value());
}

