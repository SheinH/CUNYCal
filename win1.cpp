#include "win1.h"
#include "ui_win1.h"

Win1::Win1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Win1)
{
    ui->setupUi(this);
}

Win1::~Win1()
{
    delete ui;
}
