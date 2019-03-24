#include "manualmode.h"
#include "ui_manualmode.h"

manualmode::manualmode(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::manualmode)
{
    ui->setupUi(this);
}

manualmode::~manualmode()
{
    delete ui;
}
