#ifndef MACROSETTINGS_H
#define MACROSETTINGS_H

#include <QDialog>
#include <QSettings>
#include <QTimer>

namespace Ui {
class MacroSettings;
}

class MacroSettings : public QDialog
{
    Q_OBJECT

public:
    explicit MacroSettings(QWidget *parent = nullptr);
    ~MacroSettings();

    void settingsLoad( QSettings *settings );
    void settingsSave( QSettings *settings );

private:
    Ui::MacroSettings *ui;

    QList<QTimer *> listTimers;
    QTimer *listTimersFind( QString name);

private slots:
    //void  on_
    void on_sbTime_Mn_valueChanged(int arg1);

    void on_leCaption_Mn_textChanged(const QString &arg1);
    void on_PushButtonRun_click();
    void on_SpinBoxTime_valuchanged(int arg);
    void on_CheckBoxTime_stateChanged(int);

signals:
    void on_macroRun(QString macro);
    void on_macroBtnNameChange(QString name, QString text);

};

#endif // MACROSETTINGS_H
