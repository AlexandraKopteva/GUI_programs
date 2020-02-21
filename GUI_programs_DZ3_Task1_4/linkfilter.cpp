#include "linkfilter.h"

linkfilter::linkfilter(QObject *parent) : QObject(parent)
{

}
bool linkfilter::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress) {
    QMouseEvent *mev = static_cast<QMouseEvent*>(event);
    if (mev->button() == Qt::MouseButton::RightButton) {
        emit linckClicked();
        return true;}
    }
    return false;
}
