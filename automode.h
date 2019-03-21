#ifndef AUTOMODE_H
#define AUTOMODE_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <memory>


namespace Ui {
class automode;
}

class automode : public QMainWindow
{
    Q_OBJECT

public:
    explicit automode(QWidget *parent = nullptr);
    ~automode();

private:
    Ui::automode *ui;
    QVideoWidget *videoWidget;
    std::unique_ptr<QMediaPlayer> mediaPlayer;
    std::unique_ptr<QMediaPlaylist> playlist;
    void set_continue_state(bool);
private slots:
    void clipboard_changed();
};

#endif // AUTOMODE_H
