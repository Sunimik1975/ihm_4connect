#ifndef MENU_PRINCIPAL_H
#define MENU_PRINCIPAL_H

#include <QDialog>
#include <QTableView>
#include <QStandardItemModel>

namespace Ui {
class Menu_principal;
}

class Menu_principal : public QDialog
{
    Q_OBJECT

public:
    explicit Menu_principal(QWidget *parent = nullptr);
    ~Menu_principal();
    void on_btnSinglePlayer_clicked();
    void on_btnMultiPlayer_clicked();
    void on_btnHighContrast_clicked();
    void loadRanking();
    void showRounds();
    bool highContrastEnabled; // Variable para rastrear el estado del modo alto contraste

private:
    Ui::Menu_principal *ui;
    QTableView* rankingTableView;        // Tabla para mostrar el ranking
    QStandardItemModel* rankingModel;   // Modelo para manejar los datos del ranking
};

#endif // MENU_PRINCIPAL_H
