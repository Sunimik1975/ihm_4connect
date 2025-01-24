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
    setFixedSize(this->size()); // Fija el tamaño actual de la ventana

    //qDebug() << "entra a la funcion on mainwindow.";
    // Conectar el botón "Registrar jugador" a la función para abrir RegisterWindow
    // Conectar el botón de la interfaz al slot openRegisterWindow()
    //ui->registerLabel = new ClickableLabel(this);  // Crear la instancia manualmente

    connect(ui->registerLabel, &QPushButton::clicked, this, &MainWindow::openRegisterWindow);
    connect(ui->loginButton, &QPushButton::clicked, this, &MainWindow::login);
    connect(ui->remember_password, &QPushButton::clicked, this, &MainWindow::Remember_contrasenya);

    //connect(ui->rankingButton, &QPushButton::clicked, this, &MainWindow::showRanking);  // Connect the ranking button
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::openRegisterWindow() {
    RegisterWindow* registerWindow = new RegisterWindow();
    qDebug() << "Entrando en la función openRegisterWindow.";

    // Conectar la señal de RegisterWindow al registro de jugadores en Connect4
    bool connected = connect(registerWindow, &RegisterWindow::registerPlayer, this, [=](const QString& nickName, const QString& email,
                                                                                        const QString& password, const QDate& birthdate,
                                                                                        int points, const QImage& avatar) {
        // Llamar a la función Connect4::registerPlayer
        if (!Connect4::getInstance().existsNickName(nickName)) {
            Player* player = Connect4::getInstance().registerPlayer(nickName, email, password, birthdate, points, avatar);
            if (player) {
                qDebug() << "Jugador registrado exitosamente.";
            } else {
                qCritical() << "Error al registrar el jugador.";
            }
        } else {
            qWarning() << "El nickname ya existe. No se puede registrar nuevamente.";
        }
    });

    if (connected) {
        qDebug() << "Conexión establecida correctamente.";
    } else {
        qCritical() << "Error: No se pudo establecer la conexión.";
    }

    // Mostrar la ventana de registro
    registerWindow->show();
}

void MainWindow::setJugadorConectado(const QString& jugador) {
    QString jugadorConectado = jugador;
    activePlayers.append(jugadorConectado);
    qDebug() << "Jugador que sigue conectado:" << jugadorConectado;

}


// Método para cambiar el modo de juego (multiplayer o singleplayer)
void MainWindow::setIsMultiplayer(bool multiplayer) {
    qDebug() << "ESTAMOS EN MULTIPLAYER funcion";
    this->isMultiplayer = multiplayer;
}

// MainWindow.cpp

void MainWindow::login() {
    QString nickName = ui->nicknameLineEditM->text();
    QString passwordM = ui->passwordLineEditM->text();

    // Validar los datos del jugador
    if (Connect4::getInstance().loginPlayer(nickName, passwordM)) {
        //QMessageBox::information(this, "Éxito", QString("%1 ha iniciado sesión.").arg(nickName));

        // Limpiar los campos de texto después del login exitoso
        ui->nicknameLineEditM->clear();
        ui->passwordLineEditM->clear();

        if (isMultiplayer) {
            qDebug() << "ESTAMOS EN MULTIPLAYER funcion";
            // Verificar si ya hay 2 jugadores
            if (activePlayers.contains(nickName)) {
                //QMessageBox::information(this, "Aviso", "Ya has iniciado sesión.");
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
            qDebug() << "ESTAMOS EN Singleplayer";
            // Lógica para el modo singleplayer
            GameBoard* gameBoard = new GameBoard(nickName, "Maquina");
            gameBoard->show();

            this->close();
        }
    } else {
        QMessageBox::warning(this, "Error", "El nombre de usuario o la contraseña son incorrectos.");
    }
}



#include <QInputDialog>
#include <cstdlib>  // Para generar números aleatorios
#include <ctime>    // Para inicializar la semilla aleatoria

void MainWindow::Remember_contrasenya() {
    // Solicitar nombre de usuario
    QString username = QInputDialog::getText(this, "Recuperar contraseña", "Introduce tu nombre de usuario:");
    if (username.isEmpty()) {
        QMessageBox::warning(this, "Error", "El nombre de usuario no puede estar vacío.");
        return;
    }

    // Solicitar correo electrónico
    QString email = QInputDialog::getText(this, "Recuperar contraseña", "Introduce tu correo electrónico:");
    if (email.isEmpty()) {
        QMessageBox::warning(this, "Error", "El correo electrónico no puede estar vacío.");
        return;
    }

    // Verificar si el usuario y correo coinciden en el sistema
    Player* player = Connect4::getInstance().getPlayer(username);
    if (!player || player->getEmail() != email) {
        QMessageBox::warning(this, "Error", "El usuario o correo electrónico no coinciden con los registros.");
        return;
    }

    // Generar un código de seguridad aleatorio
    std::srand(std::time(0));  // Inicializar la semilla aleatoria
    int securityCode = std::rand() % 900000 + 100000;  // Generar un número de 6 dígitos
    QString codeString = QString::number(securityCode);

    // Simular el envío del código de seguridad
    QMessageBox::information(this, "Código de seguridad", QString("Tu código de seguridad es: %1").arg(codeString));

    // Solicitar el código de seguridad al usuario
    QString enteredCode = QInputDialog::getText(this, "Verificar código de seguridad", "Introduce el código de seguridad que recibiste:");
    if (enteredCode.isEmpty() || enteredCode != codeString) {
        QMessageBox::warning(this, "Error", "El código de seguridad es incorrecto o no coincide.");
        return;
    }

    // Mostrar la contraseña al usuario
    QString password = player->getPassword();
    QMessageBox::information(this, "Recuperación exitosa", QString("Tu contraseña es: %1").arg(password));
}
