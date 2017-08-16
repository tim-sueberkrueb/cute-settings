import qbs 1.0

Project {
    name: "tests"

    references: [
        "core/core.qbs"
    ]

    AutotestRunner {
        builtByDefault: project.testsEnabled
        name: "autotests"
    }
}
