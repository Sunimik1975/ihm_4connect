// MainWindow.cpp
#include "mainwindow.h"
#include "gameboard.h"
#include "ui_mainwindow.h"
#include "RegisterWindow.h"
#include "connect4.h"  // Asegúrate de incluir la clase Connect4
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
void MainWindow::login() {
    QString nickName = ui->nicknameLineEditM->text();
    QString passwordM = ui->passwordLineEditM->text();

    qDebug() << "Tamaño de activePlayers antes del if:" << activePlayers.size();
    qDebug() << "Contenido de activePlayers:" << activePlayers;
    qDebug() << "Contenido de activePlayers:" << jugadorConectado;
    // Validar datos
    if (Connect4::getInstance().loginPlayer(nickName, passwordM)) {
        QMessageBox::information(this, "Éxito", QString("%1 ha iniciado sesión.").arg(nickName));

        // Comprobar si hay un jugador conectado
        if (activePlayers.size() == 1) {
            qDebug() << "Entrano al primewr if, es decir si hay un jugador activo" ;
            // Si ya hay un jugador conectado, solo se agrega el nuevo jugador
            QString jugadorExistente = activePlayers.at(0);
            activePlayers.clear();
            activePlayers.append(jugadorExistente);
            activePlayers.append(nickName);
        } else {
            qDebug() << "Entrano al primewr if, es decir NO hay un jugador activo" ;
            // Si no hay jugadores conectados, agregar ambos jugadores

            activePlayers.append(nickName);
            qDebug() << "Contenido de activePlayers:" << activePlayers;
        }

        // Crear y mostrar la ventana del tablero de juego
        if (activePlayers.size() == 2) {
            qDebug() << "Entra directame" ;
            QString player1 = activePlayers.at(0);
            QString player2 = activePlayers.at(1);
            qDebug() << "Contenido de activePlayers:" << activePlayers;

            GameBoard* gameBoard = new GameBoard(player1, player2);
            gameBoard->show();

            // Cerrar la ventana principal
            this->close();
        }

        return;
    }
}



