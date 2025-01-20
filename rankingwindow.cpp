#include "RankingWindow.h"
#include <QVBoxLayout>
#include <QListView>  // Agregar este include
#include "Player.h"
#include "connect4.h"

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

    // Convertir la lista de objetos Player* en una lista de QStrings con los nombres de los jugadores
    QStringList playerNames;
    for (Player* player : players) {
        playerNames << player->getNickName();  // Obtener el nickname de cada jugador
    }

    // Establecer los datos en el modelo
    model->setStringList(playerNames);
}
