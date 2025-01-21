/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QFormLayout *formLayout;
    QLabel *NickNameM;
    QLineEdit *nicknameLineEditM;
    QLabel *passwordM;
    QLineEdit *passwordLineEditM;
    QPushButton *registerButtonM;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QPushButton *loginButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        gridLayout->setSizeConstraint(QLayout::SizeConstraint::SetFixedSize);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");

        gridLayout->addLayout(verticalLayout, 1, 1, 2, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::MinimumExpanding);

        gridLayout->addItem(verticalSpacer_2, 0, 0, 1, 6);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 0, 2, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 5, 2, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(-1, -1, 10, -1);
        NickNameM = new QLabel(centralwidget);
        NickNameM->setObjectName("NickNameM");

        formLayout->setWidget(0, QFormLayout::LabelRole, NickNameM);

        nicknameLineEditM = new QLineEdit(centralwidget);
        nicknameLineEditM->setObjectName("nicknameLineEditM");

        formLayout->setWidget(0, QFormLayout::FieldRole, nicknameLineEditM);

        passwordM = new QLabel(centralwidget);
        passwordM->setObjectName("passwordM");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(passwordM->sizePolicy().hasHeightForWidth());
        passwordM->setSizePolicy(sizePolicy);

        formLayout->setWidget(1, QFormLayout::LabelRole, passwordM);

        passwordLineEditM = new QLineEdit(centralwidget);
        passwordLineEditM->setObjectName("passwordLineEditM");
        sizePolicy.setHeightForWidth(passwordLineEditM->sizePolicy().hasHeightForWidth());
        passwordLineEditM->setSizePolicy(sizePolicy);

        formLayout->setWidget(1, QFormLayout::FieldRole, passwordLineEditM);

        registerButtonM = new QPushButton(centralwidget);
        registerButtonM->setObjectName("registerButtonM");

        formLayout->setWidget(2, QFormLayout::FieldRole, registerButtonM);

        label = new QLabel(centralwidget);
        label->setObjectName("label");

        formLayout->setWidget(2, QFormLayout::LabelRole, label);


        gridLayout->addLayout(formLayout, 1, 3, 2, 1);

        verticalSpacer = new QSpacerItem(40, 60, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::MinimumExpanding);

        gridLayout->addItem(verticalSpacer, 3, 0, 2, 6);

        loginButton = new QPushButton(centralwidget);
        loginButton->setObjectName("loginButton");

        gridLayout->addWidget(loginButton, 1, 4, 2, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(4, 1);

        verticalLayout_2->addLayout(gridLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        NickNameM->setText(QCoreApplication::translate("MainWindow", "Nickname:", nullptr));
        passwordM->setText(QCoreApplication::translate("MainWindow", "Password:", nullptr));
        registerButtonM->setText(QCoreApplication::translate("MainWindow", "Registrarse", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Si no tienes cuenta puedes", nullptr));
        loginButton->setText(QCoreApplication::translate("MainWindow", "Iniciar sesi\303\263n", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
