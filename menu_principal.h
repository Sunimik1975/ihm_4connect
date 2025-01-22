#ifndef MENU_PRINCIPAL_H
#define MENU_PRINCIPAL_H

#include <QDialog>

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





private:
    Ui::Menu_principal *ui;
    bool highContrastEnabled; // Variable para rastrear el estado del modo alto contraste

};

#endif // MENU_PRINCIPAL_H
