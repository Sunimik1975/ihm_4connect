/********************************************************************************
** Form generated from reading UI file 'regitro.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGITRO_H
#define UI_REGITRO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_regitro
{
public:

    void setupUi(QDialog *regitro)
    {
        if (regitro->objectName().isEmpty())
            regitro->setObjectName("regitro");
        regitro->resize(400, 300);

        retranslateUi(regitro);

        QMetaObject::connectSlotsByName(regitro);
    } // setupUi

    void retranslateUi(QDialog *regitro)
    {
        regitro->setWindowTitle(QCoreApplication::translate("regitro", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class regitro: public Ui_regitro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGITRO_H
