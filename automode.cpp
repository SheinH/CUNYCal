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
    ui(new Ui::automode),
    clipboard(QGuiApplication::clipboard()),
    continueEnabled{false}
{
    ui->setupUi(this);
    pixmap.load(":/res/check.png");
    indicator = findChild<QLabel*>("indicator");
    statusLabel = findChild<QLabel*>("statusLabel");
    continueButton = findChild<QPushButton*>("continueButton");
    mediaPlayer = std::make_unique<QMediaPlayer>();
    playlist = std::make_unique<QMediaPlaylist>();
    playlist->addMedia(QUrl("qrc:///res/selectionexample.mov"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    mediaPlayer->setPlaylist(playlist.get());
    videoWidget = findChild<QVideoWidget*>("videoPlayer");
    mediaPlayer->setVideoOutput(videoWidget);
    mediaPlayer->play();
    spinner = new QMovie(":/res/spinner.gif");
    spinner->setScaledSize({30,30});
    indicator->setMovie(spinner);
    indicator->show();
    spinner->start();
    connect(clipboard,&QClipboard::dataChanged,this,&automode::clipboard_changed);
}

void automode::clipboard_changed(){
    auto clipboard = QGuiApplication::clipboard();
    const auto clipText = clipboard->text().toStdString();
    const auto valid = CourseScanner::isValidCourseString(clipText);
    set_continue_state(valid);
}

automode::~automode()
{
    delete ui;
}

void automode::set_continue_state(bool enabled) {
    if(enabled == continueEnabled)
        return;
    if(enabled){
//        indicator->setpi
        indicator->setPixmap(pixmap);
        statusLabel->setText("Schedule Loaded!");
        continueButton->setEnabled(true);
    }
    else{
        indicator->setMovie(spinner);
        statusLabel->setText("Scanning Clipboard...");
        continueButton->setEnabled(false);
    }
    continueEnabled = enabled;
}
