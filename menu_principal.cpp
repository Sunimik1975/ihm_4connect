#include "menu_principal.h"
#include "Player.h"
#include "ui_menu_principal.h"
#include "mainwindow.h"   // Ventana para el modo multiplayer
#include "connect4.h"
#include <QMessageBox>
#include "gameboard.h"
#include "Connect4DAO.h"

Menu_principal::Menu_principal(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Menu_principal)
{
    ui->setupUi(this);

    // Conectar botones a las funciones correspondientes
    connect(ui->Singleplayer_button, &QPushButton::clicked, this, &Menu_principal::on_btnSinglePlayer_clicked);
    connect(ui->multiplayer_button, &QPushButton::clicked, this, &Menu_principal::on_btnMultiPlayer_clicked);
}

Menu_principal::~Menu_principal()
{
    delete ui;
}

void Menu_principal::on_btnSinglePlayer_clicked() {
    // Crear la instancia del juego
    Connect4& game = Connect4::getInstance();

    // Verificar si la máquina está registrada, si no, registrarla
    if (!game.existsNickName("Maquina")) {
        Player* maquina = game.registerPlayer("Maquina", "maquina@example.com", "Maquina123@", QDate(1990, 1, 1), 100);
        if (maquina) {
            qDebug() << "Jugador máquina registrado:" << maquina->getNickName();
        }
    } else {
        qDebug() << "La máquina ya está registrada.";
    }

    // Verificar si la máquina ya está logueada
    Player* maquina = game.loginPlayer("Maquina", "Maquina123@");
    if (maquina) {
        qDebug() << "Jugador máquina logeado:" << maquina->getNickName();
    } else {
        qDebug() << "Error al iniciar sesión con la máquina.";
    }

    // Crear y mostrar la ventana principal de juego
    MainWindow* mainWindow = new MainWindow(this);

    // Asumimos que la máquina será el oponente predeterminado
    mainWindow->setJugadorConectado("Maquina");

    // Mostrar la ventana principal
    mainWindow->show();

    // Ocultar el menú principal, pero no cerrarlo
    this->hide();
}


// Esta función lanza el juego en modo Multiplayer
void Menu_principal::on_btnMultiPlayer_clicked()
{
    // Crear la ventana principal para multiplayer
    MainWindow *mainWindow = new MainWindow(this);

    // Indicar que el juego es en modo multiplayer
    mainWindow->setIsMultiplayer(true);  // Le pasamos el estado a MainWindow

    // Mostrar la ventana principal
    mainWindow->show();

    // Ocultar el menú principal
    hide();
}
