#pragma once
#include <string>
#include <filesystem>
#include <vector>


struct ExecutionConfig {
    std::vector<std::string> BuildPipeline;
    std::string RunCommand;
};


class LangConnector {
public:
    virtual ~LangConnector() = default;

    virtual ExecutionConfig prepare(const std::filesystem::path& sourcePath) = 0;
};