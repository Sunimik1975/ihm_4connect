#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openRegisterWindow(); // Slot para abrir la ventana de registro
    void login();
private:
    Ui::MainWindow *ui;
    QList<QString> activePlayers;  // Lista de jugadores activos
};

#endif // MAINWINDOW_H
