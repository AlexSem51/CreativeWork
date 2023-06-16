#include "windowarm.h"
#include "ui_windowarm.h"

WindowARM::WindowARM(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowARM)
{
    ui->setupUi(this);
}

WindowARM::~WindowARM()
{
    delete ui;
}
