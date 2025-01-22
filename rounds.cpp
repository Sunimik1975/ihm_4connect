#include "rounds.h"                // Definición de la clase rounds
#include "staticsplayer.h"
#include "ui_staticsplayer.h"

#include "ui_rounds.h"             // Interfaz generada automáticamente por Qt
#include "Connect4.h"              // Clase principal para gestión de jugadores y rondas
#include <QDate>                   // Manejo de fechas
#include <QDateTime>               // Manejo de fechas y horas
#include <QStandardItemModel>      // Modelo estándar para tablas
#include <QMessageBox>             // Ventanas de mensajes
#include <QInputDialog>            // Ventanas de entrada
#include <QLineEdit>               // Línea de texto editable
#include <QTabWidget>              // Pestañas
#include <QTableView>              // Vista de tabla
#include <QTableWidget>            // Tabla editable
#include <QVBoxLayout>             // Layout vertical
#include <QPushButton>             // Botón de Qt
#include <algorithm>               // Funciones de ordenación como std::sort
#include <QDebug>                  // Depuración
#include <QtCharts/QChartView>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QChart>


rounds::rounds(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rounds),
    model(new QStandardItemModel(this))
{
    ui->setupUi(this);

    // Configuración inicial de la tabla
    model->setColumnCount(3);
    model->setHeaderData(0, Qt::Horizontal, "Día y Hora");
    model->setHeaderData(1, Qt::Horizontal, "Ganador");
    model->setHeaderData(2, Qt::Horizontal, "Perdedor");

    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    // Solicitar el nombre del jugador
    bool ok;
    playerName = QInputDialog::getText(this, tr("Ingresar nombre del jugador"),
                                       tr("Nombre del jugador:"), QLineEdit::Normal,
                                       "", &ok);

    if (ok && !playerName.isEmpty()) {
        loadRoundsData(playerName);
    } else {
        QMessageBox::warning(this, tr("Error"), tr("Debe ingresar un nombre válido."));
    }

    // Conectar el botón de filtro con la acción
    connect(ui->buscar_filtro, &QPushButton::clicked, this, &rounds::showAllPlayersWithRounds);
    connect(ui->jugador_tiempo, &QPushButton::clicked, this, &rounds::filterRoundsByDate);
    //ganadas/perdidas
    connect(ui->ganadas, &QPushButton::clicked, this, &rounds::filterRoundsByDateAndWins);
    connect(ui->perdidas, &QPushButton::clicked, this, &rounds::showPlayerStatsByDate);

}

rounds::~rounds()
{
    delete ui;
}

void rounds::loadRoundsData(const QString& playerName)
{
    Connect4& game = Connect4::getInstance();

    // Obtener jugador actual usando el nombre proporcionado
    Player* currentPlayer = game.getPlayer(playerName);
    if (!currentPlayer) {
        qWarning() << "Error: No se pudo obtener el jugador actual.";
        return;
    }

    // Obtener rondas jugadas por el jugador
    QList<Round*> roundsList = game.getRoundsForPlayer(currentPlayer);

    // Ordenar rondas por fecha (de más reciente a más antigua)
    std::sort(roundsList.begin(), roundsList.end(), [](Round* a, Round* b) {
        return a->getTimestamp() > b->getTimestamp();
    });

    // Llenar la tabla con los datos de las rondas
    model->setRowCount(roundsList.size());
    for (int i = 0; i < roundsList.size(); ++i) {
        Round* round = roundsList[i];
        model->setItem(i, 0, new QStandardItem(round->getTimestamp().toString("yyyy-MM-dd hh:mm:ss"))); // Día y Hora
        model->setItem(i, 1, new QStandardItem(round->getWinner()->getNickName())); // Ganador
        model->setItem(i, 2, new QStandardItem(round->getLoser()->getNickName()));  // Perdedor
    }
}

void rounds::filterRoundsByDate()
{
    // Obtener las fechas seleccionadas
    QDate startDate = ui->startDateEdit->date();
    QDate endDate = ui->endDateEdit->date();

    if (startDate > endDate) {
        QMessageBox::warning(this, "Error", "La fecha de inicio no puede ser mayor que la fecha final.");
        return;
    }

    Connect4& game = Connect4::getInstance();

    // Obtener jugador actual
    Player* currentPlayer = game.getPlayer(playerName);
    if (!currentPlayer) {
        QMessageBox::warning(this, "Error", "No se pudo encontrar al jugador.");
        return;
    }

    // Obtener rondas jugadas por el jugador
    QList<Round*> allRounds = game.getRoundsForPlayer(currentPlayer);

    // Filtrar rondas por el rango de fechas
    QList<Round*> filteredRounds;
    for (Round* round : allRounds) {
        QDate roundDate = round->getTimestamp().date();
        if (roundDate >= startDate && roundDate <= endDate) {
            filteredRounds.append(round);
        }
    }

    // Mostrar las rondas filtradas en la tabla
    model->setRowCount(filteredRounds.size());
    for (int i = 0; i < filteredRounds.size(); ++i) {
        Round* round = filteredRounds[i];
        model->setItem(i, 0, new QStandardItem(round->getTimestamp().toString("yyyy-MM-dd hh:mm:ss")));
        model->setItem(i, 1, new QStandardItem(round->getWinner()->getNickName()));
        model->setItem(i, 2, new QStandardItem(round->getLoser()->getNickName()));
    }

    if (filteredRounds.isEmpty()) {
        QMessageBox::information(this, "Sin partidas", "No se encontraron partidas en el rango de fechas seleccionado.");
    }
}

void rounds::showAllPlayersWithRounds()
{
    // Obtener las fechas seleccionadas
    QDate startDate = ui->startDateEdit->date();
    QDate endDate = ui->endDateEdit->date();

    Connect4& game = Connect4::getInstance();

    // Obtener la lista de todos los jugadores
    QList<Player*> players = game.getRanking();

    // Lista para almacenar todas las rondas concatenadas
    // Lista para almacenar todas las rondas concatenadas
    QList<Round*> allRounds;

    // Recorrer todos los jugadores y obtener sus rondas
    for (Player* player : players) {
        QList<Round*> playerRounds = game.getRoundsForPlayer(player);

        // Filtrar rondas por rango de fechas
        for (Round* round : playerRounds) {
            QDate roundDate = round->getTimestamp().date();
            if (roundDate >= startDate && roundDate <= endDate) {
                allRounds.append(round); // Agregar rondas dentro del rango
            }
        }
    }


    // Ordenar todas las rondas por fecha (de más reciente a más antigua)
    std::sort(allRounds.begin(), allRounds.end(), [](Round* a, Round* b) {
        return a->getTimestamp() > b->getTimestamp();
    });

    // Crear un diálogo para mostrar los datos
    QDialog* dialog = new QDialog(this);
    dialog->setWindowTitle("Todas las rondas");

    QVBoxLayout* layout = new QVBoxLayout(dialog);
    QTableWidget* table = new QTableWidget(dialog);
    table->setColumnCount(3); // Columnas: Fecha y Hora, Ganador, Perdedor
    table->setHorizontalHeaderLabels({"Fecha y Hora", "Ganador", "Perdedor"});

    // Llenar la tabla con los datos de todas las rondas
    table->setRowCount(allRounds.size());
    for (int i = 0; i < allRounds.size(); ++i) {
        Round* round = allRounds[i];
        table->setItem(i, 0, new QTableWidgetItem(round->getTimestamp().toString("yyyy-MM-dd hh:mm:ss"))); // Fecha y Hora
        table->setItem(i, 1, new QTableWidgetItem(round->getWinner()->getNickName())); // Ganador
        table->setItem(i, 2, new QTableWidgetItem(round->getLoser()->getNickName()));  // Perdedor
    }

    table->resizeColumnsToContents();
    layout->addWidget(table);
    dialog->setLayout(layout);

    // Botón para cerrar el diálogo
    QPushButton* closeButton = new QPushButton("Cerrar", dialog);
    layout->addWidget(closeButton);
    connect(closeButton, &QPushButton::clicked, dialog, &QDialog::accept);

    dialog->exec();
}

void rounds::filterRoundsByDateAndWins()
{
    // Obtener las fechas seleccionadas
    QDate startDate = ui->startDateEdit->date();
    QDate endDate = ui->endDateEdit->date();

    if (startDate > endDate) {
        QMessageBox::warning(this, "Error", "La fecha de inicio no puede ser mayor que la fecha final.");
        return;
    }

    Connect4& game = Connect4::getInstance();

    // Obtener jugador actual
    Player* currentPlayer = game.getPlayer(playerName);
    if (!currentPlayer) {
        QMessageBox::warning(this, "Error", "No se pudo encontrar al jugador.");
        return;
    }

    // Obtener rondas jugadas por el jugador
    QList<Round*> allRounds = game.getRoundsForPlayer(currentPlayer);

    qDebug() << "Total rounds found for player:" << allRounds.size();  // Verifica la cantidad de rondas

    // Filtrar rondas por el rango de fechas y si el jugador es el ganador
    QList<Round*> filteredRounds;
    for (Round* round : allRounds) {
        QDate roundDate = round->getTimestamp().date();
        qDebug() << "Round Date:" << roundDate.toString() << "Start Date:" << startDate.toString() << "End Date:" << endDate.toString();

        if (roundDate >= startDate && roundDate <= endDate && (round->getWinner()->getNickName() == currentPlayer->getNickName())) {
            filteredRounds.append(round);
        }
    }

    // Mostrar las rondas filtradas en la tabla
    model->setRowCount(filteredRounds.size());
    for (int i = 0; i < filteredRounds.size(); ++i) {
        Round* round = filteredRounds[i];
        model->setItem(i, 0, new QStandardItem(round->getTimestamp().toString("yyyy-MM-dd hh:mm:ss")));
        model->setItem(i, 1, new QStandardItem(round->getWinner()->getNickName()));
        model->setItem(i, 2, new QStandardItem(round->getLoser()->getNickName()));
    }

    if (filteredRounds.isEmpty()) {
        QMessageBox::information(this, "Sin partidas", "No se encontraron partidas del jugador como ganador en el rango de fechas seleccionado.");
    }
}


void rounds::filterRoundsByDateAndLoses()
{
    // Obtener las fechas seleccionadas
    QDate startDate = ui->startDateEdit->date();
    QDate endDate = ui->endDateEdit->date();

    if (startDate > endDate) {
        QMessageBox::warning(this, "Error", "La fecha de inicio no puede ser mayor que la fecha final.");
        return;
    }

    Connect4& game = Connect4::getInstance();

    // Obtener jugador actual
    Player* currentPlayer = game.getPlayer(playerName);
    if (!currentPlayer) {
        QMessageBox::warning(this, "Error", "No se pudo encontrar al jugador.");
        return;
    }

    // Obtener rondas jugadas por el jugador
    QList<Round*> allRounds = game.getRoundsForPlayer(currentPlayer);

    qDebug() << "Total rounds found for player:" << allRounds.size();  // Verifica la cantidad de rondas

    // Filtrar rondas por el rango de fechas y si el jugador es el ganador
    QList<Round*> filteredRounds;
    for (Round* round : allRounds) {
        QDate roundDate = round->getTimestamp().date();
        qDebug() << "Round Date:" << roundDate.toString() << "Start Date:" << startDate.toString() << "End Date:" << endDate.toString();

        if (roundDate >= startDate && roundDate <= endDate && (round->getLoser()->getNickName() == currentPlayer->getNickName())) {
            filteredRounds.append(round);
        }
    }

    // Mostrar las rondas filtradas en la tabla
    model->setRowCount(filteredRounds.size());
    for (int i = 0; i < filteredRounds.size(); ++i) {
        Round* round = filteredRounds[i];
        model->setItem(i, 0, new QStandardItem(round->getTimestamp().toString("yyyy-MM-dd hh:mm:ss")));
        model->setItem(i, 1, new QStandardItem(round->getWinner()->getNickName()));
        model->setItem(i, 2, new QStandardItem(round->getLoser()->getNickName()));
    }

    if (filteredRounds.isEmpty()) {
        QMessageBox::information(this, "Sin partidas", "No se encontraron partidas del jugador como ganador en el rango de fechas seleccionado.");
    }
}




void rounds::showPlayerStatsByDate()
{
    // Obtener las fechas seleccionadas
    QDate startDate = ui->startDateEdit->date();
    QDate endDate = ui->endDateEdit->date();
    if (startDate > endDate) {
        QMessageBox::warning(this, "Error", "La fecha de inicio no puede ser mayor que la fecha final.");
        return;
    }

    Connect4& game = Connect4::getInstance();

    // Obtener jugador actual
    Player* currentPlayer = game.getPlayer(playerName);
    if (!currentPlayer) {
        QMessageBox::warning(this, "Error", "No se pudo encontrar al jugador.");
        return;
    }

    // Obtener rondas jugadas por el jugador
    QList<Round*> allRounds = game.getRoundsForPlayer(currentPlayer);

    // Variables para almacenar estadísticas
    QMap<QDate, int> winsPerDay;
    QMap<QDate, int> lossesPerDay;
    QMap<QDate, QSet<QString>> opponentsPerDay;  // Usamos QSet para contar oponentes únicos

    // Procesar rondas
    for (Round* round : allRounds) {
        QDate roundDate = round->getTimestamp().date();

        if (roundDate >= startDate && roundDate <= endDate) {
            if (round->getWinner()->getNickName() == currentPlayer->getNickName()) {
                winsPerDay[roundDate]++;
            } else if (round->getLoser()->getNickName() == currentPlayer->getNickName()) {
                lossesPerDay[roundDate]++;
            }

            // Registrar oponentes enfrentados
            QString opponentName = (round->getWinner()->getNickName() == currentPlayer->getNickName())
                                       ? round->getLoser()->getNickName()
                                       : round->getWinner()->getNickName();
            opponentsPerDay[roundDate].insert(opponentName);
        }
    }
    qDebug() << winsPerDay;
    qDebug() << opponentsPerDay;
    qDebug() << endDate;

    // Pasar estadísticas a la ventana de gráficos
    openStatisticsWindow(winsPerDay, lossesPerDay, opponentsPerDay, startDate, endDate);
}

void rounds::openStatisticsWindow(const QMap<QDate, int>& winsPerDay,
                                  const QMap<QDate, int>& lossesPerDay,
                                  const QMap<QDate, QSet<QString>>& opponentsPerDay,
                                  const QDate& startDate,
                                  const QDate& endDate)
{
    StaticsPlayer* statsWindow = new StaticsPlayer(playerName, winsPerDay, lossesPerDay, opponentsPerDay, startDate, endDate, this);
    statsWindow->exec();


}



