#include "mydb.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

MyDB* MyDB::instance = nullptr;

MyDB::MyDB()
{
    init();
}

void MyDB::init()
{
    qDebug() << "in init()";
}

MyDB *MyDB::getInstance()
{
    qDebug() << "in MyDB::getInstance()";

    if(instance == nullptr)
        instance = new MyDB();

    return instance;
}

void MyDB::ResetInstance()
{
    qDebug() << "deleting instance of MyDB";
    delete instance;
    instance = nullptr;
}

QStringList MyDB::loadDataFromFile()
{
    QString fileName = "./seat_data.txt";

    qDebug() << "Loading data from file: " << fileName;
    QStringList data;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for reading.";
        return data;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        data.append(line);
    }

    file.close();
    return data;
}

void MyDB::saveDataToFile(const QString &fileName, const QStringList &data)
{
    qDebug() << "Saving data to file: " << fileName;
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for writing.";
        return;
    }

    QTextStream out(&file);
    for (const QString &line : data) {
        out << line << Qt::endl;
    }

    file.close();
}

void MyDB::reserveSeat(const QString &seat)
{
    QStringList seats = loadDataFromFile();

    for (QString &s : seats) {
        if (s.startsWith(seat)) {
            s = s.replace(s.indexOf(':') + 2, 8, "Reserved");
            break;
        }
    }

    saveDataToFile("seat_data.txt", seats);
}

void MyDB::cancelSeat(const QString &seat)
{
    QStringList seats = loadDataFromFile();

    for (QString &s : seats) {
        if (s.startsWith(seat)) {
            s = s.replace(s.indexOf(':') + 2, 8, "Available");
            break;
        }
    }

    saveDataToFile("seat_data.txt", seats);
}

void MyDB::resetSeatData()
{
    QStringList seatData = loadDataFromFile();

    for(QString& seat : seatData)
    {
        QStringList seatInfo = seat.split(" : ");
        if(seatInfo.size() == 2)
        {
            seatInfo[1] = "Available";
            seat = seatInfo.join(" : ");
        }
    }

    saveDataToFile("seat_data.txt", seatData);
}

