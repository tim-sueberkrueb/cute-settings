#include "coreplugin.h"

#include <QtQml/qqml.h>

#include "settings.h"
#include "category.h"
#include "options/varoption.h"
#include "options/booloption.h"
#include "options/doubleoption.h"
#include "options/intoption.h"
#include "options/stringoption.h"
#include "options/scriptedoption.h"

using namespace CuteSettings;

CuteSettingsCorePlugin::CuteSettingsCorePlugin(QObject *parent) : QQmlExtensionPlugin(parent)
{

}

void CuteSettingsCorePlugin::registerTypes(const char *uri)
{
    Q_ASSERT(QLatin1String(uri) == QLatin1String("CuteSettings"));
    qmlRegisterType<Settings>(uri, 0, 1, "Settings");
    qmlRegisterType<Category>(uri, 0, 1, "Category");
    qmlRegisterType<VarOption>(uri, 0, 1, "VarOption");
    qmlRegisterType<BoolOption>(uri, 0, 1, "BoolOption");
    qmlRegisterType<IntOption>(uri, 0, 1, "IntOption");
    qmlRegisterType<DoubleOption>(uri, 0, 1, "DoubleOption");
    qmlRegisterType<StringOption>(uri, 0, 1, "StringOption");
    qmlRegisterType<ScriptedOption>(uri, 0, 1, "ScriptedOption");
}
