#ifndef SETTINGUPDATE_H
#define SETTINGUPDATE_H

#include <QSettings>
#include <QVariant>
#include <QDir>
#include <QFile>


class SettingUpdate
{
public:
    static void SaveSetting(QString Group, QString Key, QString value);
    static void LoadSetting(QString Group, QString Key, QString value);
    static void Initialization(char *argv[], const size_t n);
    SettingUpdate();
};

#endif // SETTINGUPDATE_H
