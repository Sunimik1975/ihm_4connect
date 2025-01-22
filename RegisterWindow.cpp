// RegisterWindow.cpp
#include "RegisterWindow.h"
#include "ui_RegisterWindow.h"
#include <QMessageBox>
#include "Connect4.h"
#include <QFileDialog>

RegisterWindow::RegisterWindow(QWidget *parent) :
    QDialog(parent),  // Cambiar QWidget a QDialog
    ui(new Ui::RegisterWindow) {
    ui->setupUi(this);

    // El botón 'registerPlayerButton' tiene un nombre, así que Qt generará el slot 'on_registerPlayerButton_clicked'
    connect(ui->registerButton, &QPushButton::clicked, this, &RegisterWindow::on_registerButton_clicked);
    connect(ui->avatarButton, &QPushButton::clicked, this, &RegisterWindow::on_selectAvatarButton_clicked);
    connect(ui->nosirve, &QPushButton::clicked, this, &RegisterWindow::on_selectAvatarButton_clicked);
}

RegisterWindow::~RegisterWindow() {
    delete ui;
}
// Función para seleccionar el avatar
void RegisterWindow::on_selectAvatarButton_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this, "Seleccionar Avatar", "", "Imágenes (*.png *.jpg *.jpeg)");

    if (!fileName.isEmpty()) {
        // Cargar la imagen seleccionada
        selectedAvatar.load(fileName);

        // Redimensionar la imagen para que se ajuste al QLabel
        QPixmap avatarPixmap = QPixmap::fromImage(selectedAvatar).scaled(100, 100, Qt::KeepAspectRatio);

        // Mostrar la imagen en la etiqueta
        ui->avatarLabel->setPixmap(avatarPixmap);
    }
}
// Asegúrate de que el nombre del slot coincida con la convención de Qt
void RegisterWindow::on_registerButton_clicked() {
    QString nickName = ui->nicknameLineEdit->text();
    QString email = ui->emailLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    QDate birthdate = ui->birthdateEdit->date();
    int points = ui->pointsSpinBox->value();
    QImage avatar;

    // Validar datos
    if (!Connect4::getInstance().validatePlayerData(nickName, email, password, birthdate)) {
        // Detener si los datos no son válidos
        return;
    }

    emit registerPlayer(nickName, email, password, birthdate, points, avatar);
    //qDebug() << "Señal emitida: registerPlayer(" << nickName << ", " << email << ", " << password << ", " << birthdate << ", " << points << ")";

    this->hide();
}




