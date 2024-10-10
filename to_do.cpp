#include "to_do.h"
#include "ui_to_do.h"

To_Do::To_Do(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::To_Do)
{
    ui->setupUi(this);
}

To_Do::~To_Do()
{
    delete ui;
}
