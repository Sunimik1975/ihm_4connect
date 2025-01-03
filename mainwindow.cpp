// MainWindow.cpp
#include "mainwindow.h"
#include "gameboard.h"
#include "ui_mainwindow.h"
#include "RegisterWindow.h"
#include "Connect4.h"  // Asegúrate de incluir la clase Connect4
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    //qDebug() << "entra a la funcion on mainwindow.";
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
        //qDebug() << "Conexión recibida en MainWindow";

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
        //qDebug() << "usuario valido.";
<<<<<<< HEAD
        QMessageBox::information(this, "Éxito", QString("%1 ha iniciado sesión.").arg(nickName));

        // Agregar el jugador a la lista de jugadores activos
        activePlayers.append(nickName);

        if (activePlayers.size() >= 2) {
            QString player1 = activePlayers.at(0);
            QString player2 = activePlayers.at(1);

            // Crear y mostrar la ventana del tablero de juego
            GameBoard* gameBoard = new GameBoard(player1, player2);
            gameBoard->show();

            // Cerrar la ventana principal
            this->close();
        }

=======
        return;
>>>>>>> 3555011f08e3e22df8b5db64ecb8385aedb16479
    }


}


