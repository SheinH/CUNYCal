#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ScheduleRegex.h"
#include "let.h"
#include <QClipboard>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("CUNYCal");

    this->window()->winId(); // create window->windowhandle()
    let clipboard = QGuiApplication::clipboard();
    connect(clipboard, &QClipboard::dataChanged, this, &MainWindow::handleClipboardChange);
    handleClipboardChange();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleClipboardChange() {
    let &clipboard = QGuiApplication::clipboard()->text();
    let valid = CourseScanner::isValidCourseString(clipboard.toStdString());
    let child = MainWindow::findChild<QRadioButton *>("clipRadioButton");
    let def = MainWindow::findChild<QRadioButton *>("manualEntryButton");
    if(valid){
        child->setEnabled(true);
    }
    else{
        child->setChecked(false);
        child->setEnabled(false);
        def->setChecked(true);
    }
}
