#ifndef ORGANIZER_H
#define ORGANIZER_H

#include <QObject>
#include<QFile>
/*
 DZ_9
1. Создать внешний вид программы-органайзера, которая будет отображать задачи.
Каждая задача состоит из следующих пунктов:
        * id задачи (уникальный номер)
        * название задачи
        * описание задачи
        * дата начала выполнения задачи (в формате dd.mm.yyyy)
        * дата окончания выполнения задачи (в формате dd.mm.yyyy)
        * текущий прогресс (число от 0 до 100%)
Для этого создать 4 qml файла:
        * Основное окно (main.qml)
        * Рабочая область
        * Делегат
        * Модель (заполнить начальными данными)
2. Создать пользовательский виджет - кнопку в отдельном файле.
Добавить в рабочую область кнопку "Добавить", которая будет добавлять новое задание.
3. Создать окно для добавления нового задания. В этом окне должны быть поля для ввода составляющих,
которые есть у любой задачи (см. 1 задание), кроме id (он будет генерироваться автоматически).
Предусмотреть валидацию пользовательского ввода, например, текущий прогресс - это дожно быть целое число от 0 до 100.
4. (По желанию) Ввод даты начала и окончания выполнения задачи осуществить через виджет календаря.
DZ_10
2. Создать модель для программы-органайзера (из прошлого урока) в виде класса, унаследованного от QAbstractListModel.
Соединить модель с представлением.
3. Доработать программу-органайзер так, чтобы можно было добавлять и удалять задачи.
*/

class Organizer : public QObject//public QAbstractListModel
{
    Q_OBJECT
public:
    explicit Organizer(QObject *parent = nullptr);
    ~Organizer();
    Q_INVOKABLE void loadBase();
    Q_INVOKABLE void getNextRecord();
    Q_INVOKABLE void writeNewInformation(QString, QString, QString, QString, QString, QString);
    Q_INVOKABLE void rewriteFile();
    Q_INVOKABLE void deleteFile();
 private:
    QFile *file;
 signals:
    void initEnd(bool succeed);
    void load(QString id, QString task, QString desc, QString date_beg, QString date_end, QString prog);
 private slots:
 };

#endif // ORGANIZER_H
