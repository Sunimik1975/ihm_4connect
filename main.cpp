#include "connect4.h"
#include "RegisterWindow.h"  // Asegúrate de incluir la clase RegisterWindow
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Crear la ventana principal
    MainWindow w;
    w.setWindowTitle("Entrega 4 en raya Grupo 2");

    // Usar la biblioteca Connect4Lib
    Connect4& game = Connect4::getInstance();

    // Registrar un jugador para prueba
    Player* player = game.registerPlayer("Player1", "player1@example.com", "Password123!", QDate(1990, 1, 1), 100);
    if (player) {
        qDebug() << "Jugador registrado:" << player->getNickName();
    }

    // Crear y mostrar la ventana de registro
    //RegisterWindow *registerWindow = new RegisterWindow();
    //registerWindow->show();  // Mostrar la ventana de registro

    // Mostrar la ventana principal
    w.show();

    return a.exec();  // Ejecutar el bucle de eventos de Qt
}
