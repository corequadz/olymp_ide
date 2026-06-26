#pragma once
#include <string>
#include <filesystem>


struct ExecutionConfig {
    std::string compileCommand;
    std::string runCommand;
};


class LangConnector {
public:
    virtual ~LangConnector() = default;

    virtual ExecutionConfig prepare(const std::filesystem::path& sourcePath) = 0;
};