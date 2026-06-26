#include "connectors/CppConnector.hpp"
#include <string>
#include <filesystem>


ExecutionConfig CppConnector::prepare(const std::filesystem::path& sourcePath) {
    ExecutionConfig config;
    std::filesystem::path outputPath = sourcePath.parent_path() / "output";
    std::string compileCommand = "g++ -std=c++20 \"" + sourcePath.string() + "\" -o \"" + outputPath.string() + "\"";

    config.BuildPipeline = {compileCommand};
    config.RunCommand = "\"" + outputPath.string() + "\"";

    return config;
}