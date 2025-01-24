#include "connect4.h"
#include "mainwindow.h"
#include "menu_principal.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // Crear y mostrar el menú principal
    Menu_principal w;
    //w.setWindowTitle("Entrega 4 en raya Grupo 2");
    w.show();

    return a.exec();
}
