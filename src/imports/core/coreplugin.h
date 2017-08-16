#ifndef COREPLUGIN_H
#define COREPLUGIN_H

#include <QQmlExtensionPlugin>

class CuteSettingsCorePlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)
public:
    explicit CuteSettingsCorePlugin(QObject *parent = nullptr);

    void registerTypes(const char *uri) override;
};

#endif // COREPLUGIN_H
