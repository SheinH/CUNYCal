#include "win1.h"
#include "automode.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Win1 w;
    w.show();

    return a.exec();
}
