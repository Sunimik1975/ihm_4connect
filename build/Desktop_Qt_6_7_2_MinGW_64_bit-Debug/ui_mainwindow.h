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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
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
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLabel *registerLabel;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_5;
    QPushButton *loginButton;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *nicknameLineEditM;
    QSpacerItem *verticalSpacer_4;
    QLineEdit *passwordLineEditM;
    QSpacerItem *verticalSpacer_2;
    QPushButton *nose_contra;
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
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_3->addItem(verticalSpacer_6, 1, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 1, 4, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        horizontalLayout_3->addWidget(label_2);

        registerLabel = new QLabel(centralwidget);
        registerLabel->setObjectName("registerLabel");
        registerLabel->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        registerLabel->setStyleSheet(QString::fromUtf8("font: 9pt \"Segoe UI\";\n"
"text-decoration: underline;\n"
"color: rgb(0, 255, 255);"));
        registerLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_3->addWidget(registerLabel);


        gridLayout_3->addLayout(horizontalLayout_3, 5, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_3->addItem(verticalSpacer_3, 2, 1, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_3->addItem(verticalSpacer_5, 1, 1, 1, 1);

        loginButton = new QPushButton(centralwidget);
        loginButton->setObjectName("loginButton");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(loginButton->sizePolicy().hasHeightForWidth());
        loginButton->setSizePolicy(sizePolicy);
        loginButton->setMinimumSize(QSize(0, 0));
        loginButton->setMaximumSize(QSize(16777215, 60));

        gridLayout_3->addWidget(loginButton, 2, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        nicknameLineEditM = new QLineEdit(centralwidget);
        nicknameLineEditM->setObjectName("nicknameLineEditM");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(nicknameLineEditM->sizePolicy().hasHeightForWidth());
        nicknameLineEditM->setSizePolicy(sizePolicy1);
        nicknameLineEditM->setMinimumSize(QSize(0, 0));
        nicknameLineEditM->setMaximumSize(QSize(16777215, 60));

        gridLayout_3->addWidget(nicknameLineEditM, 0, 2, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_3->addItem(verticalSpacer_4, 2, 3, 1, 1);

        passwordLineEditM = new QLineEdit(centralwidget);
        passwordLineEditM->setObjectName("passwordLineEditM");
        sizePolicy1.setHeightForWidth(passwordLineEditM->sizePolicy().hasHeightForWidth());
        passwordLineEditM->setSizePolicy(sizePolicy1);
        passwordLineEditM->setMinimumSize(QSize(0, 0));
        passwordLineEditM->setMaximumSize(QSize(16777215, 60));

        gridLayout_3->addWidget(passwordLineEditM, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 0, 3, 1, 1);

        nose_contra = new QPushButton(centralwidget);
        nose_contra->setObjectName("nose_contra");

        gridLayout_3->addWidget(nose_contra, 3, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout_3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
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
        label_2->setText(QCoreApplication::translate("MainWindow", "Si no tienes cuenta puedes", nullptr));
        registerLabel->setText(QCoreApplication::translate("MainWindow", "Registrarte", nullptr));
        loginButton->setText(QCoreApplication::translate("MainWindow", "Iniciar Sesi\303\263n", nullptr));
        nicknameLineEditM->setPlaceholderText(QCoreApplication::translate("MainWindow", "Nickname", nullptr));
        passwordLineEditM->setPlaceholderText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        nose_contra->setText(QCoreApplication::translate("MainWindow", "No se contrase\303\261a", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
