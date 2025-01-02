#ifndef REGITRO_H
#define REGITRO_H

#include <QDialog>

namespace Ui {
class regitro;
}

class regitro : public QDialog
{
    Q_OBJECT

public:
    explicit regitro(QWidget *parent = nullptr);
    ~regitro();

private:
    Ui::regitro *ui;
};

#endif // REGITRO_H
