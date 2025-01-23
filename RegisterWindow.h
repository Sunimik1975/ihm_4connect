#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QWidget>
#include <QString>
#include <QDate>
#include <QDialog>
#include "iconcombobox.h"


namespace Ui {
class RegisterWindow;
}

// RegisterWindow.h
class RegisterWindow : public QDialog {
    Q_OBJECT

public:
    Ui::RegisterWindow* getUi() const { return ui; }
    explicit RegisterWindow(QWidget *parent = nullptr);
    ~RegisterWindow();

signals:
signals:
    void registerPlayer(const QString& nickName, const QString& email, const QString& password,
                        const QDate& birthdate, int points, const QImage& avatar);



private slots:
    void on_registerButton_clicked();
    void on_selectAvatarButton_clicked();


private:
    Ui::RegisterWindow *ui;
    QImage selectedAvatar;
};

#endif // REGISTERWINDOW_H
