#include "win1.h"
#include "ui_win1.h"

Win1::Win1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Win1)
{
    ui->setupUi(this);
    autoMode = new automode();
    manualMode = new manualmode();
}

Win1::~Win1()
{
    delete ui;
}

void Win1::on_pushButton_clicked()
{
    close();
    autoMode->show();
}

void Win1::on_pushButton_2_clicked()
{
    close();
    manualMode->show();
}
