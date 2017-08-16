#ifndef CUTESETTINGS_H
#define CUTESETTINGS_H

#include "category.h"

namespace CuteSettings
{
    class Settings : public Category
    {
        Q_OBJECT

        Q_PROPERTY(QString filePath READ filePath WRITE setFilePath NOTIFY filePathChanged)
        Q_PROPERTY(bool loadOnCompleted READ loadOnCompleted WRITE setLoadOnCompleted NOTIFY loadOnCompletedChanged)
        Q_PROPERTY(bool saveOnDestruction READ saveOnDestruction WRITE setSaveOnDestruction NOTIFY saveOnDestructionChanged)

    public:
        explicit Settings(QObject *parent = nullptr);
        ~Settings();

        QString filePath() const;
        void setFilePath(const QString& filePath);

        bool loadOnCompleted() const;
        void setLoadOnCompleted(bool loadOnCompleted);

        bool saveOnDestruction() const;
        void setSaveOnDestruction(bool saveOnDestruction);

        void componentComplete() override;

        Q_INVOKABLE bool load();
        Q_INVOKABLE bool save();

        Q_INVOKABLE bool loadString(const QString& jsonString);
        Q_INVOKABLE QString saveString();

    signals:
        void filePathChanged(const QString& filePath);
        void loadOnCompletedChanged(bool loadOnCompleted);
        void saveOnDestructionChanged(bool saveOnDestruction);

    private: // members
        QString _filePath;
        bool _loadOnCompleted = false;
        bool _saveOnDestruction = false;
    };
}

#endif // CUTESETTINGS_H
