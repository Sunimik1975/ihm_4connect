#include "gameboard.h"
#include "build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug/ui_gameboard.h"
#include "mainwindow.h"
#include "ui_gameboard.h"
#include "connect4.h"
#include <cstdlib>


#include <QMouseEvent>
#include <QPainter>
#include <QtMath>
#include <QMessageBox>
#include <QInputDialog>
#include <QVBoxLayout>
#include <QThread>
GameBoard::GameBoard(const QString& player1, const QString& player2, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameBoard)
    , rows(6)
    , cols(7)
    , currentPlayer(1)
    , player1Name(player1)
    , player2Name(player2)
{
    ui->setupUi(this);
    grid.resize(rows, QVector<int>(cols, 0));
    setMinimumSize(cols * 40, rows * 40);

    qDebug() << "Jugador 1:" << player1Name << ", Jugador 2:" << player2Name;

    // Conectar botones
    connect(ui->cerrarPushButton, &QPushButton::clicked, this, &GameBoard::on_cerrarSesionButton_clicked);
    connect(ui->cerrarPushButton2, &QPushButton::clicked, this, &GameBoard::on_cerrarSesionButton_clicked);
}


GameBoard::~GameBoard()
{
    delete ui;
}


void GameBoard::on_cerrarSesionButton_clicked() {

    // Identificar qué botón fue presionado
    QPushButton* button = qobject_cast<QPushButton*>(sender());

    QString jugadorADesconectar;

    if (button == ui->cerrarPushButton) {
        jugadorADesconectar = player1Name;
        qDebug() << "Cerrar Sesión - Botón 1 presionado. Desconectando:" << player1Name;
    } else if (button == ui->cerrarPushButton2) {
        jugadorADesconectar = player2Name;
        qDebug() << "Cerrar Sesión - Botón 2 presionado. Desconectando:" << player2Name;
    } else {
        qDebug() << "Error: Botón desconocido.";
        return;
    }

    // Mostrar en la terminal que el jugador ha sido desconectado
    qDebug() << jugadorADesconectar << "ha sido desconectado.";

    // Determinar quién sigue conectado
    QString jugadorConectado = (jugadorADesconectar == player1Name) ? player2Name : player1Name;


    // Mostrar quién sigue conectado
    qDebug() << "El jugador que sigue conectado es:" << jugadorConectado;

    // Cerrar la ventana actual y abrir MainWindow
    MainWindow* mainWindow = new MainWindow();
    mainWindow->setJugadorConectado(jugadorConectado);
    mainWindow->show();

    // Cerrar la ventana de GameBoard
    this->close();

    // Solicitar el nombre del nuevo jugador
    //QString nuevoJugador = QInputDialog::getText(this, "Nuevo Jugador", "Introduce el nombre del nuevo jugador:");
/*
    if (!nuevoJugador.isEmpty()) {
        if(Connect4::getInstance().getPlayer(nuevoJugador)){
            if (jugadorADesconectar == player1Name) {
                player1Name = nuevoJugador;
            } else {
                player2Name = nuevoJugador;
            }

            // Mostrar en la terminal que el nuevo jugador se ha conectado
            qDebug() << nuevoJugador << "se ha conectado.";

            // Actualizar el tablero
            update();
        }
        else {
            qDebug() << "No existe ese jugador.";
        }
    } else {
        qDebug() << "No se ha conectado ningún nuevo jugador.";
    }*/

}



void GameBoard::actualizarJugadores(const QString& jugador1, const QString& jugador2) {
    player1Name = jugador1;
    player2Name = jugador2;

    qDebug() << "Jugadores actualizados: " << player1Name << " y " << player2Name;
}


void GameBoard::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    // a las posiciones (x,y) de cualquier punto se le suman la posicion (x0,y0) donde se pinta el centralQWidget sobre MainWindow
    QRect espacioJuego = geometry();

    // calcula el tamaño de la celda
    if (espacioJuego.width() / cols < espacioJuego.height() / rows) {
        cellSize = espacioJuego.width() / cols;
    } else {
        cellSize = espacioJuego.height() / rows;
    }
    int x0 = (espacioJuego.width() - (cellSize * cols)) / 2;
    int y0 = (espacioJuego.height() - (cellSize * rows)) / 2;

    // Dibujar la fondo
    painter.setBrush(Qt::gray);
    painter.drawRect(x0, y0, cellSize * cols, cellSize * rows);

    // Dibujar celdas
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            QRectF circleRect(x0 + (c * cellSize + 5),
                              y0 + (r * cellSize + 5),
                              cellSize - 10,
                              cellSize - 10);

            // Dependiendo del valor de grid[r][c], dibujamos el círculo correspondiente
            if (grid[r][c] == 0) {
                painter.setBrush(Qt::white);  // Celda vacía
            } else if (grid[r][c] == 1) {
                qDebug() <<"pinto rojo";
                painter.setBrush(Qt::red);    // Jugador 1
            } else if (grid[r][c] == 2){
                qDebug() <<"pinto amarillo";
                painter.setBrush(Qt::yellow); // Jugador 2
            }
            painter.drawEllipse(circleRect);
        }
    }
}




void GameBoard::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && currentPlayer <= 2) { // Solo permite interacción para Jugador 1 o Jugador 2
        int x = event->pos().x();
        QRect geom = geometry();
        int width = geom.width();
        int x0 = (width - (cols * cellSize)) / 2;

        int column = (x - x0) / cellSize;
        if (column >= 0 && column < cols) {
            int row;
            if (dropDisc(column, row)) {
                update();
            if (currentPlayer == 2 && player2Name == "Maquina") {
                    QTimer::singleShot(500, this, &GameBoard::machineMove);
            }
            else if(checkWin(row, column))
            {
                QString winnerName = (currentPlayer == 1) ? player1Name : player2Name;
                QString loserName  = (currentPlayer == 1) ? player2Name : player1Name;

                // Recupera los objetos Player de la base de datos
                Player* winnerPlayer = Connect4::getInstance().getPlayer(winnerName);
                Player* loserPlayer  = Connect4::getInstance().getPlayer(loserName);
                QMessageBox::information(this, "Éxito", QString("%1 PUUUUNTOS.").arg(winnerPlayer->getPoints()));
                // Incrementa los puntos del ganador (por ejemplo, +10)
                if (winnerPlayer) {
                    winnerPlayer->addPoints(10);
                    QMessageBox::information(this, "Éxito", QString("%1 PUNTOS.").arg(winnerPlayer->getPoints()));

                    // Guarda la modificación en la base de datos
                    // Se puede hacer con un método updatePlayer, según tu DAO
                    //Connect4::getInstance().updatePlayer(*winnerPlayer);
                }

                // Registrar la partida (round) en la base de datos (opcional)
                Connect4::getInstance().registerRound(
                QDateTime::currentDateTime(),
                winnerPlayer,
                loserPlayer
                );

                QMessageBox::information(
                    this,
                    "Victoria",
                    QString("¡Jugador %1 ha ganado!").arg(winnerName)
                    );

                return;
            }

                // Cambiar de jugador
                switchPlayer();
            } else {
                QMessageBox::warning(this, "Columna Llena", "La columna seleccionada está llena. Por favor, elige otra.");
            }
        }
    }

    // Turno automático de la máquina si es Jugador 2
    if (currentPlayer == 2 && player2Name == "Maquina") {
        QTimer::singleShot(500, this, &GameBoard::machineMove);
    }
}

void GameBoard::switchPlayer()
{
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
    QString nextPlayerName = (currentPlayer == 1) ? player1Name : player2Name;
    qDebug() << "Turno de" << nextPlayerName;
}


void GameBoard::machineMove()
{
    // Selecciona una columna aleatoria válida
    int column = -1;
    column = std::rand() % cols;  // Genera un número aleatorio entre 0 y cols-1
      // Asegúrate de que la columna no esté llena

    int row;
    if (dropDisc(column, row)) {
        update();

        // Verificar si el movimiento actual gana el juego
        if (checkWin(row, column)) {
            QString winnerName = (currentPlayer == 1) ? player1Name : player2Name;
            QString loserName  = (currentPlayer == 1) ? player2Name : player1Name;

            // Recupera los objetos Player de la base de datos
            Player* winnerPlayer = Connect4::getInstance().getPlayer(winnerName);
            Player* loserPlayer  = Connect4::getInstance().getPlayer(loserName);
            QMessageBox::information(this, "Éxito", QString("%1 PUUUUNTOS.").arg(winnerPlayer->getPoints()));
            // Incrementa los puntos del ganador (por ejemplo, +10)
            if (winnerPlayer) {
                winnerPlayer->addPoints(2);
                QMessageBox::information(this, "Éxito", QString("%1 PUNTOS.").arg(winnerPlayer->getPoints()));

                // Guarda la modificación en la base de datos
                // Se puede hacer con un método updatePlayer, según tu DAO
                //Connect4::getInstance().updatePlayer(*winnerPlayer);
            }

            // Registrar la partida (round) en la base de datos (opcional)
            Connect4::getInstance().registerRound(
                QDateTime::currentDateTime(),
                winnerPlayer,
                loserPlayer
                );

            QMessageBox::information(
                this,
                "Victoria",
                QString("¡Jugador %1 ha ganado!").arg(winnerName)
                );

            return;
        }

        // Cambiar de jugador
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
        QString nextPlayerName = (currentPlayer == 1) ? player1Name : player2Name;
        qDebug() << "Turno de" << nextPlayerName;
    }
}

bool GameBoard::dropDisc(int column, int &row)
{
    for (int r = rows - 1; r >= 0; --r) {
        if (grid[r][column] == 0) {
            grid[r][column] = currentPlayer;
            row = r;
            return true;
        }
    }
    return false; // Columna llena
}
bool GameBoard::checkWin(int row, int col)
{
    int player = grid[row][col];
    if(player == 0)
        return false;

    // Direcciones: horizontal, vertical, diagonal /, diagonal \*
    const QVector<QPair<int, int>> directions
        = {
            {0, 1}, {1, 0}, {1, 1}, {1, -1}
        };

    for(auto &dir : directions){
        int count = 1;

        // Dirección positiva
        int r = row + dir.first;
        int c = col + dir.second;
        while(r >=0 && r < rows && c >=0 && c < cols && grid[r][c] == player){
            count++;
            r += dir.first;
            c += dir.second;
        }

        // Dirección negativa
        r = row - dir.first;
        c = col - dir.second;
        while(r >=0 && r < rows && c >=0 && c < cols && grid[r][c] == player){
            count++;
            r -= dir.first;
            c -= dir.second;
        }

        if(count >=4)
            return true;
    }

    return false;
}
