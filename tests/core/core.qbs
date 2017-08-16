import qbs 1.0

QtGuiApplication {
    name: "test_core"
    condition: project.testsEnabled
    type: base.concat(["autotest"])

    Depends { name: "Qt"; submodules: ["gui", "testlib", "qmltest"] }

    files: ["*.cpp", "*.qml"]
}
