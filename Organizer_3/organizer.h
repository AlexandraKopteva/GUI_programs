#ifndef ORGANIZER_H
#define ORGANIZER_H

#include <QAbstractListModel>
#include <QObject>
#include <vector>

class Organizer : public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles { IdRole = Qt::UserRole + 1, NameRole, DescRole, StartRole, EndRole, ProgRole };
    struct TableLine
    {
        QString name;
        QString description;
        QString start;
        QString end;
        QString progress;
        TableLine(){}
        TableLine(QString n, QString d, QString s, QString e, QString p)
            : name(n), description(d), start(s), end(e), progress(p) {}
    };
    Organizer(QObject *parent = nullptr);
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;
    //
    Q_INVOKABLE int rowCount(const QModelIndex &parent) const override;
    Q_INVOKABLE void addLine(QString n, QString d, QString s, QString e, QString p);
private:
    std::vector<TableLine> m_data;
};
#endif // ORGANIZER_H
