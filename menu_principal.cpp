#include "menu_principal.h"
#include "Player.h"
#include "ui_menu_principal.h"
#include "mainwindow.h"   // Ventana para el modo multiplayer
#include "connect4.h"
#include <QMessageBox>
#include "gameboard.h"
#include "Connect4DAO.h"
#include <QApplication>
#include <QPalette> // Para manejar colores en la aplicación
#include "rounds.h"

Menu_principal::Menu_principal(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Menu_principal)
    , highContrastEnabled(false) // Inicializamos como false

{
    ui->setupUi(this);
    // Inicializar el modelo
    rankingModel = new QStandardItemModel(this);

    // Configurar las columnas del modelo
    rankingModel->setColumnCount(3); // Dos columnas: Nombre y Puntos
    rankingModel->setHorizontalHeaderLabels({"Jugador", "Puntos", "Avatar"});

    // Asignar el modelo al QTableView ya existente en la UI
    ui->rankingTableView->setModel(rankingModel);

    // Ajustar las columnas al contenido
    ui->rankingTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Cargar el ranking
    loadRanking();
    // Conectar botones a las funciones correspondientes
    connect(ui->Singleplayer_button, &QPushButton::clicked, this, &Menu_principal::on_btnSinglePlayer_clicked);
    connect(ui->multiplayer_button, &QPushButton::clicked, this, &Menu_principal::on_btnMultiPlayer_clicked);
    connect(ui->fondo_oscuro, &QPushButton::clicked, this, &Menu_principal::on_btnHighContrast_clicked);
    connect(ui->rondas, &QPushButton::clicked, this, &Menu_principal::showRounds);

}

Menu_principal::~Menu_principal()
{
    delete ui;
}

void Menu_principal::loadRanking() {
    // Obtener el ranking de los jugadores desde Connect4
    QList<Player*> players = Connect4::getInstance().getRanking();

    // Limpiar el modelo actual
    rankingModel->removeRows(0, rankingModel->rowCount());

    // Configurar las columnas del modelo
    rankingModel->setColumnCount(3); // Tres columnas: Nombre, Puntos y Avatar
    rankingModel->setHorizontalHeaderLabels({"Jugador", "Puntos", "Avatar"});

    // Llenar la tabla con los datos
    for (Player* player : players) {
        QList<QStandardItem*> row;
        row << new QStandardItem(player->getNickName());           // Nombre del jugador
        row << new QStandardItem(QString::number(player->getPoints())); // Puntos del jugador

        // Crear un item para el avatar
        QStandardItem* avatarItem = new QStandardItem();
        QPixmap avatarPixmap = QPixmap::fromImage(player->getAvatar()).scaled(50, 30, Qt::KeepAspectRatio);
        avatarItem->setData(avatarPixmap, Qt::DecorationRole);
        row << avatarItem;

        rankingModel->appendRow(row);
    }

    // Ajustar las columnas al contenido
    ui->rankingTableView->resizeColumnsToContents();
    ui->rankingTableView->setColumnWidth(2, 50); // Ajustar el ancho de la columna del avatar
    ui->rankingTableView->verticalHeader()->setDefaultSectionSize(30); // Ajustar la altura de las filas
}
void Menu_principal::showRounds()
{
    rounds *roundsDialog = new rounds(this); // Crea un diálogo de la clase rounds
    roundsDialog->show(); // Muestra el diálogo
}

void Menu_principal::on_btnSinglePlayer_clicked() {
    // Crear la instancia del juego
    Connect4& game = Connect4::getInstance();

    // Verificar si la máquina está registrada, si no, registrarla
    if (!game.existsNickName("Maquina")) {
        Player* maquina = game.registerPlayer("Maquina", "maquina@example.com", "Maquina123@", QDate(1990, 1, 1), 100);
        if (maquina) {
            qDebug() << "Jugador máquina registrado:" << maquina->getNickName();
        }
    } else {
        qDebug() << "La máquina ya está registrada.";
    }

    // Verificar si la máquina ya está logueada
    Player* maquina = game.loginPlayer("Maquina", "Maquina123@");
    if (maquina) {
        qDebug() << "Jugador máquina logeado:" << maquina->getNickName();
    } else {
        qDebug() << "Error al iniciar sesión con la máquina.";
    }

    // Crear y mostrar la ventana principal de juego
    MainWindow* mainWindow = new MainWindow(this);

    // Asumimos que la máquina será el oponente predeterminado
    mainWindow->setJugadorConectado("Maquina");

    // Mostrar la ventana principal
    mainWindow->show();

    // Ocultar el menú principal, pero no cerrarlo
    this->hide();
}

// Esta función lanza el juego en modo Multiplayer
void Menu_principal::on_btnMultiPlayer_clicked()
{
    // Crear la ventana principal para multiplayer
    MainWindow *mainWindow = new MainWindow(this);

    // Indicar que el juego es en modo multiplayer
    mainWindow->setIsMultiplayer(true);  // Le pasamos el estado a MainWindow

    // Mostrar la ventana principal
    mainWindow->show();

    // Ocultar el menú principal
    hide();
/*
    // Obtener la instancia de Connect4
    Connect4& game = Connect4::getInstance();

    // Confirmar con el usuario antes de borrar todos los datos
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmación",
                                  "¿Estás seguro de que quieres borrar todos los datos de la base de datos?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        // Llamar a la función para borrar todos los datos
        game.clearAllData();

        // Mostrar mensaje de éxito
        QMessageBox::information(this, "Datos borrados", "Todos los datos de la base de datos han sido eliminados.");
    } else {
        // Cancelación del borrado
        QMessageBox::information(this, "Cancelado", "No se han eliminado los datos.");
    }
*/

}


void Menu_principal::on_btnHighContrast_clicked()
{



    if (highContrastEnabled) {
        // Cambiar al modo normal (opcional, si tienes otro archivo .qss para modo normal)
        QFile normalStyleFile(":/estilos/normalStyle.qss");
        if (normalStyleFile.open(QFile::ReadOnly)) {
            QString normalStyleSheet = QLatin1String(normalStyleFile.readAll());
            qApp->setStyleSheet(normalStyleSheet);
            normalStyleFile.close();
        }
        // Ya se aplica el estilo de alto contraste desde el archivo QSS
        //QMessageBox::information(this, "Modo claro", "El modo claro se ha activado.");
        highContrastEnabled = false;
    } else {
        // Cambiar al modo normal (opcional, si tienes otro archivo .qss para modo normal)
        QFile normalStyleFile(":/estilos/estilos.qss");
        if (normalStyleFile.open(QFile::ReadOnly)) {
            QString normalStyleSheet = QLatin1String(normalStyleFile.readAll());
            qApp->setStyleSheet(normalStyleSheet);
            normalStyleFile.close();
        }

        //QMessageBox::information(this, "Modo oscuro", "El modo oscuro se ha activado.");
        highContrastEnabled = true;

    }
}
    /*
    if (highContrastEnabled) {
        // Cambiar al modo normal: Fondo blanco y estilo predeterminado
        QPalette lightPalette;

        // Configurar el fondo blanco puro
        lightPalette.setColor(QPalette::Window, Qt::white); // Fondo general
        lightPalette.setColor(QPalette::Base, Qt::white);   // Fondo de widgets
        lightPalette.setColor(QPalette::AlternateBase, Qt::lightGray); // Alternativo

        // Colores del texto
        lightPalette.setColor(QPalette::WindowText, Qt::black); // Texto general
        lightPalette.setColor(QPalette::Text, Qt::black);       // Texto en widgets
        lightPalette.setColor(QPalette::ButtonText, Qt::black); // Texto en botones
        lightPalette.setColor(QPalette::ToolTipText, Qt::black);

        // Colores de botones
        lightPalette.setColor(QPalette::Button, Qt::white); // Fondo de botones

        // Colores de selección
        lightPalette.setColor(QPalette::Highlight, QColor(100, 100, 255)); // Resaltado azul
        lightPalette.setColor(QPalette::HighlightedText, Qt::white);

        // Aplicar la paleta clara a la aplicación
        qApp->setPalette(lightPalette);

        // Eliminar hojas de estilo personalizadas
        qApp->setStyleSheet("");

        QMessageBox::information(this, "Modo Normal", "El modo normal se ha activado.");
        highContrastEnabled = false; // Actualizar el estado
    } else {
        // Cambiar al modo de alto contraste
        QPalette darkPalette;

        // Fondo general
        darkPalette.setColor(QPalette::Window, QColor(35, 35, 35)); // Fondo oscuro
        darkPalette.setColor(QPalette::Base, QColor(45, 45, 45));   // Fondo de widgets
        darkPalette.setColor(QPalette::AlternateBase, QColor(60, 60, 60));

        // Colores del texto
        darkPalette.setColor(QPalette::WindowText, Qt::white); // Texto general
        darkPalette.setColor(QPalette::Text, Qt::black);       // Texto en widgets
        darkPalette.setColor(QPalette::ButtonText, Qt::white); // Texto en botones
        darkPalette.setColor(QPalette::ToolTipText, Qt::white);

        // Colores de botones
        darkPalette.setColor(QPalette::Button, QColor(50, 50, 50)); // Fondo de botones
        darkPalette.setColor(QPalette::BrightText, Qt::red);

        // Colores de selección
        darkPalette.setColor(QPalette::Highlight, QColor(100, 100, 255)); // Resaltado azul
        darkPalette.setColor(QPalette::HighlightedText, Qt::white);

        // Aplicar la paleta de alto contraste a la aplicación
        qApp->setPalette(darkPalette);

        // Estilo global para botones y cuadros de diálogo
        QString globalStyle = R"(
            QPushButton {
                background-color: #323232;
                color: white;
                border: 1px solid #555555;
                border-radius: 5px;
                padding: 5px;
            }
            QPushButton:hover {
                background-color: #505050;
            }
            QPushButton:pressed {
                background-color: #282828;
            }
            QMessageBox {
                background-color: #323232;
                color: white;
                border: 1px solid #555555;
                border-radius: 10px;
            }
            QMessageBox QLabel {
                color: white;
            }
            QMessageBox QPushButton {
                background-color: #505050;
                color: white;
                border: 1px solid #777777;
                padding: 5px;
                border-radius: 5px;
            }
            QMessageBox QPushButton:hover {
                background-color: #606060;
            }
            QMessageBox QPushButton:pressed {
                background-color: #404040;
            }
        )";

        qApp->setStyleSheet(globalStyle);

        QMessageBox::information(this, "Modo Alto Contraste", "El modo de alto contraste se ha activado.");
        highContrastEnabled = true; // Actualizar el estado
    }*/
