/********************************************************************************
** Form generated from reading UI file 'RegisterWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RegisterWindow
{
public:
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *NickName;
    QLineEdit *nicknameLineEdit;
    QLabel *password;
    QLineEdit *passwordLineEdit;
    QLabel *email;
    QLineEdit *emailLineEdit;
    QLabel *fechadenacimiento;
    QDateEdit *birthdateEdit;
    QLabel *puntos;
    QSpinBox *pointsSpinBox;
    QSpacerItem *horizontalSpacer;
    QPushButton *registerButton;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *RegisterWindow)
    {
        if (RegisterWindow->objectName().isEmpty())
            RegisterWindow->setObjectName("RegisterWindow");
        RegisterWindow->resize(400, 314);
        verticalLayout_2 = new QVBoxLayout(RegisterWindow);
        verticalLayout_2->setObjectName("verticalLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        NickName = new QLabel(RegisterWindow);
        NickName->setObjectName("NickName");

        verticalLayout->addWidget(NickName);

        nicknameLineEdit = new QLineEdit(RegisterWindow);
        nicknameLineEdit->setObjectName("nicknameLineEdit");

        verticalLayout->addWidget(nicknameLineEdit);

        password = new QLabel(RegisterWindow);
        password->setObjectName("password");

        verticalLayout->addWidget(password);

        passwordLineEdit = new QLineEdit(RegisterWindow);
        passwordLineEdit->setObjectName("passwordLineEdit");

        verticalLayout->addWidget(passwordLineEdit);

        email = new QLabel(RegisterWindow);
        email->setObjectName("email");

        verticalLayout->addWidget(email);

        emailLineEdit = new QLineEdit(RegisterWindow);
        emailLineEdit->setObjectName("emailLineEdit");

        verticalLayout->addWidget(emailLineEdit);

        fechadenacimiento = new QLabel(RegisterWindow);
        fechadenacimiento->setObjectName("fechadenacimiento");

        verticalLayout->addWidget(fechadenacimiento);

        birthdateEdit = new QDateEdit(RegisterWindow);
        birthdateEdit->setObjectName("birthdateEdit");

        verticalLayout->addWidget(birthdateEdit);

        puntos = new QLabel(RegisterWindow);
        puntos->setObjectName("puntos");

        verticalLayout->addWidget(puntos);

        pointsSpinBox = new QSpinBox(RegisterWindow);
        pointsSpinBox->setObjectName("pointsSpinBox");

        verticalLayout->addWidget(pointsSpinBox);


        gridLayout->addLayout(verticalLayout, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 2, 1, 1);

        registerButton = new QPushButton(RegisterWindow);
        registerButton->setObjectName("registerButton");

        gridLayout->addWidget(registerButton, 2, 3, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);


        retranslateUi(RegisterWindow);

        QMetaObject::connectSlotsByName(RegisterWindow);
    } // setupUi

    void retranslateUi(QDialog *RegisterWindow)
    {
        RegisterWindow->setWindowTitle(QCoreApplication::translate("RegisterWindow", "Dialog", nullptr));
        NickName->setText(QCoreApplication::translate("RegisterWindow", "TextLabel", nullptr));
        password->setText(QCoreApplication::translate("RegisterWindow", "Password", nullptr));
        email->setText(QCoreApplication::translate("RegisterWindow", "Email", nullptr));
        fechadenacimiento->setText(QCoreApplication::translate("RegisterWindow", "Fecha de Nacimiento", nullptr));
        puntos->setText(QCoreApplication::translate("RegisterWindow", "Puntos", nullptr));
        registerButton->setText(QCoreApplication::translate("RegisterWindow", "Listo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterWindow: public Ui_RegisterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
