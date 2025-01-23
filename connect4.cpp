#include "Connect4.h"
#include "Connect4DAO.h"
#include <QFile>
#include <QDebug>
#include <QRegularExpression>
#include <QMessageBox>


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
    qDebug() << "Intentando registrar jugador:" << nickName << email << password << birthdate << points;

    if (!validatePlayerData(nickName, email, password, birthdate)) {
        qDebug() << "Error: Validación fallida para el jugador.";
        return nullptr;
    }

    QImage finalAvatar = avatar.isNull() ? QImage(":/avatar/avatars/default.png") : avatar;
    Player* player = new Player(nickName, email, password, birthdate, points, finalAvatar);

    if (Connect4DAO::getInstance().addPlayer(*player)) {
        qDebug() << "Jugador registrado exitosamente en la base de datos.";
        return player;
    } else {
        qCritical() << "Error al agregar el jugador a la base de datos.";
        delete player;
        return nullptr;
    }
}

Player* Connect4::registerPlayer(const QString& nickName, const QString& email,
                                 const QString& password, const QDate& birthdate, int points) {
    return registerPlayer(nickName, email, password, birthdate, points, QImage());
}






bool Connect4::validatePlayerData(const QString& nickName, const QString& email,
                                  const QString& password, const QDate& birthdate) {
    QStringList errors;

    QRegularExpression nicknameRegex("^[a-zA-Z0-9_-]{6,15}$");
    if (!nicknameRegex.match(nickName).hasMatch()) {
        errors << "El nickname debe tener entre 6 y 15 caracteres y solo puede contener letras, números, guiones o guiones bajos.";
    }

    QRegularExpression emailRegex(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
    if (!emailRegex.match(email).hasMatch()) {
        errors << "El correo electrónico no tiene un formato válido.";
    }

    QRegularExpression passwordRegex(R"((?=.*[A-Z])(?=.*[a-z])(?=.*\d)(?=.*[!@#$%&*()-+=]).{8,20})");
    if (!passwordRegex.match(password).hasMatch()) {
        errors << "La contraseña debe tener entre 8 y 20 caracteres, incluyendo una mayúscula, una minúscula, un número y un símbolo especial.";
    }

    QDate currentDate = QDate::currentDate();
    if (birthdate.addYears(12) > currentDate) {
        errors << "El jugador debe tener al menos 12 años.";
    }

    if (!errors.isEmpty()) {
        QMessageBox::warning(nullptr, "Error en validación", errors.join("\n"));
        return false;
    }

    return true;
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


