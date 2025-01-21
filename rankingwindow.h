#ifndef RANKINGWINDOW_H
#define RANKINGWINDOW_H

#include <QDialog>
#include <QListView>  // Agregar este include para QListView
#include <QStringListModel>


namespace Ui {
class rankingwindow;
}

class rankingwindow : public QDialog
{
    Q_OBJECT

public:
    explicit rankingwindow(QWidget *parent = nullptr);
    ~rankingwindow();

private:
    Ui::rankingwindow *ui;
    void loadRanking();  // Función para cargar el ranking
    QStringListModel* model;

};

#endif // RANKINGWINDOW_H
