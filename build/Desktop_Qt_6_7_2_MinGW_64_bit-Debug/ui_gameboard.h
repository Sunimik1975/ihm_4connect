/********************************************************************************
** Form generated from reading UI file 'gameboard.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEBOARD_H
#define UI_GAMEBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameBoard
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *Mostrar_rounds;
    QPushButton *cerrarPushButton;
    QPushButton *cerrarPushButton2;
    QPushButton *rankingbutton;
    QPushButton *modifyProfileButton2;
    QSpacerItem *verticalSpacer;
    QPushButton *caca;

    void setupUi(QWidget *GameBoard)
    {
        if (GameBoard->objectName().isEmpty())
            GameBoard->setObjectName("GameBoard");
        GameBoard->resize(400, 300);
        gridLayout = new QGridLayout(GameBoard);
        gridLayout->setObjectName("gridLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        Mostrar_rounds = new QPushButton(GameBoard);
        Mostrar_rounds->setObjectName("Mostrar_rounds");

        gridLayout->addWidget(Mostrar_rounds, 1, 0, 1, 1);

        cerrarPushButton = new QPushButton(GameBoard);
        cerrarPushButton->setObjectName("cerrarPushButton");

        gridLayout->addWidget(cerrarPushButton, 0, 0, 1, 1);

        cerrarPushButton2 = new QPushButton(GameBoard);
        cerrarPushButton2->setObjectName("cerrarPushButton2");

        gridLayout->addWidget(cerrarPushButton2, 0, 2, 1, 1);

        rankingbutton = new QPushButton(GameBoard);
        rankingbutton->setObjectName("rankingbutton");

        gridLayout->addWidget(rankingbutton, 1, 2, 1, 1);

        modifyProfileButton2 = new QPushButton(GameBoard);
        modifyProfileButton2->setObjectName("modifyProfileButton2");

        gridLayout->addWidget(modifyProfileButton2, 2, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 249, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 0, 1, 1);

        caca = new QPushButton(GameBoard);
        caca->setObjectName("caca");

        gridLayout->addWidget(caca, 3, 2, 1, 1);


        retranslateUi(GameBoard);

        QMetaObject::connectSlotsByName(GameBoard);
    } // setupUi

    void retranslateUi(QWidget *GameBoard)
    {
        GameBoard->setWindowTitle(QCoreApplication::translate("GameBoard", "Form", nullptr));
        Mostrar_rounds->setText(QCoreApplication::translate("GameBoard", "Mostrar Rounds", nullptr));
        cerrarPushButton->setText(QCoreApplication::translate("GameBoard", "PushButton", nullptr));
        cerrarPushButton2->setText(QCoreApplication::translate("GameBoard", "PushButton", nullptr));
        rankingbutton->setText(QCoreApplication::translate("GameBoard", "Mostrar Ranking", nullptr));
        modifyProfileButton2->setText(QCoreApplication::translate("GameBoard", "Modificar perfil", nullptr));
        caca->setText(QCoreApplication::translate("GameBoard", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameBoard: public Ui_GameBoard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEBOARD_H
