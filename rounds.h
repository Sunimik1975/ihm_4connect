#ifndef ROUNDS_H
#define ROUNDS_H

#include <QDialog>
#include <QStandardItemModel>
#include <QList>

class Player; // Declaración adelantada de la clase Player
class Round;  // Declaración adelantada de la clase Round

namespace Ui {
class rounds;
}

class rounds : public QDialog
{
    Q_OBJECT

public:
    Ui::rounds* getUi() const { return ui; }
    explicit rounds(QWidget *parent = nullptr);
    ~rounds();
    //string StaticsPlayer(playerName, winsPerDay, lossesPerDay, opponentsPerDay, startDate, endDate, this);

    // Métodos públicos
    void showAllPlayersWithRounds(); // Muestra todas las rondas concatenadas en una tabla
    void loadRoundsData(const QString& playerName); // Carga datos de un jugador específico (método heredado del ejemplo)
    void filterRoundsByDate(); // Filtra rondas por rango de fechas
    void filterRoundsByDateAndWins();
    void filterRoundsByDateAndLoses();
    void showPlayerStatsByDate();
    void openStatisticsWindow(const QMap<QDate, int>& winsPerDay,
                                      const QMap<QDate, int>& lossesPerDay,
                                      const QMap<QDate, QSet<QString>>& opponentsPerDay,
                                      const QDate& startDate,
                              const QDate& endDate);

private:
    Ui::rounds *ui;                          // Puntero a la interfaz de usuario
    QStandardItemModel *model;               // Modelo para gestionar datos en tablas
    QString playerName;                      // Nombre del jugador actual
    void initializeTable();                  // Método para inicializar la tabla
    void populateTableWithRounds(QList<Round*> rounds); // Llena la tabla con rondas dadas

};

#endif // ROUNDS_H
