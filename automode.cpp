#include "automode.h"
#include "ui_automode.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QUrl>
#include <QMovie>
#include <QClipboard>
#include <QGuiApplication>
#include <CourseScanner.h>
automode::automode(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::automode)
{
    mediaPlayer = std::make_unique<QMediaPlayer>();
    playlist = std::make_unique<QMediaPlaylist>();
    playlist->addMedia(QUrl("qrc:///res/selectionexample.mov"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    mediaPlayer->setPlaylist(playlist.get());
    ui->setupUi(this);
    videoWidget = findChild<QVideoWidget*>("videoPlayer");
    mediaPlayer->setVideoOutput(videoWidget);
    mediaPlayer->play();
    auto lbl = findChild<QLabel*>("indicator");
    QMovie *movie = new QMovie(":/res/spinner.gif");
    movie->setScaledSize({30,30});
    lbl->setMovie(movie);
    lbl->show();
    movie->start();
    auto clipboard = QGuiApplication::clipboard();
    connect(clipboard,&QClipboard::dataChanged,this,&automode::clipboard_changed);
}

void automode::clipboard_changed(){
    auto clipboard = QGuiApplication::clipboard();
    const auto clipText = clipboard->text().toStdString();
}

automode::~automode()
{
    delete ui;
}
