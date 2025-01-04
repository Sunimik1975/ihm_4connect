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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameBoard
{
public:
    QPushButton *cerrarSesionButton;

    void setupUi(QWidget *GameBoard)
    {
        if (GameBoard->objectName().isEmpty())
            GameBoard->setObjectName("GameBoard");
        GameBoard->resize(400, 300);
        cerrarSesionButton = new QPushButton(GameBoard);
        cerrarSesionButton->setObjectName("cerrarSesionButton");
        cerrarSesionButton->setGeometry(QRect(150, 270, 80, 24));

        retranslateUi(GameBoard);

        QMetaObject::connectSlotsByName(GameBoard);
    } // setupUi

    void retranslateUi(QWidget *GameBoard)
    {
        GameBoard->setWindowTitle(QCoreApplication::translate("GameBoard", "Form", nullptr));
        cerrarSesionButton->setText(QCoreApplication::translate("GameBoard", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameBoard: public Ui_GameBoard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEBOARD_H
