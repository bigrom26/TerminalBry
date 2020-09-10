#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QLabel>
#include <QTimer>
#include <QSettings>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QSerialPort *m_serial = nullptr;
private:
    Ui::MainWindow *ui;

    QLabel *lTime       =nullptr;
    QLabel *lVersion    =nullptr;
    QLabel *lStatus     =nullptr;
    QTimer tick;

    QSettings settings;

private slots:
    void on_second(void);


};
#endif // MAINWINDOW_H
