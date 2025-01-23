/********************************************************************************
** Form generated from reading UI file 'staticsplayer.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATICSPLAYER_H
#define UI_STATICSPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StaticsPlayer
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *opponentsContainer;
    QWidget *chartContainer;

    void setupUi(QDialog *StaticsPlayer)
    {
        if (StaticsPlayer->objectName().isEmpty())
            StaticsPlayer->setObjectName("StaticsPlayer");
        StaticsPlayer->resize(400, 300);
        horizontalLayout = new QHBoxLayout(StaticsPlayer);
        horizontalLayout->setObjectName("horizontalLayout");
        opponentsContainer = new QWidget(StaticsPlayer);
        opponentsContainer->setObjectName("opponentsContainer");

        horizontalLayout->addWidget(opponentsContainer);

        chartContainer = new QWidget(StaticsPlayer);
        chartContainer->setObjectName("chartContainer");

        horizontalLayout->addWidget(chartContainer);


        retranslateUi(StaticsPlayer);

        QMetaObject::connectSlotsByName(StaticsPlayer);
    } // setupUi

    void retranslateUi(QDialog *StaticsPlayer)
    {
        StaticsPlayer->setWindowTitle(QCoreApplication::translate("StaticsPlayer", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StaticsPlayer: public Ui_StaticsPlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATICSPLAYER_H
