#ifndef WIN1_H
#define WIN1_H

#include <QMainWindow>
#include "automode.h"
namespace Ui {
class Win1;
}

class Win1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Win1(QWidget *parent = nullptr);
    ~Win1();

private slots:
    void on_pushButton_clicked();
private:
    Ui::Win1 *ui;
    automode* autoMode;
};

#endif // WIN1_H
