#ifndef AUTOMODE_H
#define AUTOMODE_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <memory>
#include <QLabel>
#include <QPushButton>


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
    QClipboard* clipboard;
    QLabel *indicator;
    QLabel *statusLabel;
    QPushButton *continueButton;
    QMovie *spinner;
    QPixmap pixmap;
    bool continueEnabled;
private slots:
    void clipboard_changed();
};

#endif // AUTOMODE_H
