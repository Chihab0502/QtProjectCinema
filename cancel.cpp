#include "cancel.h"
#include "ui_cancel.h"
#include "mydb.h"
#include <QLabel>

cancel::cancel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cancel)
{
    ui->setupUi(this);
    updateUI();
}

cancel::~cancel()
{
    delete ui;
}

void cancel::updateUI()
{
    ui->cmbSeats->clear();

    MyDB *myDB = MyDB::getInstance();
    QStringList seats = myDB->loadDataFromFile();

    for(const QString& seat : seats)
    {
        ui->cmbSeats->addItem(seat);
    }

    if(ui->cmbSeats->count() <= 0)
        ui->btnCancel->setEnabled(false);
}

void cancel::on_btnCancel_clicked()
{
    QString sSeat = ui->cmbSeats->currentText();

    MyDB *myDB = MyDB::getInstance();
    myDB->cancelSeat(sSeat);

    ui->lblInfo->setText("Seat canceled successfully!");
    updateUI();
    emit mysignal1();
}
