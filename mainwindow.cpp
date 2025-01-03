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
    qDebug() << "entra a la funcion on mainwindow.";
    // Conectar el botón "Registrar jugador" a la función para abrir RegisterWindow
    // Conectar el botón de la interfaz al slot openRegisterWindow()
    connect(ui->registerButtonM, &QPushButton::clicked, this, &MainWindow::openRegisterWindow);
    connect(ui->loginButton, &QPushButton::clicked, this, &MainWindow::login);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::openRegisterWindow() {
    RegisterWindow* registerWindow = new RegisterWindow();
    qDebug() << "entra a la funcion on register  window.";

    // Conectar la señal de RegisterWindow a la función que maneja el registro de jugadores en Connect4
    bool connected = connect(registerWindow, &RegisterWindow::registerPlayer, this, [=](const QString& nickName, const QString& email,
                                                                       const QString& password, const QDate& birthdate,
                                                                       int points, const QImage& avatar) {
        qDebug() << "Conexión recibida en MainWindow";

        // Llama a la función Connect4::registerPlayer
        Player* player = Connect4::getInstance().registerPlayer(nickName, email, password, birthdate, points);

        if (player) {
            QMessageBox::information(this, "Éxito", "Jugador registrado exitosamente.");
        } else {
            QMessageBox::critical(this, "Error", "No se pudo registrar el jugador.");
        }
    });
    if (connected) {
        qDebug() << "Conexión establecida correctamente.";
    } else {
        qCritical() << "Error: No se pudo establecer la conexión.";
    }
    // Mostrar la ventana de registro
    registerWindow->show();
    //registerWindow->deleteLater();
}

void MainWindow::login() {

    QString nickName = ui->nicknameLineEditM->text();
    QString passwordM = ui->passwordLineEditM->text();
    // Validar datos
    if (Connect4::getInstance().loginPlayer(nickName, passwordM)) {
        // Detener si los datos no son válidos
        qDebug() << "usuario valido.";
        return;
    }


}


