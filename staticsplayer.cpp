#include "staticsplayer.h"
#include "ui_RegisterWindow.h"
#include "ui_staticsplayer.h"
#include "ui_rounds.h"
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
#include "ui_rounds.h"
#include "ui_staticsplayer.h"

//Se ha utilizado la ayuda de inteligencia artificial para la realización de este código

StaticsPlayer::StaticsPlayer(const QString& playerName,
                             const QMap<QDate, int>& winsPerDay,
                             const QMap<QDate, int>& lossesPerDay,
                             const QMap<QDate, QSet<QString>>& opponentsPerDay,
                             const QDate& startDate,
                             const QDate& endDate,
                             QWidget* parent)
    : QDialog(parent),
    ui(new Ui::StaticsPlayer)
{
    ui->setupUi(this);
    this->resize(820,900);
    setFixedSize(this->size()); // Fija el tamaño actual de la ventana

    // Crear layouts para las gráficas
    QVBoxLayout* barChartLayout = new QVBoxLayout();
    QVBoxLayout* opponentsChartLayout = new QVBoxLayout();

    // Widgets para las gráficas
    QWidget* chartWidget = new QWidget(this);
    chartWidget->setGeometry(10, 50, 800, 400);
    chartWidget->setLayout(barChartLayout);

    QWidget* opponentsWidget = new QWidget(this);
    opponentsWidget->setGeometry(10, 460, 800, 400);
    opponentsWidget->setLayout(opponentsChartLayout);

    chartWidget->show();
    opponentsWidget->show();

    // Primera gráfica: partidas ganadas y perdidas
    QBarSet* winsSet = new QBarSet("Ganadas");
    QBarSet* lossesSet = new QBarSet("Perdidas");

    QStringList categories;
    for (QDate date = startDate; date <= endDate; date = date.addDays(1)) {
        categories << date.toString("dd-MM-yyyy");
        *winsSet << winsPerDay.value(date, 0);
        *lossesSet << lossesPerDay.value(date, 0);
    }

    QBarSeries* series = new QBarSeries();
    series->append(winsSet);
    series->append(lossesSet);

    QChart* barChart = new QChart();
    barChart->addSeries(series);
    barChart->setTitle("Partidas ganadas y perdidas");
    barChart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis* axisX = new QBarCategoryAxis();
    axisX->append(categories);
    barChart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis* axisY = new QValueAxis();
    axisY->setTitleText("Número de partidas");
    barChart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QChartView* barChartView = new QChartView(barChart);
    barChartView->setRenderHint(QPainter::Antialiasing);

    barChartLayout->addWidget(barChartView);

    // Segunda gráfica: oponentes enfrentados
    QMap<QString, QBarSet*> barSets;  // Un conjunto de barras por oponente
    QBarSeries* opponentSeries = new QBarSeries();

    // Lista para las categorías (fechas)
    QStringList opponentCategories;

    // Iterar las fechas en orden cronológico
    for (QDate date = startDate; date <= endDate; date = date.addDays(1)) {
        opponentCategories << date.toString("dd-MM-yyyy");  // Añadir la fecha como categoría

        // Obtener los oponentes enfrentados ese día
        QSet<QString> opponents = opponentsPerDay.value(date);

        // Iterar sobre los oponentes
        for (const QString& opponent : opponents) {
            // Crear un QBarSet para el oponente si no existe
            if (!barSets.contains(opponent)) {
                QBarSet* newBarSet = new QBarSet(opponent);
                barSets[opponent] = newBarSet;
                opponentSeries->append(newBarSet);
            }

            // Rellenar con valores para fechas anteriores si faltan
            while (barSets[opponent]->count() < opponentCategories.size() - 1) {
                *(barSets[opponent]) << 0;
            }

            // Añadir enfrentamiento para este día
            *(barSets[opponent]) << 1;
        }

        // Rellenar con valores 0 para oponentes no enfrentados
        for (auto barSet : barSets) {
            if (!opponents.contains(barSet->label())) {
                while (barSet->count() < opponentCategories.size() - 1) {
                    *barSet << 0;  // Rellenar días anteriores
                }
                *barSet << 0;  // Añadir el día actual como 0
            }
        }
    }



    QChart* opponentsChart = new QChart();
    opponentsChart->addSeries(opponentSeries);
    opponentsChart->setTitle("Oponentes enfrentados por día");
    opponentsChart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis* opponentsAxisX = new QBarCategoryAxis();
    opponentsAxisX->append(opponentCategories);
    opponentsChart->addAxis(opponentsAxisX, Qt::AlignBottom);
    opponentSeries->attachAxis(opponentsAxisX);

    QValueAxis* opponentsAxisY = new QValueAxis();
    opponentsAxisY->setTitleText("Número de enfrentamientos");
    opponentsChart->addAxis(opponentsAxisY, Qt::AlignLeft);
    opponentSeries->attachAxis(opponentsAxisY);

    QChartView* opponentsChartView = new QChartView(opponentsChart);
    opponentsChartView->setRenderHint(QPainter::Antialiasing);

    opponentsChartLayout->addWidget(opponentsChartView);
}




StaticsPlayer::~StaticsPlayer()
{
    delete ui;
}



