// RegisterWindow.cpp
#include "RegisterWindow.h"
#include "ui_RegisterWindow.h"
#include <QMessageBox>
#include "Connect4.h"

RegisterWindow::RegisterWindow(QWidget *parent) :
    QDialog(parent),  // Cambiar QWidget a QDialog
    ui(new Ui::RegisterWindow) {
    ui->setupUi(this);

    // El botón 'registerPlayerButton' tiene un nombre, así que Qt generará el slot 'on_registerPlayerButton_clicked'
    connect(ui->registerButton, &QPushButton::clicked, this, &::RegisterWindow::on_registerButton_clicked);
}

RegisterWindow::~RegisterWindow() {
    delete ui;
}

// Asegúrate de que el nombre del slot coincida con la convención de Qt
// RegisterWindow.cpp
void RegisterWindow::on_registerButton_clicked() {
    QString nickName = ui->nicknameLineEdit->text();
    QString email = ui->emailLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    QDate birthdate = ui->birthdateEdit->date();
    int points = ui->pointsSpinBox->value();

    if (nickName.isEmpty() || email.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Error", "Todos los campos deben estar llenos.");
        return;
    }

    qDebug() << "Datos del jugador: " << nickName << email << password << birthdate << points;
    // Emitir la señal para registrar al jugador
    emit registerPlayer(nickName, email, password, birthdate, points);

    // Cerrar la ventana de registro
    close();
}

