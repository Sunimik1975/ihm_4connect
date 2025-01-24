#include "RegisterWindow.h"
#include "ui_RegisterWindow.h"
#include "Connect4.h"
#include "iconcombobox.h"
#include <QFileDialog>

RegisterWindow::RegisterWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterWindow) {
    ui->setupUi(this);

    // Agregar íconos al IconComboBox
    QList<QString> avatarPaths = {":/avatar/avatars/default.png", ":/avatar/avatars/chica.jpg", ":/avatar/avatars/zorro.jpg"};
    for (const QString &path : avatarPaths) {
        ui->avatarCombo->addIconItem(path); // Utiliza addIconItem para agregar íconos
    }

    ui->avatarCombo->setCurrentIndex(-1); // Seleccionar el primer avatar por defecto

    connect(ui->registerButton, &QPushButton::clicked, this, &RegisterWindow::on_registerButton_clicked);
}

RegisterWindow::~RegisterWindow() {
    delete ui;
}

// Selección de avatar (actualizado para usar IconComboBox)
void RegisterWindow::on_selectAvatarButton_clicked() {
    QIcon selectedIcon = ui->avatarCombo->selectedIcon(); // Obtener ícono seleccionado
    selectedAvatar = selectedIcon.pixmap(100, 100).toImage(); // Convertir a QImage para guardar
    //ui->avatarLabel->setPixmap(QPixmap::fromImage(selectedAvatar)); // Mostrar en el QLabel
}

void RegisterWindow::on_registerButton_clicked() {
    QString nickName = ui->nicknameLineEdit->text();
    QString email = ui->emailLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    QDate birthdate = ui->birthdateEdit->date();

    // Validar datos
    if (!Connect4::getInstance().validatePlayerData(nickName, email, password, birthdate)) {
        return;
    }

    // Obtener el path del ícono seleccionado del IconComboBox
    QString selectedIconPath = ui->avatarCombo->selectedIconName(); // Obtener ruta completa del ícono seleccionado

    // Convertir el ícono a QImage para guardar
    QIcon selectedIcon = QIcon(selectedIconPath);
    selectedAvatar = selectedIcon.pixmap(100, 100).toImage();

    // Emitir la señal para registrar al jugador
    emit registerPlayer(nickName, email, password, birthdate, 0, selectedAvatar);
    this->hide();
}
