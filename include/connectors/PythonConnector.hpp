#pragma once
#include "core/LangConnector.hpp"


class PythonConnector : public LangConnector {
public:
    virtual ExecutionConfig prepare(const std::filesystem::path& sourcePath) override;
};