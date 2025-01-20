// MainWindow.cpp
#include "mainwindow.h"
#include "gameboard.h"
#include "ui_mainwindow.h"
#include "RegisterWindow.h"
#include "connect4.h"  // Asegúrate de incluir la clase Connect4
#include "rankingwindow.h"  // Include the RankingWindow header
#include <QMessageBox>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    //qDebug() << "entra a la funcion on mainwindow.";
    // Conectar el botón "Registrar jugador" a la función para abrir RegisterWindow
    // Conectar el botón de la interfaz al slot openRegisterWindow()
    connect(ui->registerButtonM, &QPushButton::clicked, this, &MainWindow::openRegisterWindow);
    connect(ui->loginButton, &QPushButton::clicked, this, &MainWindow::login);
    //connect(ui->rankingButton, &QPushButton::clicked, this, &MainWindow::showRanking);  // Connect the ranking button
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
        Connect4::getInstance().registerPlayer(nickName, email, password, birthdate, points,avatar);

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
void MainWindow::setJugadorConectado(const QString& jugador) {
    QString jugadorConectado = jugador;
    activePlayers.append(jugadorConectado);
    qDebug() << "Jugador que sigue conectado:" << jugadorConectado;

}


// Método para cambiar el modo de juego (multiplayer o singleplayer)
void MainWindow::setIsMultiplayer(bool multiplayer) {
    this->isMultiplayer = multiplayer;
}

// MainWindow.cpp

void MainWindow::login() {
    QString nickName = ui->nicknameLineEditM->text();
    QString passwordM = ui->passwordLineEditM->text();

    // Validar los datos del jugador
    if (Connect4::getInstance().loginPlayer(nickName, passwordM)) {
        QMessageBox::information(this, "Éxito", QString("%1 ha iniciado sesión.").arg(nickName));

        if (isMultiplayer) {
            // Verificar si ya hay 2 jugadores
            if (activePlayers.contains(nickName)) {
                QMessageBox::information(this, "Aviso", "Ya has iniciado sesión.");
                return;
            }

            activePlayers.append(nickName);

            if (activePlayers.size() == 2) {
                QString player1 = activePlayers.at(0);
                QString player2 = activePlayers.at(1);
                qDebug() << "hay dos jugadores";
                // Abrir el tablero de juego para dos jugadores
                GameBoard* gameBoard = new GameBoard(player1, player2);
                gameBoard->show();

                this->close(); // Cerrar la ventana principal
            } else {
                QMessageBox::information(this, "Esperando jugador", "Esperando que otro jugador inicie sesión.");
            }
        } else {
            // Lógica para el modo singleplayer
            GameBoard* gameBoard = new GameBoard(nickName, "Maquina");
            gameBoard->show();

            this->close();
        }
    } else {
        QMessageBox::warning(this, "Error", "El nombre de usuario o la contraseña son incorrectos.");
    }
}






