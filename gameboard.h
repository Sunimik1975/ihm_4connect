#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QWidget>
#include <QTimer>
#include <QListWidget>
#include <QListView>
#include <QStandardItemModel>


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
    void loadRanking();
    void resetGame();


public slots:
    //void showRanking();
    void on_modifyProfilePlayer2Button_clicked();
    //void showRounds();
    void on_modifyProfilePlayer1Button_clicked();
    void updatePlayerLabels();


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
    bool isMachinePlayer2 = false;
    bool gameOver;  // Variable para saber si el juego ha terminado
    // Nuevo atributo para indicar si el jugador 2 es una máquina
private:
    QListView* rankingListView;        // Reemplaza QListWidget con QListView
    QStandardItemModel* rankingModel; // Modelo para manejar los datos


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
