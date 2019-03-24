#ifndef MANUALMODE_H
#define MANUALMODE_H

#include <QMainWindow>

namespace Ui {
class manualmode;
}

class manualmode : public QMainWindow
{
    Q_OBJECT

public:
    explicit manualmode(QWidget *parent = nullptr);
    ~manualmode();

private:
    Ui::manualmode *ui;
};

#endif // MANUALMODE_H
