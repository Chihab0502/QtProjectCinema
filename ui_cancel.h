/********************************************************************************
** Form generated from reading UI file 'cancel.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CANCEL_H
#define UI_CANCEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_cancel
{
public:
    QPushButton *btnCancel;
    QLabel *label;
    QComboBox *cmbSeats;
    QLabel *lblInfo;

    void setupUi(QDialog *cancel)
    {
        if (cancel->objectName().isEmpty())
            cancel->setObjectName("cancel");
        cancel->setWindowModality(Qt::WindowModal);
        cancel->resize(250, 112);
        btnCancel = new QPushButton(cancel);
        btnCancel->setObjectName("btnCancel");
        btnCancel->setGeometry(QRect(80, 60, 75, 23));
        label = new QLabel(cancel);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 10, 101, 21));
        cmbSeats = new QComboBox(cancel);
        cmbSeats->setObjectName("cmbSeats");
        cmbSeats->setGeometry(QRect(110, 10, 121, 22));
        lblInfo = new QLabel(cancel);
        lblInfo->setObjectName("lblInfo");
        lblInfo->setGeometry(QRect(50, 90, 151, 16));

        retranslateUi(cancel);

        QMetaObject::connectSlotsByName(cancel);
    } // setupUi

    void retranslateUi(QDialog *cancel)
    {
        cancel->setWindowTitle(QCoreApplication::translate("cancel", "Cancel Ticket", nullptr));
        btnCancel->setText(QCoreApplication::translate("cancel", "Cancel", nullptr));
        label->setText(QCoreApplication::translate("cancel", "Select Seat", nullptr));
        lblInfo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class cancel: public Ui_cancel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANCEL_H
