#include "rankingwindow.h"
#include "ui_rankingwindow.h"
#include <QVBoxLayout>
#include <QListView>  // Agregar este include
#include "Player.h"
#include "connect4.h"

rankingwindow::rankingwindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::rankingwindow)
{
    ui->setupUi(this);

    // Crear el modelo de la lista
    model = new QStringListModel(this);

    // Asignar el modelo al QListView ya existente en la UI
    ui->listView->setModel(model);

    // Cargar el ranking al abrir la ventana
    loadRanking();
}

rankingwindow::~rankingwindow()
{
    delete ui;
}

void rankingwindow::loadRanking() {
    // Obtener la lista de jugadores desde Connect4
    QList<Player*> players = Connect4::getInstance().getRanking();

    // Crear una lista de strings que contenga tanto el nombre como los puntos
    QStringList playerInfo;
    for (Player* player : players) {
        // Concatenamos el nombre del jugador con sus puntos
        playerInfo << QString("%1 - %2 puntos").arg(player->getNickName()).arg(player->getPoints());
    }

    // Establecer los datos en el modelo
    model->setStringList(playerInfo);
}
