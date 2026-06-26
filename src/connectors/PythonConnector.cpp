#include "hub/LanguageConnectors/PythonConnector.hpp"
#include <string>
#include <filesystem>


ExecutionConfig PythonConnector::prepare(const std::filesystem::path& sourcePath) {
    ExecutionConfig config;
    config.compileCommand = "";
    config.runCommand = "python3 " + sourcePath.string() + " 2>&1";

    return config;
}