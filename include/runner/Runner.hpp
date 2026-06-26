#pragma once
#include "core/LangConnector.hpp"
#include <filesystem>
#include <string>

class Runner {
public:
    void Run(const ExecutionConfig& config, const std::filesystem::path& inputFile = {}, const std::filesystem::path& outputFile = {}, int timeLimitSeconds = 2);
};