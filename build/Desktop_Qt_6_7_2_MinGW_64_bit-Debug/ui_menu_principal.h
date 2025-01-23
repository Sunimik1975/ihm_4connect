/********************************************************************************
** Form generated from reading UI file 'menu_principal.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
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
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_Menu_principal
{
public:
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_2;
    QPushButton *multiplayer_button;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QPushButton *Singleplayer_button;
    QPushButton *fondo_oscuro;

    void setupUi(QDialog *Menu_principal)
    {
        if (Menu_principal->objectName().isEmpty())
            Menu_principal->setObjectName("Menu_principal");
        Menu_principal->resize(400, 300);
        gridLayout_2 = new QGridLayout(Menu_principal);
        gridLayout_2->setObjectName("gridLayout_2");
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 2, 0, 1, 1);

        multiplayer_button = new QPushButton(Menu_principal);
        multiplayer_button->setObjectName("multiplayer_button");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(multiplayer_button->sizePolicy().hasHeightForWidth());
        multiplayer_button->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(multiplayer_button, 4, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 5, 0, 1, 1);

        Singleplayer_button = new QPushButton(Menu_principal);
        Singleplayer_button->setObjectName("Singleplayer_button");
        sizePolicy.setHeightForWidth(Singleplayer_button->sizePolicy().hasHeightForWidth());
        Singleplayer_button->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(Singleplayer_button, 3, 0, 1, 1);

        fondo_oscuro = new QPushButton(Menu_principal);
        fondo_oscuro->setObjectName("fondo_oscuro");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(fondo_oscuro->sizePolicy().hasHeightForWidth());
        fondo_oscuro->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(fondo_oscuro, 1, 1, 1, 1);


        retranslateUi(Menu_principal);

        QMetaObject::connectSlotsByName(Menu_principal);
    } // setupUi

    void retranslateUi(QDialog *Menu_principal)
    {
        Menu_principal->setWindowTitle(QCoreApplication::translate("Menu_principal", "Dialog", nullptr));
        multiplayer_button->setText(QCoreApplication::translate("Menu_principal", "1VS1", nullptr));
        Singleplayer_button->setText(QCoreApplication::translate("Menu_principal", "Singleplayer", nullptr));
        fondo_oscuro->setText(QCoreApplication::translate("Menu_principal", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Menu_principal: public Ui_Menu_principal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_PRINCIPAL_H
