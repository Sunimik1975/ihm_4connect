#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setJugadorConectado(const QString& jugador);
    QString jugadorConectado;      // Jugador que sigue conectado
    void setIsMultiplayer(bool multiplayer);


private slots:
    void openRegisterWindow(); // Slot para abrir la ventana de registro
    void login();

private:
    Ui::MainWindow *ui;
    QList<QString> activePlayers;  // Lista de jugadores activos
    //QString jugadorConectado;      // Jugador que sigue conectado
    bool isMultiplayer;  // Variable para almacenar si es multiplayer o no

};

#endif // MAINWINDOW_H
