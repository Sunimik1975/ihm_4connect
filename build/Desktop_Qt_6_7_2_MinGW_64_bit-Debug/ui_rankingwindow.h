/********************************************************************************
** Form generated from reading UI file 'rankingwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RANKINGWINDOW_H
#define UI_RANKINGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_rankingwindow
{
public:
    QVBoxLayout *verticalLayout;
    QListView *listView;

    void setupUi(QDialog *rankingwindow)
    {
        if (rankingwindow->objectName().isEmpty())
            rankingwindow->setObjectName("rankingwindow");
        rankingwindow->setWindowModality(Qt::WindowModality::ApplicationModal);
        rankingwindow->resize(400, 300);
        verticalLayout = new QVBoxLayout(rankingwindow);
        verticalLayout->setObjectName("verticalLayout");
        listView = new QListView(rankingwindow);
        listView->setObjectName("listView");

        verticalLayout->addWidget(listView);


        retranslateUi(rankingwindow);

        QMetaObject::connectSlotsByName(rankingwindow);
    } // setupUi

    void retranslateUi(QDialog *rankingwindow)
    {
        rankingwindow->setWindowTitle(QCoreApplication::translate("rankingwindow", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class rankingwindow: public Ui_rankingwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANKINGWINDOW_H
