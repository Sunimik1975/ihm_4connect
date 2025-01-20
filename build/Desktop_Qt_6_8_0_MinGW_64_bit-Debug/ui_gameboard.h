/********************************************************************************
** Form generated from reading UI file 'gameboard.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEBOARD_H
#define UI_GAMEBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameBoard
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *cerrarPushButton;
    QSpacerItem *verticalSpacer;
    QPushButton *cerrarPushButton2;
    QListView *ranking;

    void setupUi(QWidget *GameBoard)
    {
        if (GameBoard->objectName().isEmpty())
            GameBoard->setObjectName("GameBoard");
        GameBoard->resize(400, 300);
        gridLayout = new QGridLayout(GameBoard);
        gridLayout->setObjectName("gridLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 1, 1, 1);

        cerrarPushButton = new QPushButton(GameBoard);
        cerrarPushButton->setObjectName("cerrarPushButton");

        gridLayout->addWidget(cerrarPushButton, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 249, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);

        cerrarPushButton2 = new QPushButton(GameBoard);
        cerrarPushButton2->setObjectName("cerrarPushButton2");

        gridLayout->addWidget(cerrarPushButton2, 1, 2, 1, 1);

        ranking = new QListView(GameBoard);
        ranking->setObjectName("ranking");

        gridLayout->addWidget(ranking, 0, 1, 1, 1);


        retranslateUi(GameBoard);

        QMetaObject::connectSlotsByName(GameBoard);
    } // setupUi

    void retranslateUi(QWidget *GameBoard)
    {
        GameBoard->setWindowTitle(QCoreApplication::translate("GameBoard", "Form", nullptr));
        cerrarPushButton->setText(QCoreApplication::translate("GameBoard", "PushButton", nullptr));
        cerrarPushButton2->setText(QCoreApplication::translate("GameBoard", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameBoard: public Ui_GameBoard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEBOARD_H
