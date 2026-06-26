#include "runner/Runner.hpp"
#include "hub/LanguageConnectors/PythonConnector.hpp"
#include <iostream>

int main() {
    PythonConnector connector;
    Runner runner;
    ExecutionConfig config = connector.prepare("script.py");

    std::cout << "[IDE Test] Generated Run Command: " << config.runCommand << std::endl;

    // Передаем конфигурацию в Раннер на запуск
    std::cout << "[IDE Test] Executing..." << std::endl;
    runner.Run(config);

    return 0;
}