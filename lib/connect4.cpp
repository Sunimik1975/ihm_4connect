#include "Connect4.h"
#include "Connect4DAO.h"
#include <QFile>
#include <QDebug>

Connect4::Connect4() {}
Connect4::~Connect4() {}

Connect4& Connect4::getInstance() {
    static Connect4 instance;

    static bool isInitialized = false; // Control para inicializar solo la primera vez
    if (!isInitialized) {
        instance.initializeDatabase();
        isInitialized = true;
    }

    return instance;
}

void Connect4::initializeDatabase() {
    // Verificar si el archivo de base de datos existe
    if (!QFile::exists(databaseFilePath)) {
        qDebug() << "El archivo de base de datos no existe. Creando nuevo archivo en" << databaseFilePath;
    }
    else {
        qDebug() << "Archivo de base de datos encontrado en" << databaseFilePath;
    }

    // Inicializar la base de datos y crear estructura si no existe
    if (!Connect4DAO::getInstance().initializeDatabase(databaseFilePath)) {
        qCritical() << "Error al inicializar la base de datos.";
    }
}

Player* Connect4::registerPlayer(const QString& nickName, const QString& email,
    const QString& password, const QDate& birthdate, int points,
    const QImage& avatar) {
    if (!validatePlayerData(nickName, email, password, birthdate)) {
        qDebug() << "Datos del jugador no válidos.";
        return nullptr;
    }

    QImage finalAvatar = avatar.isNull() ? QImage(":/images/default.png") : avatar;
    Player* player = new Player(nickName, email, password, birthdate, points, finalAvatar);
    if (Connect4DAO::getInstance().addPlayer(*player)) {
        return player;
    }
    else {
        delete player;
        return nullptr;
    }
}

}

bool Connect4::validatePlayerData(const QString& nickName, const QString& email,
    const QString& password, const QDate& birthdate) {
    QRegExp nicknameRegex("^[a-zA-Z0-9_-]{6,15}$");
    if (!nicknameRegex.exactMatch(nickName)) {
        qDebug() << "El nickname no cumple con los requisitos.";
        return false;
    }

    QRegExp emailRegex(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
    if (!emailRegex.exactMatch(email)) {
        qDebug() << "El correo electrónico no tiene un formato válido.";
        return false;
    }

    QRegExp passwordRegex(R"((?=.*[A-Z])(?=.*[a-z])(?=.*\d)(?=.*[!@#$%&*()-+=]).{8,20})");
    if (!passwordRegex.exactMatch(password)) {
        qDebug() << "La contraseña no cumple con los requisitos de seguridad.";
        return false;
    }

    QDate currentDate = QDate::currentDate();
    if (birthdate.addYears(12) > currentDate) {
        qDebug() << "El jugador debe tener al menos 12 años.";
        return false;
    }

    return true;
}


Player* Connect4::registerPlayer(const QString& nickName, const QString& email,
    const QString& password, const QDate& birthdate, int points) {
    return registerPlayer(nickName, email, password, birthdate, points, QImage());
}


Round* Connect4::registerRound(const QDateTime& timestamp, Player* winner, Player* loser) {
    Round* round = new Round(timestamp, winner, loser);
    if (Connect4DAO::getInstance().addRound(*round)) {
        return round;
    }
    else {
        delete round;
        return nullptr;
    }
}

Player* Connect4::loginPlayer(const QString& nickName, const QString& password) {
    Player* player = Connect4DAO::getInstance().getPlayer(nickName);
    if (player && player->getPassword() == password) {
        return player;
    }
    delete player;
    return nullptr;
}

Player* Connect4::getPlayer(const QString& nickName)
{
    Player* player = Connect4DAO::getInstance().getPlayer(nickName);
    if (player) {
        return player;
    }
    delete player;
    return nullptr;
}

bool Connect4::existsNickName(const QString& nickName)
{
    Player* player = Connect4DAO::getInstance().getPlayer(nickName);
    bool result = false;
    if (player) {
        result = true;
    }
    delete player;
    return result;
}

QList<Player*> Connect4::getRanking() {
    return Connect4DAO::getInstance().getRanking();
}

QList<Round*> Connect4::getRoundsForPlayer(Player* player) {
    return Connect4DAO::getInstance().getRoundsForPlayer(player->getNickName());
}

void Connect4::clearAllData() {
    Connect4DAO::getInstance().clearAllData();
}
