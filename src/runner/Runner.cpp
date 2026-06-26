#include "runner/Runner.hpp"
#include <cstdlib>
#include <iostream>


void Runner::Run(const ExecutionConfig& config) {
    if (!config.compileCommand.empty()) {
        std::system(config.compileCommand.c_str());
    }
    std::system(config.runCommand.c_str());
}