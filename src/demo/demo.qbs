import qbs 1.0

QtGuiApplication {
    name: "demo"
    targetName: "cutesettings-demo"
    condition: project.withDemo
    consoleApplication: false

    Depends { name: "Qt"; submodules: ["gui", "qml", "quick", "quickcontrols2"]; versionAtLeast: "5.8" }

    cpp.defines: [
        "QT_NO_CAST_FROM_ASCII",
        "QT_NO_CAST_TO_ASCII"
    ]

    files: ["*.cpp", "*.qrc"]

    Group {
        name: "QML Files"
        files: [
            "qml/*",
        ]
        fileTags: ["qml", "qt.core.resource_data"]
    }

    Group {
        qbs.install: true
        qbs.installDir: "bin"
        fileTagsFilter: ["application"]
    }
}
