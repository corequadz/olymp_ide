#pragma once
#include "core/LangConnector.hpp"


class CppConnector : public LangConnector {
public:
    virtual ExecutionConfig prepare(const std::filesystem::path& sourcePath) override;
};