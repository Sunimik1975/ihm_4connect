#ifndef RANKINGWINDOW_H
#define RANKINGWINDOW_H

#include <QWidget>
#include <QListView>  // Agregar este include para QListView
#include <QStringListModel>

class RankingWindow : public QWidget {
    Q_OBJECT

public:
    explicit RankingWindow(QWidget* parent = nullptr);
    ~RankingWindow();

private:
    QListView* listView;  // Declarar listView como un puntero a QListView
    QStringListModel* model;  // Declarar el modelo de lista
    void loadRanking();  // Función para cargar el ranking
};

#endif // RANKINGWINDOW_H
