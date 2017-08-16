import qbs 1.0

DynamicLibrary {
    name: "core"
    consoleApplication: false

    cpp.cxxLanguageVersion: "c++11"
    cpp.visibility: "minimal"
    cpp.defines: [
        "QT_NO_CAST_FROM_ASCII",
        "QT_NO_CAST_TO_ASCII"
    ]

    Qt.core.resourcePrefix: "/"
    Qt.core.resourceSourceBase: "../src"

    targetName: "cutesettingscoreplugin"

    Depends { name: "Qt"; submodules: ["qml", "quick"] }

    FileTagger {
        patterns: ["qmldir", "*.qmltypes"]
        fileTags: ["qml"]
    }

    Group {
        qbs.install: true
        qbs.installDir: "qml/CuteSettings"

        fileTagsFilter: ["debuginfo", "dynamiclibrary", "qml"]
    }

     files: ["*.cpp", "*.h", "qmldir", "*.qmltypes", "options/*.cpp", "options/*.h"]
}
