#include "macrosettings.h"
#include "ui_macrosettings.h"

//enum {
//    id_sbTime =0,
//};

//void setTimer( QTimer *tm, )

MacroSettings::MacroSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MacroSettings)
{
    ui->setupUi(this);

    // load from setting

    listTimers.clear();
    // sbTime_M1
    foreach(QObject *o, children() )
    {
        QString name = o->objectName();
        //QStringList sl = name.split("_")
        if ( name.startsWith("sbTime_M") ) {
            QSpinBox *sb = dynamic_cast<QSpinBox *>(o);
            if ( sb == nullptr ) continue;
            QTimer *tm  = new QTimer();
            tm->setInterval( sb->value() );
            tm->setProperty( "id_sbTime", QVariant( qlonglong(o) );
            listTimers.push_back(tm);
            connect( sp, &QSpinBox::valueChanged, this, &MacroSettings::on_SpinBoxTime_valuchanged );
            continue;
         }
//       if (isChildWidgetOfAnyLayout((QLayout*)o,widget))
//          return true;
        if ( name.startsWith("pbRun_M") ) {
            QPushButton *pb = dynamic_cast<QPushButton *>(o);
            if ( pb == nullptr ) continue;
            connect( pb, &QPushButton::click, this, &MacroSettings::on_PushButtonRun_click );
            continue;
        }

        if ( name.startsWith("cbRepeat_M") ) {
            QCheckBox *sb = dynamic_cast<QCheckBox *>(o);
            if ( sb == nullptr ) continue;
            QTimer *tm = listTimersFind( "sbTime_" +sl[1] );
            if ( sb ->isChecked() )
                tm->start();
            else
                tm->stop();
            connect( sb, &QCheckBox::stateChanged, this, &MacroSettings::on_CheckBoxTime_stateChanged );
            continue;
        }

    }
//    on_leCaption_Mn_textChanged
}

MacroSettings::~MacroSettings()
{
    delete ui;
}

void MacroSettings::settingsLoad(QSettings *settings)
{
#if 0
    QWidgetList *wl = parentWidget->findChildren<QWidget *>();
    for( int i = 0; i < wl.length(); i++ ) {

    }
#endif
}

void MacroSettings::settingsSave(QSettings *settings)
{
    foreach(QObject *o, children() )
    {
        QString name = o->objectName();
        //QStringList sl = name.split("_")
        QLineEdit *le = dynamic_cast<QLineEdit *>(o);
        if ( le != nullptr ) {
            settings->value(name, le->text() );
            continue;
        }
        QSpinBox *sb = dynamic_cast<QSpinBox *>(o);
        if ( sb != nullptr ) {
            settings->value(name, sb->value() );
            continue;
        }

        QCheckBox *cb = dynamic_cast<QCheckBox *>(o);
        if ( cb != nullptr ) {
            settings->value(name, cb->isChecked() );
            continue;
        }
    }
}

QTimer *MacroSettings::listTimersFind(QString name)
{
    foreach( QTimer *tm, listTimers ) {
        if ( tm->property("id_sbTime") == name )
            return tm;
    }
    return nullptr;

}

void MacroSettings::on_sbTime_Mn_valueChanged(int arg1)
{
    QSpinBox *sb = dynamic_cast<QSpinBox *>(sender());
    if( pb == nullptr ) return;
}

void MacroSettings::on_leCaption_Mn_textChanged(const QString &arg1)
{
    QLineEdit *le = dynamic_cast<QLineEdit *>(sender());
    if( le == nullptr ) return;
    // "leCaption_M1"
    // "pbRun_M1"
    QString name = le->objectName();
    QString idx = name.split("_")[1];
    name = "pbRun_"+ idx;
    QPushButton *pb = findChild<QPushButton *>(name);
    if ( pb == nullptr ) return;
    pb->setText( le->text() );
    emit on_macroBtnNameChange( idx, le->text() );
}

void MacroSettings::on_PushButtonRun_click()
{
    QPushButton *pb = dynamic_cast<QPushButton *>(sender());
    if ( pb == nullptr ) return;
    QString name = pb->objectName();
    QStringList sl = name.split("_");
    // leMacro_M1
    QLineEdit *le = findChild<QLineEdit *>("leMacro_"+sl[1]);
    if ( le == nullptr ) return;
    emit on_macroRun(le->text() );
}

void MacroSettings::on_CheckBoxTime_stateChanged(int arg)
{
    QCheckBox *cb = dynamic_cast<QCheckBox *>(sender());
    if ( cb == nullptr ) return;
    QString name = cb->objectName();
    QStringList sl = name.split("_");
    // cbRepeat_M1
//    QLineEdit *le = findChild<QLineEdit *>("leMacro_"+sl[1]);
//    if ( le == nullptr ) return;
//    emit on_macroRun(le->text() );
    //
    QTimer *tm = listTimersFind( "sbTime_" +sl[1] );
    if ( tm == nullptr ) return;
    if ( arg )
        tm->start();
    else
        tm->stop();
}
