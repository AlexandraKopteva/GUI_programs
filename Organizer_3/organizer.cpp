#include "organizer.h"


Organizer::Organizer(QObject *parent) : QAbstractListModel(parent)
{
    m_data.push_back(TableLine("Задания","Описание задания","Дата начала","Дата окончания","Прогресс"));
}

#define SCIDS static_cast<int>(m_data.size())

int Organizer::rowCount(const QModelIndex &parent) const
{
    return parent.isValid()? 0 : SCIDS;
}

#define SCU(n) static_cast<unsigned>(n)
#define UIR SCU(index.row())

QVariant Organizer::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) return QVariant();

    switch (role) {
    case IdRole: return QVariant(UIR);
    case NameRole: return QVariant(m_data[UIR].name);
    case DescRole: return QVariant(m_data[UIR].description);
    case StartRole: return QVariant(m_data[UIR].start);
    case EndRole: return QVariant(m_data[UIR].end);
    case ProgRole: return QVariant(m_data[UIR].progress);
    default: return QVariant();
    }
}

QHash<int, QByteArray> Organizer::roleNames() const
{
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    roles[IdRole]     = "taskID";
    roles[NameRole]   = "name";
    roles[DescRole]   = "description";
    roles[StartRole]  = "start";
    roles[EndRole]    = "end";
    roles[ProgRole]   = "progress";
    return roles;
}

void Organizer::addLine(QString n, QString d, QString s, QString e, QString p)
{
    beginInsertRows(QModelIndex(), SCIDS, SCIDS);
    m_data.push_back(TableLine(n, d, s, e, p));
    endInsertRows();
    emit dataChanged(createIndex(0,0), createIndex(SCIDS, 0));
}
