#ifndef SETTINGUPDATE_H
#define SETTINGUPDATE_H

#include <QSettings>
#include <QVariant>
#include <QDir>
#include <QFile>



class SettingUpdate
{
public:
    void SaveSetting(QString Group, QString Key, QString value);
    void RemoveSetting(QString Group);
    QStringList getGroup();
    QString LoadSetting(QString Group, QString Key);
    void Initialization();
    SettingUpdate();

   private:
    QSettings *sett;
};

#endif // SETTINGUPDATE_H
