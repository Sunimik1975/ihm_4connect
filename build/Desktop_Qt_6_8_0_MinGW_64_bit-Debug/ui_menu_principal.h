/********************************************************************************
** Form generated from reading UI file 'menu_principal.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_PRINCIPAL_H
#define UI_MENU_PRINCIPAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Menu_principal
{
public:
    QGridLayout *gridLayout;
    QPushButton *Singleplayer_button;
    QPushButton *multiplayer_button;

    void setupUi(QDialog *Menu_principal)
    {
        if (Menu_principal->objectName().isEmpty())
            Menu_principal->setObjectName("Menu_principal");
        Menu_principal->resize(400, 300);
        gridLayout = new QGridLayout(Menu_principal);
        gridLayout->setObjectName("gridLayout");
        Singleplayer_button = new QPushButton(Menu_principal);
        Singleplayer_button->setObjectName("Singleplayer_button");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Singleplayer_button->sizePolicy().hasHeightForWidth());
        Singleplayer_button->setSizePolicy(sizePolicy);

        gridLayout->addWidget(Singleplayer_button, 0, 0, 1, 1);

        multiplayer_button = new QPushButton(Menu_principal);
        multiplayer_button->setObjectName("multiplayer_button");

        gridLayout->addWidget(multiplayer_button, 1, 0, 1, 1);


        retranslateUi(Menu_principal);

        QMetaObject::connectSlotsByName(Menu_principal);
    } // setupUi

    void retranslateUi(QDialog *Menu_principal)
    {
        Menu_principal->setWindowTitle(QCoreApplication::translate("Menu_principal", "Dialog", nullptr));
        Singleplayer_button->setText(QCoreApplication::translate("Menu_principal", "Singleplayer", nullptr));
        multiplayer_button->setText(QCoreApplication::translate("Menu_principal", "1VS1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Menu_principal: public Ui_Menu_principal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_PRINCIPAL_H
