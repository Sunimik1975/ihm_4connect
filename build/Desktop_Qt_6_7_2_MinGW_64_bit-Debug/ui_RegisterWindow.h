/********************************************************************************
** Form generated from reading UI file 'RegisterWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RegisterWindow
{
public:
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_4;
    QLineEdit *passwordLineEdit;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_9;
    QSpacerItem *verticalSpacer_11;
    QPushButton *registerButton;
    QSpacerItem *verticalSpacer_8;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QDateEdit *birthdateEdit;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *nicknameLineEdit;
    QSpacerItem *verticalSpacer_10;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QComboBox *avatarCombo;
    QLabel *avatarLabel;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_12;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_6;
    QLineEdit *emailLineEdit;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *verticalSpacer_13;
    QSpacerItem *verticalSpacer_14;

    void setupUi(QDialog *RegisterWindow)
    {
        if (RegisterWindow->objectName().isEmpty())
            RegisterWindow->setObjectName("RegisterWindow");
        RegisterWindow->resize(457, 446);
        verticalLayout_2 = new QVBoxLayout(RegisterWindow);
        verticalLayout_2->setObjectName("verticalLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 4, 0, 1, 1);

        passwordLineEdit = new QLineEdit(RegisterWindow);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setMinimumSize(QSize(0, 60));
        passwordLineEdit->setMaximumSize(QSize(16777215, 60));

        gridLayout->addWidget(passwordLineEdit, 1, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 3, 0, 1, 1);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_9, 3, 2, 1, 1);

        verticalSpacer_11 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_11, 6, 2, 1, 1);

        registerButton = new QPushButton(RegisterWindow);
        registerButton->setObjectName("registerButton");
        registerButton->setMinimumSize(QSize(0, 60));

        gridLayout->addWidget(registerButton, 6, 1, 1, 1);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_8, 2, 2, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        label = new QLabel(RegisterWindow);
        label->setObjectName("label");
        label->setMinimumSize(QSize(0, 10));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(label, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 0, 1, 1);

        birthdateEdit = new QDateEdit(RegisterWindow);
        birthdateEdit->setObjectName("birthdateEdit");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(birthdateEdit->sizePolicy().hasHeightForWidth());
        birthdateEdit->setSizePolicy(sizePolicy);
        birthdateEdit->setMinimumSize(QSize(0, 50));
        birthdateEdit->setStyleSheet(QString::fromUtf8("font: 9pt \"Segoe UI\";"));
        birthdateEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(birthdateEdit, 2, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 2, 1, 1);


        gridLayout->addLayout(gridLayout_2, 3, 1, 1, 1);

        nicknameLineEdit = new QLineEdit(RegisterWindow);
        nicknameLineEdit->setObjectName("nicknameLineEdit");
        nicknameLineEdit->setMinimumSize(QSize(0, 60));
        nicknameLineEdit->setMaximumSize(QSize(16777215, 60));

        gridLayout->addWidget(nicknameLineEdit, 0, 1, 1, 1);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_10, 4, 2, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 0, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 0, 0, 1, 1);

        avatarCombo = new QComboBox(RegisterWindow);
        avatarCombo->setObjectName("avatarCombo");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(avatarCombo->sizePolicy().hasHeightForWidth());
        avatarCombo->setSizePolicy(sizePolicy1);
        avatarCombo->setMinimumSize(QSize(0, 50));
        avatarCombo->setMaximumSize(QSize(16777215, 50));

        gridLayout_3->addWidget(avatarCombo, 1, 1, 1, 1);

        avatarLabel = new QLabel(RegisterWindow);
        avatarLabel->setObjectName("avatarLabel");
        avatarLabel->setMinimumSize(QSize(0, 10));
        avatarLabel->setMaximumSize(QSize(16777215, 10));
        avatarLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(avatarLabel, 0, 1, 1, 1);


        gridLayout->addLayout(gridLayout_3, 4, 1, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 6, 0, 1, 1);

        verticalSpacer_12 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_12, 2, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_6, 0, 2, 1, 1);

        emailLineEdit = new QLineEdit(RegisterWindow);
        emailLineEdit->setObjectName("emailLineEdit");
        emailLineEdit->setMinimumSize(QSize(0, 60));
        emailLineEdit->setMaximumSize(QSize(16777215, 60));

        gridLayout->addWidget(emailLineEdit, 2, 1, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_7, 1, 2, 1, 1);

        verticalSpacer_13 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_13, 5, 0, 1, 1);

        verticalSpacer_14 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_14, 5, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout);


        retranslateUi(RegisterWindow);

        QMetaObject::connectSlotsByName(RegisterWindow);
    } // setupUi

    void retranslateUi(QDialog *RegisterWindow)
    {
        RegisterWindow->setWindowTitle(QCoreApplication::translate("RegisterWindow", "Dialog", nullptr));
        passwordLineEdit->setPlaceholderText(QCoreApplication::translate("RegisterWindow", "Password", nullptr));
        registerButton->setText(QCoreApplication::translate("RegisterWindow", "Crear Cuenta", nullptr));
        label->setText(QCoreApplication::translate("RegisterWindow", "Fecha de nacimiento", nullptr));
        nicknameLineEdit->setPlaceholderText(QCoreApplication::translate("RegisterWindow", "Nickname", nullptr));
        avatarLabel->setText(QCoreApplication::translate("RegisterWindow", "Seleccionar Avatar", nullptr));
        emailLineEdit->setPlaceholderText(QCoreApplication::translate("RegisterWindow", "Correo electr\303\263nico", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterWindow: public Ui_RegisterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
