/********************************************************************************
** Form generated from reading UI file 'rounds.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROUNDS_H
#define UI_ROUNDS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_rounds
{
public:
    QGridLayout *gridLayout;
    QPushButton *buscar_filtro;
    QDateEdit *startDateEdit;
    QPushButton *ganadas;
    QPushButton *perdidas;
    QDateEdit *endDateEdit;
    QPushButton *jugador_tiempo;
    QLabel *label_2;
    QLabel *label;
    QTableView *tableView;

    void setupUi(QDialog *rounds)
    {
        if (rounds->objectName().isEmpty())
            rounds->setObjectName("rounds");
        rounds->resize(400, 300);
        gridLayout = new QGridLayout(rounds);
        gridLayout->setObjectName("gridLayout");
        buscar_filtro = new QPushButton(rounds);
        buscar_filtro->setObjectName("buscar_filtro");

        gridLayout->addWidget(buscar_filtro, 3, 1, 1, 1);

        startDateEdit = new QDateEdit(rounds);
        startDateEdit->setObjectName("startDateEdit");

        gridLayout->addWidget(startDateEdit, 0, 1, 1, 1);

        ganadas = new QPushButton(rounds);
        ganadas->setObjectName("ganadas");

        gridLayout->addWidget(ganadas, 5, 1, 1, 1);

        perdidas = new QPushButton(rounds);
        perdidas->setObjectName("perdidas");

        gridLayout->addWidget(perdidas, 6, 1, 1, 1);

        endDateEdit = new QDateEdit(rounds);
        endDateEdit->setObjectName("endDateEdit");

        gridLayout->addWidget(endDateEdit, 2, 1, 1, 1);

        jugador_tiempo = new QPushButton(rounds);
        jugador_tiempo->setObjectName("jugador_tiempo");

        gridLayout->addWidget(jugador_tiempo, 4, 1, 1, 1);

        label_2 = new QLabel(rounds);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label = new QLabel(rounds);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        tableView = new QTableView(rounds);
        tableView->setObjectName("tableView");

        gridLayout->addWidget(tableView, 7, 0, 1, 2);


        retranslateUi(rounds);

        QMetaObject::connectSlotsByName(rounds);
    } // setupUi

    void retranslateUi(QDialog *rounds)
    {
        rounds->setWindowTitle(QCoreApplication::translate("rounds", "Dialog", nullptr));
        buscar_filtro->setText(QCoreApplication::translate("rounds", "todas las partidas", nullptr));
        ganadas->setText(QCoreApplication::translate("rounds", "ganadas", nullptr));
        perdidas->setText(QCoreApplication::translate("rounds", "perdidas", nullptr));
        jugador_tiempo->setText(QCoreApplication::translate("rounds", "Partidas jugador/tiempo", nullptr));
        label_2->setText(QCoreApplication::translate("rounds", "fin", nullptr));
        label->setText(QCoreApplication::translate("rounds", "Inicio", nullptr));
    } // retranslateUi

};

namespace Ui {
    class rounds: public Ui_rounds {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROUNDS_H
