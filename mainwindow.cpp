#include "mainwindow.h"
#include "ui_mainwindow.h"
#if 0
QSettings *Settings(QString firm =nullptr, QString fileName =nullptr )
{
//    QSettings *Result = new QSettings(XmlFormat, QSettings::UserScope, firm, fileName );
    QSettings *Result = new QSettings(firm, fileName );
    return Result;
}
#endif

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , lTime(new QLabel())
    , lVersion(new QLabel())
    , lStatus(new QLabel())
{
    ui->setupUi(this);

    lTime->setText("00:00:00");
    lTime->setStyleSheet( "font-size:10pt;  padding: 2px; font-weight: bold;" );
    lVersion->setText(FileVersionInfo("FileVersion" ));
    lStatus->setStyleSheet( "font-size:10pt; padding: 2px; 2px; font-weight: bold;" );

    statusBar()->addWidget(lTime);
    statusBar()->addWidget(lVersion);
    statusBar()->addWidget(lStatus);

    connect( &tick, SIGNAL(timeout()), this, SLOT(on_second()) );
    tick.start(1000);

//    settings = QSettings();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_second(void)
{
    lTime->setText( QTime::currentTime().toString("hh:mm:ss"));
}
