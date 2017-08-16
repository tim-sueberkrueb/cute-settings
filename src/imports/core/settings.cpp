#include <QFile>
#include <QJsonDocument>
#include <QDebug>

#include "settings.h"

namespace CuteSettings
{
    Settings::Settings(QObject *parent) : Category(parent)
    {

    }

    Settings::~Settings()
    {
        if (_saveOnDestruction) {
            save();
        }
    }

    QString Settings::filePath() const
    {
         return _filePath;
    }

    void Settings::setFilePath(const QString &filePath)
    {
        if (filePath != _filePath) {
            filePathChanged(_filePath = filePath);
        }
    }

    bool Settings::loadOnCompleted() const
    {
        return _loadOnCompleted;
    }

    void Settings::setLoadOnCompleted(bool loadOnCompleted)
    {
        if (loadOnCompleted != _loadOnCompleted) {
            loadOnCompletedChanged(_loadOnCompleted = loadOnCompleted);
        }
    }

    bool Settings::saveOnDestruction() const
    {
        return _saveOnDestruction;
    }

    void Settings::setSaveOnDestruction(bool saveOnDestruction)
    {
        if (saveOnDestruction != _saveOnDestruction) {
            saveOnDestructionChanged(_saveOnDestruction = saveOnDestruction);
        }
    }

    void Settings::componentComplete()
    {
        Category::componentComplete();
        if (_loadOnCompleted) {
            load();
        }
    }

    bool Settings::load()
    {
        QFile file(_filePath);
        if (!file.open(QIODevice::ReadOnly)) {
            qWarning() << "Could not open file" << _filePath << "for read";
            return false;
        }
        auto content = file.readAll();
        auto doc = QJsonDocument::fromJson(content);
        if (doc.isNull()) {
            qWarning() << "Invalid JSON in file" << _filePath;
            return false;
        }
        loadJsonObject(doc.object(), true);
        setDirty(false);
        file.close();
        return true;
    }

    bool Settings::save()
    {
        QFile file(_filePath);
        if (!file.open(QIODevice::WriteOnly)) {
            qWarning() << "Could not open file" << _filePath << "for write";
            return false;
        }
        QJsonDocument doc;
        doc.setObject(saveJsonObject(true));
        file.write(doc.toJson());
        file.close();
        setDirty(false);
        return true;
    }

    bool Settings::loadString(const QString &jsonString)
    {
        QByteArray bytes = jsonString.toUtf8();
        QJsonDocument doc = QJsonDocument::fromJson(bytes);
        if (doc.isNull()) {
            qWarning() << "Failed to load invalid JSON string";
            return false;
        }
        loadJsonObject(doc.object());
        setDirty(false);
        return true;
    }

    QString Settings::saveString()
    {
        QJsonDocument doc;
        doc.setObject(saveJsonObject(true));
        setDirty(false);
        return QString::fromUtf8(doc.toJson());
    }
}
