#include "settingupdate.h"
#include <QDebug>
SettingUpdate::SettingUpdate() :
sett(new QSettings(QDir::currentPath() + "/config.ini", QSettings::IniFormat))
{
    sett->setIniCodec("UTF-8");
}
void SettingUpdate::Initialization(){
    QString filename = QDir::currentPath() + "/config.ini";
    QFile file(filename);

    if (!file.exists()){
        file.open(QFile::WriteOnly | QFile::Text);
        file.close();
    }

}
QString SettingUpdate::LoadSetting(QString Group, QString Key){
    QString value;
    sett->beginGroup(Group);
    value = sett->value(Key).toString();
    sett->endGroup();
    return value;
}
void SettingUpdate::RemoveSetting(QString Group){
    sett->remove(Group);
}

void SettingUpdate::SaveSetting(QString Group, QString Key, QString value){
    sett->beginGroup(Group);
    sett->setValue(Key, value);
    sett->endGroup();
}

QStringList SettingUpdate::getGroup(){
    return sett->childGroups();
}
