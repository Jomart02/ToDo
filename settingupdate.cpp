#include "settingupdate.h"
#include <QDebug>
SettingUpdate::SettingUpdate()
{

}
void SettingUpdate::Initialization(char *argv[], const size_t n){
    QString filename = QDir::currentPath() + "/config.ini";
    QFile file(filename);
    int i=0;
    qDebug() << file.exists();
    if (!file.exists()){
        file.open(QFile::WriteOnly | QFile::Text);

        QTextStream stream(&file);
        for(size_t i {}; i < n; i++)
        {
            stream << "[" << argv[i] << "]" << endl;
        }
        file.close();
    }

}

void SettingUpdate::LoadSetting(QString Group, QString Key, QString value){

    QSettings sett(QDir::currentPath() + "/config.ini", QSettings::IniFormat);
    sett.setIniCodec("UTF-8");
    sett.beginGroup("CONNECT");

    sett.endGroup();
}

void SettingUpdate::SaveSetting(QString Group, QString Key, QString value){
    QSettings sett(QDir::currentPath() + "/config.ini", QSettings::IniFormat);
    sett.setIniCodec("UTF-8");
    sett.beginGroup(Group);
    sett.setValue(Key, value);
    sett.endGroup();
}
