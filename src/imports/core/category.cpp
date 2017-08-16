#include <QDebug>
#include <QMetaObject>
#include <QMetaProperty>

#include "category.h"

namespace CuteSettings
{
    Category::Category(QObject *parent) : QObject(parent)
    {

    }

    QString Category::label() const
    {
        return _label;
    }

    void Category::setLabel(const QString &label)
    {
        if (label != _label) {
            labelChanged(_label = label);
        }
    }

    bool Category::dirty() const
    {
        return _dirty;
    }

    void Category::setDirty(bool dirty)
    {
        if (dirty != _dirty) {
            dirtyChanged(_dirty = dirty);
        }
    }

    QJsonObject Category::saveJsonObject(bool setClean)
    {
        QJsonObject jsonObject;

        const QMetaObject* metaObj = metaObject();
        const int offset = metaObj->propertyOffset();
        const int count = metaObj->propertyCount();

        for (int i = offset; i < count; i++) {
            QMetaProperty property = metaObj->property(i);
            QVariant var = property.read(this);
            if (var.userType() == qMetaTypeId<QJSValue>())
                var = var.value<QJSValue>().toVariant();
            if (var.canConvert<Category*>()) {
                auto category = var.value<Category*>();
                QString categoryName = QString::fromUtf8(property.name());
                jsonObject[categoryName] = category->saveJsonObject(setClean);
                if (setClean) {
                    category->setDirty(false);
                }
            } else if (var.canConvert<VarOption*>()) {
                auto option = var.value<VarOption*>();
                QString optionName = QString::fromUtf8(property.name());
                jsonObject[optionName] = option->saveJsonValue();
                if (setClean) {
                    option->setDirty(false);
                }
            }
        }
        return jsonObject;
    }

    void Category::loadJsonObject(const QJsonObject &jsonObject, bool setClean)
    {
        const QMetaObject* metaObj = metaObject();
        const int offset = metaObj->propertyOffset();
        const int count = metaObj->propertyCount();

        for (int i = offset; i < count; i++) {
            QMetaProperty property = metaObj->property(i);
            QVariant variant = property.read(this);
            if (variant.canConvert<Category*>()) {
                auto category = variant.value<Category*>();
                QString categoryName = QString::fromUtf8(property.name());
                if (jsonObject.contains(categoryName)) {
                    auto categoryJsonValue = jsonObject[categoryName];
                    if (categoryJsonValue.isObject()) {
                        category->loadJsonObject(categoryJsonValue.toObject(), setClean);
                        if (setClean) {
                            category->setDirty(false);
                        }
                    }
                    else {
                        qWarning() << "Expected JSON object for category" << categoryName;
                    }
                }
            } else if (variant.canConvert<VarOption*>()) {
                auto option = variant.value<VarOption*>();
                QString optionName = QString::fromUtf8(property.name());
                if (jsonObject.contains(optionName)) {
                    option->loadJsonValue(jsonObject[optionName]);
                    if (setClean) {
                        option->setDirty(false);
                    }
                }
            }
        }
    }

    void Category::resetDefaults(bool setClean)
    {
        const QMetaObject* metaObj = metaObject();
        const int offset = metaObj->propertyOffset();
        const int count = metaObj->propertyCount();

        for (int i = offset; i < count; i++) {
            QMetaProperty property = metaObj->property(i);
            QVariant variant = property.read(this);
            if (variant.canConvert<Category*>()) {
                auto category = variant.value<Category*>();
                category->resetDefaults(setClean);
                if (setClean) {
                    category->setDirty(false);
                }
            } else if (variant.canConvert<VarOption*>()) {
                auto option = variant.value<VarOption*>();
                option->setValue(option->defaultValue(), false);
                if (setClean) {
                    option->setDirty(false);
                }
            }
        }
    }

    void Category::classBegin() { /* Not doing anything here */ }

    void Category::componentComplete()
    {
        initialize();
    }

    void Category::initialize()
    {
        const QMetaObject* metaObj = metaObject();
        const int offset = metaObj->propertyOffset();
        const int count = metaObj->propertyCount();

        if (!_initialized) {
            for (int i = offset; i < count; i++) {
                QMetaProperty property = metaObj->property(i);
                QVariant variant = property.read(this);
                if (variant.canConvert<Category*>()) {
                    auto category = variant.value<Category*>();
                    connect(category, &Category::dirtyChanged,
                            this, &Category::childDirtyChanged);
                } else if (variant.canConvert<VarOption*>()) {
                    auto option = variant.value<VarOption*>();
                    connect(option, &VarOption::dirtyChanged,
                            this, &Category::childDirtyChanged);
                }
            }
            _initialized = true;
        }
    }

    void Category::childDirtyChanged(bool dirty)
    {
        if (dirty) {
            setDirty(true);
        }
    }
}
