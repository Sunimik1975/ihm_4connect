#include "RankingWindow.h"
#include <QVBoxLayout>
#include <QListView>  // Agregar este include
#include "Player.h"
#include "connect4.h"
#include "rankingwindow.h"

RankingWindow::RankingWindow(QWidget* parent) {
    // Crear el modelo y la QListView
    model = new QStringListModel(this);
    listView = new QListView(this);

    // Configurar la vista
    listView->setModel(model);

    // Layout para la ventana
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(listView);
    setLayout(layout);

    // Cargar el ranking al abrir la ventana
    loadRanking();
}

RankingWindow::~RankingWindow() {}

void RankingWindow::loadRanking() {
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
