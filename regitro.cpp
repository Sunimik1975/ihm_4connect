#include "regitro.h"
#include "ui_regitro.h"

regitro::regitro(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::regitro)
{
    ui->setupUi(this);
}

regitro::~regitro()
{
    delete ui;
}
