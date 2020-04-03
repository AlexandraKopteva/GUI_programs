#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include "blocksheme.h"
#include "graphiicsview.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow :  public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    QGraphicsScene* scene;
    QGraphicsView* view;
private slots:
    void reDraw();
private:
    Ui::MainWindow *ui;
    int geometryCounter;
protected:
    void mousePressEvent(QMouseEvent  *event) override;
    void wheelEvent(QWheelEvent  *event) override;
};
#endif // MAINWINDOW_H
