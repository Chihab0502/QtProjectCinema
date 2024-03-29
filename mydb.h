#ifndef MYDB_H
#define MYDB_H

#include <QObject>
#include <QDebug>
#include <QFile>
#include <QTextStream>

class MyDB : public QObject
{
    Q_OBJECT
public:
    static MyDB* getInstance();
    static void ResetInstance();
    QStringList loadDataFromFile();
    void saveDataToFile(const QString &fileName, const QStringList &data);
    void reserveSeat(const QString& seat);
    void cancelSeat(const QString &seat);
    void resetSeatData();

private:
    explicit MyDB();
    void init();

private:
    static MyDB* instance;
};

#endif // MYDB_H
