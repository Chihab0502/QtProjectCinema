#include "book.h"
#include "ui_book.h"
#include "mydb.h"
#include <QLabel>

book::book(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::book)
{
    ui->setupUi(this);
    updateUI();
}

book::~book()
{
    delete ui;
}

void book::updateUI()
{
    ui->cmbSeats->clear();

    MyDB *myDB = MyDB::getInstance();
    QStringList seats = myDB->loadDataFromFile();

    for(const QString& seat : seats)
    {
        ui->cmbSeats->addItem(seat);
    }

    if(ui->cmbSeats->count() <= 0)
        ui->btnBook->setEnabled(false);
}

void book::on_btnBook_clicked()
{
    QString sSeat = ui->cmbSeats->currentText();

    MyDB *myDB = MyDB::getInstance();
    myDB->reserveSeat(sSeat);

    ui->lblInfo->setText("Seat booked successfully!");
    updateUI();
    emit mysignal();
}
