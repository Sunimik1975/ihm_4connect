#include "gameboard.h"
//#include "build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug/ui_gameboard.h"
#include "connect4.h"
#include "mainwindow.h"
#include "menu_principal.h"
#include "rankingwindow.h"
#include "RegisterWindow.h"
#include "rounds.h"
#include "ui_RegisterWindow.h"
#include "ui_gameboard.h"
#include <cstdlib>
#include "Player.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QMouseEvent>
#include <QPainter>
#include <QThread>
#include <QVBoxLayout>
#include <QtMath>
#include "iconcombobox.h"
#include "ui_mainwindow.h"


GameBoard::GameBoard(const QString &player1, const QString &player2, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameBoard)
    , rows(6)
    , cols(7)
    , currentPlayer(1)
    , player1Name(player1)
    , player2Name(player2)  // Configurar turno inicial

{
    ui->setupUi(this);
    // Crear el tablero dentro del layout de la UI
    gameOver = false;  // El juego no ha terminado al inicio



    grid.resize(rows, QVector<int>(cols, 0));
    setMinimumSize(cols * 40, rows * 40);

    qDebug() << "Jugador 1:" << player1Name << ", Jugador 2:" << player2Name;

    // Conectar botones
    connect(ui->cerrarPushButton,&QPushButton::clicked, this, &GameBoard::on_cerrarSesionButton_clicked);
    connect(ui->cerrarPushButton2, &QPushButton::clicked, this, &GameBoard::on_cerrarSesionButton_clicked);
    //connect(ui->rankingbutton, &QPushButton::clicked, this, &GameBoard::showRanking);
    connect(ui->modifyProfileButton2, &QPushButton::clicked, this, &GameBoard::on_modifyProfilePlayer2Button_clicked);
    connect(ui->modifyProfileButton1, &QPushButton::clicked, this, &GameBoard::on_modifyProfilePlayer1Button_clicked);
    connect(ui->reset, &QPushButton::clicked, this, &GameBoard::resetGame);

    //connect(ui->Mostrar_rounds, &QPushButton::clicked, this, &GameBoard::showRounds);

}

GameBoard::~GameBoard()
{
    delete ui;
}

void GameBoard::updatePlayerLabels() {
    // Actualizar nombre
    ui->label_player1_name->setText(player1Name);
    ui->label_player2_name->setText(player2Name);

    // Actualizar puntos (suponiendo que tienes un método getPoints para obtener los puntos de cada jugador)
    Player* player1 = Connect4::getInstance().getPlayer(player1Name);
    Player* player2 = Connect4::getInstance().getPlayer(player2Name);

    if (player1) {
        ui->label_player1_points->setText(QString("Puntos: %1").arg(player1->getPoints()));
        QPixmap avatarPixmap = QPixmap::fromImage(player1->getAvatar()).scaled(100, 100, Qt::KeepAspectRatio);
        ui->label_player1_avatar->setPixmap(avatarPixmap);
    }

    if (player2) {
        ui->label_player2_points->setText(QString("Puntos: %1").arg(player2->getPoints()));
        QPixmap avatarPixmap = QPixmap::fromImage(player2->getAvatar()).scaled(100, 100, Qt::KeepAspectRatio);
        ui->label_player2_avatar->setPixmap(avatarPixmap);
    }
}

void GameBoard::on_cerrarSesionButton_clicked() {

    // Identificar qué botón fue presionado
    QPushButton* button = qobject_cast<QPushButton*>(sender());

    QString jugadorADesconectar;

    if (button == ui->cerrarPushButton) {
        jugadorADesconectar = player1Name;
        QMessageBox::information(this, "Desconexión", jugadorADesconectar + " se ha desconectado.");
    } else if (button == ui->cerrarPushButton2) {
        jugadorADesconectar = player2Name;
        QMessageBox::information(this, "Desconexión", jugadorADesconectar + " se ha desconectado.");
    } else {
        QMessageBox::warning(this, "Error", "Botón desconocido. No se puede desconectar.");
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
    if (player1Name == "Maquina" || player2Name == "Maquina"){
        mainWindow->setIsMultiplayer(false);
    }
    else{
        mainWindow->setIsMultiplayer(true);

    }
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
void GameBoard::actualizarJugadores(const QString &jugador1, const QString &jugador2)
{
    player1Name = jugador1;
    player2Name = jugador2;

    qDebug() << "Jugadores actualizados: " << player1Name << " y " << player2Name;
}
void GameBoard::cellWidthHeight(int &cellWidth, int &cellHeight) {
    QRect espacioJuego = geometry();
    int controlHeight = ui->modifyProfileButton1->height() + ui->reset->height() +60; // Altura de controles + margen
    int drawAreaHeight = espacioJuego.height() - controlHeight;
    int drawAreaWidth = espacioJuego.width();

    // Calcular el tamaño de cada celda
    cellWidth = drawAreaWidth / cols;
    cellHeight = drawAreaHeight / rows;
}

void GameBoard::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QRect espacioJuego = geometry();
    int cellWidth, cellHeight;
    cellWidthHeight(cellWidth, cellHeight);

    // Elegir el tamaño uniforme de la celda
    cellSize = qMin(cellWidth, cellHeight);

    // Coordenadas iniciales para centrar el tablero
    int x0 = (espacioJuego.width() - (cellSize * cols)) / 2;
    int y0 = (espacioJuego.height() - (cellSize * rows)) / 2;
    //Menu_principal menu;
    //bool isEnabled = Menu_principal::isHighContrastEnabled();
    //Menu_principal::setHighContrastEnabled(true); // Activar alto contraste
    bool isEnabled = Menu_principal::isHighContrastEnabled(); // Consultar estado

    qDebug() << "oscuro" << isEnabled;
    // Elegir colores basados en isEnabled
    QColor fondoTablero, celdaVacia, jugador1, jugador2;
    if (isEnabled) {
        fondoTablero = QColor(40, 40, 40); // Gris oscuro para el fondo del tablero
        celdaVacia = QColor(30, 30, 30);   // Gris más oscuro para celdas vacías
        jugador1 = QColor(236, 72, 85);   // Rojo
        jugador2 = QColor(34, 197, 189);  // Verde azulado
    } else {
        fondoTablero = QColor(245, 245, 245); // Blanco grisáceo
        celdaVacia = QColor(220, 220, 220);   // Gris claro
        jugador1 = QColor(220, 38, 38);       // Rojo intenso
        jugador2 = QColor(6, 182, 212);       // Azul brillante
    }

    // Dibujar el fondo del tablero
    painter.setBrush(fondoTablero);
    painter.drawRect(x0, y0, cellSize * cols, cellSize * rows);

    // Dibujar celdas
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            QRectF circleRect(x0 + (c * cellSize + 5),
                              y0 + (r * cellSize + 5),
                              cellSize - 10,
                              cellSize - 10);

            // Colores basados en el estado de la celda
            if (grid[r][c] == 0) {
                painter.setBrush(celdaVacia); // Color para celdas vacías
            } else if (grid[r][c] == 1) {
                painter.setBrush(jugador1);  // Color para jugador 1
                painter.drawEllipse(circleRect);
                // Añadir un punto blanco en el centro del círculo rojo
                painter.setBrush(Qt::white);
                QRectF centerPoint(circleRect.center().x() - 2,
                                   circleRect.center().y() - 2,
                                   4, 4);
                painter.drawEllipse(centerPoint);
                continue;
            } else if (grid[r][c] == 2) {
                painter.setBrush(jugador2);  // Color para jugador 2
            }
            painter.drawEllipse(circleRect);
        }
    }
}



void GameBoard::resetGame() {
    // Restaura el estado del juego
    gameOver = false;

    // Reinicia el tablero (vacía todas las posiciones)
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            grid[i][j] = 0; // Vacía la celda (o el valor inicial)
        }
    }
    void paintEvent();
    // Llama a repaint() para redibujar el tablero
    update();
}


void GameBoard::mousePressEvent(QMouseEvent *event)
{
    if (gameOver){
        return;
    }else{
        if (event->button() == Qt::LeftButton
            && currentPlayer <= 2) { // Solo permite interacción para Jugador 1 o Jugador 2
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
                    } else if (checkWin(row, column)) {
                        QString winnerName = (currentPlayer == 1) ? player1Name : player2Name;
                        QString loserName = (currentPlayer == 1) ? player2Name : player1Name;

                        // Recupera los objetos Player de la base de datos
                        Player *winnerPlayer = Connect4::getInstance().getPlayer(winnerName);
                        Player *loserPlayer = Connect4::getInstance().getPlayer(loserName);

                        /*QMessageBox::information(this,
                                                 "Éxito",
                                                 QString("%1 PUUUUNTOS.").arg(winnerPlayer->getPoints());*/
                        // Incrementa los puntos del ganador (por ejemplo, +10)
                        if (winnerPlayer) {
                            winnerPlayer->addPoints(40);
                            QMessageBox::information(this,
                                                     "Éxito",
                                                     QString("%1 PUNTOS.")
                                                         .arg(winnerPlayer->getPoints()));

                            // Guarda la modificación en la base de datos
                            // Se puede hacer con un método updatePlayer, según tu DAO
                            //Connect4::getInstance().updatePlayer(*winnerPlayer);
                        }

                        // Registrar la partida (round) en la base de datos (opcional)
                        Connect4::getInstance().registerRound(QDateTime::currentDateTime(),
                                                              winnerPlayer,
                                                              loserPlayer);

                        QMessageBox::information(this,
                                                 "Victoria",
                                                 QString("¡Jugador %1 ha ganado!").arg(winnerName));

                        return;
                    }

                    // Cambiar de jugador
                    switchPlayer();
                } else {
                    /*QMessageBox::warning(this,
                                         "Columna Llena",
                                         "La columna seleccionada está llena. Por favor, elige otra.");*/
                }
            }
        }
    }
    // Turno automático de la máquina si es Jugador 2
    if (currentPlayer == 2 && player2Name == "Maquina") {
        QTimer::singleShot(500, this, &GameBoard::machineMove);
    }
}
void GameBoard::updateTurnDisplay() {
    // Cambiar los colores según el jugador actual
    if (currentPlayer == 1) {
        ui->label_player1_name->setStyleSheet("color: black;");  // Color para jugador 1
        ui->label_player2_name->setStyleSheet("color: red;");    // Color para jugador 2
    } else if (currentPlayer == 2) {
        ui->label_player2_name->setStyleSheet("color: black;");  // Color para jugador 2
        ui->label_player1_name->setStyleSheet("color: blue;");   // Color para jugador 1
    }
}

void GameBoard::switchPlayer()
{
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
    QString nextPlayerName = (currentPlayer == 1) ? player1Name : player2Name;

    // Cambiar los colores de las etiquetas según el jugador actual
    if (nextPlayerName == player2Name) {
        ui->label_player1_name->setStyleSheet("color: black;");  // Color para jugador 1
        ui->label_player2_name->setStyleSheet("color: blue;");    // Color para jugador 2
    } else if (nextPlayerName == player1Name) {
        ui->label_player2_name->setStyleSheet("color: black;");  // Color para jugador 2
        ui->label_player1_name->setStyleSheet("color: red;");   // Color para jugador 1
    }

    // Actualiza las etiquetas con la información más reciente de los jugadores
    updatePlayerLabels();

    qDebug() << "Turno de" << nextPlayerName;

    // Llamar a la función que actualiza el turno en la interfaz si es necesario
    // updateTurnDisplay();

}

void GameBoard::machineMove()
{
    // Selecciona una columna aleatoria válida
    int column = -1;
    column = std::rand() % cols; // Genera un número aleatorio entre 0 y cols-1
        // Asegúrate de que la columna no esté llena

    int row;
    if (dropDisc(column, row)) {
        update();

        // Verificar si el movimiento actual gana el juego
        if (checkWin(row, column)) {
            QString winnerName = (currentPlayer == 1) ? player1Name : player2Name;
            QString loserName = (currentPlayer == 1) ? player2Name : player1Name;

            // Recupera los objetos Player de la base de datos
            Player *winnerPlayer = Connect4::getInstance().getPlayer(winnerName);
            Player *loserPlayer = Connect4::getInstance().getPlayer(loserName);
            /*QMessageBox::information(this,
                                     "Éxito",
                                     QString("%1 PUUUUNTOS.").arg(winnerPlayer->getPoints()));*/
            // Incrementa los puntos del ganador (por ejemplo, +10)
            if (winnerPlayer) {
                winnerPlayer->addPoints(2);
                QMessageBox::information(this,
                                         "Éxito",
                                         QString("%1 PUNTOS.").arg(winnerPlayer->getPoints()));

                // Guarda la modificación en la base de datos
                // Se puede hacer con un método updatePlayer, según tu DAO
                //Connect4::getInstance().updatePlayer(*winnerPlayer);
            }

            // Registrar la partida (round) en la base de datos (opcional)
            Connect4::getInstance().registerRound(QDateTime::currentDateTime(),
                                                  winnerPlayer,
                                                  loserPlayer);

            QMessageBox::information(this,
                                     "Victoria",
                                     QString("¡Jugador %1 ha ganado!").arg(winnerName));

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
    if (player == 0)
        return false;

    // Direcciones: horizontal, vertical, diagonal /, diagonal \*
    const QVector<QPair<int, int>> directions = {{0, 1}, {1, 0}, {1, 1}, {1, -1}};

    for (auto &dir : directions) {
        int count = 1;

        // Dirección positiva
        int r = row + dir.first;
        int c = col + dir.second;
        while (r >= 0 && r < rows && c >= 0 && c < cols && grid[r][c] == player) {
            count++;
            r += dir.first;
            c += dir.second;
        }

        // Dirección negativa
        r = row - dir.first;
        c = col - dir.second;
        while (r >= 0 && r < rows && c >= 0 && c < cols && grid[r][c] == player) {
            count++;
            r -= dir.first;
            c -= dir.second;
        }

        if (count >= 4){
            gameOver = true;
            return true;
        }
    }

    return false;
}
/*
void GameBoard::showRanking()
{
    rankingwindow *rankingWindow = new rankingwindow();

    rankingWindow->show();
}

void GameBoard::showRounds()
{
    rounds *roundsDialog = new rounds(this); // Crea un diálogo de la clase rounds
    roundsDialog->show(); // Muestra el diálogo
}
*/

void GameBoard::on_modifyProfilePlayer2Button_clicked() {
    Player* player2 = Connect4::getInstance().getPlayer(player2Name);
    if (!player2) {
        QMessageBox::warning(this, "Error", "No se encontró al jugador 2.");
        return;
    }

    RegisterWindow* registerWindow = new RegisterWindow();
    Ui::RegisterWindow* ui = registerWindow->getUi();

    // Rellenar campos con los datos actuales del jugador
    ui->nicknameLineEdit->setText(player2->getNickName());
    ui->emailLineEdit->setText(player2->getEmail());
    ui->birthdateEdit->setDate(player2->getBirthdate());

    // Deshabilitar edición del nickname
    ui->nicknameLineEdit->setEnabled(false);

    // Conectar la señal personalizada para guardar cambios
    connect(registerWindow, &RegisterWindow::registerPlayer, this, [=](const QString&, const QString& email, const QString& password, const QDate& birthdate, int, const QImage& avatar) {
        player2->setEmail(email);
        player2->setPassword(password);
        player2->setBirthdate(birthdate);
        player2->setAvatar(avatar);

        // Persistir cambios en la base de datos
        player2->updateDatabase();
        //QMessageBox::information(this, "Perfil Actualizado", "Los datos del jugador 2 se han actualizado correctamente.");
    });

    registerWindow->show();
}

void GameBoard::on_modifyProfilePlayer1Button_clicked() {
    Player* player1 = Connect4::getInstance().getPlayer(player1Name);
    if (!player1) {
        QMessageBox::warning(this, "Error", "No se encontró al jugador 2.");
        return;
    }

    RegisterWindow* registerWindow = new RegisterWindow();
    Ui::RegisterWindow* ui = registerWindow->getUi();

    // Rellenar campos con los datos actuales del jugador
    ui->nicknameLineEdit->setText(player1->getNickName());
    ui->emailLineEdit->setText(player1->getEmail());
    ui->birthdateEdit->setDate(player1->getBirthdate());

    QIcon selectedIcon = ui->avatarCombo->selectedIcon(); // Obtener ícono seleccionado
    //selectedAvatar = selectedIcon.pixmap(100, 100).toImage(); // Convertir a QImage para guardar
    //ui->avatarCombo->setPixmap(QPixmap::fromImage(player1->getAvatar()).scaled(100, 100, Qt::KeepAspectRatio)); // Mostrar en el QLabel

    //ui->avatarLabel->setPixmap(QPixmap::fromImage(player1->getAvatar()).scaled(100, 100, Qt::KeepAspectRatio));

    // Deshabilitar edición del nickname
    ui->nicknameLineEdit->setEnabled(false);

    // Conectar la señal personalizada para guardar cambios
    connect(registerWindow, &RegisterWindow::registerPlayer, this, [=](const QString&, const QString& email, const QString& password, const QDate& birthdate, int, const QImage& avatar) {
        player1->setEmail(email);
        player1->setPassword(password);
        player1->setBirthdate(birthdate);
        player1->setAvatar(avatar);

        // Persistir cambios en la base de datos
        player1->updateDatabase();
        //QMessageBox::information(this, "Perfil Actualizado", "Los datos del jugador 2 se han actualizado correctamente.");
    });
    updatePlayerLabels();
    registerWindow->show();
}
