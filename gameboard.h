#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class GameBoard;
}

class GameBoard : public QWidget
{
    Q_OBJECT

public:
    explicit GameBoard(const QString &player1, const QString &player2, QWidget *parent = nullptr);
    ~GameBoard();
    void machineMove();
    void switchPlayer();
    void showRanking();




protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private slots:
    void on_cerrarSesionButton_clicked();

private:
    Ui::GameBoard *ui;
    int rows;
    int cols;
    int cellSize;
    int currentPlayer;
    bool isMachinePlayer2 = false;  // Nuevo atributo para indicar si el jugador 2 es una máquina


    QVector<QVector<int>> grid;

    QString player1Name;
    QString player2Name;

    void cerrarSesion();
    bool dropDisc(int column, int &row);
    bool checkWin(int row, int col);
    void actualizarJugadores(const QString& jugador1, const QString& jugador2);
    void turnoMaquina();
    // Variables para la animación
    bool isAnimating;
    int animColumn;
    int animTargetRow;
    double animY; // Posición Y actual de la ficha en la animación
    int animPlayer; // Jugador que está animando
    QTimer animationTimer;
    void startAnimation(int column, int player);
};

#endif // GAMEBOARD_H
