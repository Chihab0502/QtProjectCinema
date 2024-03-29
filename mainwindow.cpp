#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pm(":/assets/img/infoImage.jpg");
    ui->lblInfoImage->setPixmap(pm);

    ptrBook = new book(this);
    ptrCancel = new cancel(this);

    connect(ptrBook, &book::mysignal, this, &MainWindow::updateUI);
    connect(ptrCancel, &cancel::mysignal1, this, &MainWindow::updateUI);

    updateUI();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete ptrBook;
    delete ptrCancel;
}

void MainWindow::updateUI()
{
    qDebug() << "in updateUI()";

    MyDB *myDB = MyDB::getInstance();
    QStringList seatData = myDB->loadDataFromFile();

    qDebug() << "Seat data loaded: " << seatData;

    for(const QString& seat : seatData)
    {
        QStringList seatInfo = seat.split(" : ");
        if(seatInfo.size() != 2) {
            qDebug() << "Invalid seat data format: " << seat;
            continue;
        }

        QString seatNumber = seatInfo[0];
        QString seatStatus = seatInfo[1].trimmed();

        qDebug() << "Seat Number: " << seatNumber << ", Status: " << seatStatus;

        QString labelName = "lbl" + seatNumber;
        QLabel *ptr = this->findChild<QLabel*>(labelName);
        if(ptr != nullptr)
        {
            qDebug() << "Label found: " << labelName;

            if(seatStatus.compare("Reservede") == 0)
            {
                QPixmap pm(":/assets/img/booked.jpg");
                ptr->setPixmap(pm);
                ptr->setScaledContents(true);
                qDebug() << seatNumber << " : is booked";
            }
            else
            {
                QPixmap pm(":/assets/img/available.jpg");
                ptr->setPixmap(pm);
                ptr->setScaledContents(true);
                qDebug() << seatNumber << " : is Available";
            }
        }
        else
        {
            qDebug() << "Label not found for seat: " << seatNumber;
        }
    }
}




void MainWindow::on_btnBook_clicked()
{
    ptrBook->updateUI();
    ptrBook->show();
}

void MainWindow::on_btnCancel_clicked()
{
    ptrCancel->updateUI();
    ptrCancel->show();
}

void MainWindow::on_btnReset_clicked()
{
    MyDB *myDB = MyDB::getInstance();
    myDB->resetSeatData();

    updateUI();
}

