#include "linkfilter.h"

linkfilter::linkfilter(QObject *parent) : QObject(parent)
{

}
bool linkfilter::eventFilter(QObject *object, QEvent *event)
{
    if(event->type()== QContextMenuEvent::Mouse)
    {
        emit linckClicked();
        return true;
    }
    return false;
}
