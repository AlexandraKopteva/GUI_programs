#ifndef LINKFILTER_H
#define LINKFILTER_H

#include <QObject>
#include <QEvent>
#include<QContextMenuEvent>

class linkfilter : public QObject
{
    Q_OBJECT
public:
    explicit linkfilter(QObject *parent = nullptr);

signals:
     void linckClicked();
protected:
     bool eventFilter(QObject*, QEvent *) override;
public slots:
};

#endif // LINKFILTER_H
