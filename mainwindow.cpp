// MainWindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "RegisterWindow.h"
#include "Connect4.h"  // Asegúrate de incluir la clase Connect4
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Conectar el botón "Registrar jugador" a la función para abrir RegisterWindow
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::openRegisterWindow() {
    // Crear la ventana de registro
    RegisterWindow *registerWindow = new RegisterWindow();

    // Conectar la señal registerPlayer a la función de registro en Connect4
    connect(registerWindow, &RegisterWindow::registerPlayer, this, [=](const QString &nickName, const QString &email,
                                                                       const QString &password, const QDate &birthdate, int points) {
        // Aquí se pasa la señal a Connect4 para el registro del jugador
        Player* player = Connect4::getInstance().registerPlayer(nickName, email, password, birthdate, points);

        if (player) {
            QMessageBox::information(this, "Éxito", "Jugador registrado exitosamente.");
        } else {
            QMessageBox::critical(this, "Error", "No se pudo registrar el jugador.");
        }
    });

    // Mostrar la ventana de registro
    registerWindow->show();
}
