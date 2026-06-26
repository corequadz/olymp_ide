#include "runner/Runner.hpp"
#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/resource.h>

void Runner::Run(const ExecutionConfig &config, const std::filesystem::path &inputFile, const std::filesystem::path &outputFile, int timeLimitSeconds)
{
    for (const std::string &step : config.BuildPipeline)
    {
        int compile_step = std::system(step.c_str());
        if (compile_step != 0)
        {
            std::cerr << "Error with exit code " << compile_step << std::endl;
            return;
        }
    }
    std::cout << "Running program" << std::endl;
    pid_t pid = fork();
    if (pid < 0)
    {
        std::perror("Runtime error");
        return;
    }
    else if (pid == 0)
    {
        if (!inputFile.empty())
        {
            int in_fd = open(inputFile.c_str(), O_RDONLY);
            if (in_fd < 0)
            {
                std::perror("Input error");
                exit(1);
            }

            dup2(in_fd, STDIN_FILENO);
            close(in_fd);
        }

        if (!outputFile.empty())
        {
            int out_fd = open(outputFile.c_str(), O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (out_fd < 0)
            {
                std::perror("Output error");
                exit(1);
            }
            dup2(out_fd, STDOUT_FILENO);
            close(out_fd);
        }

        if (timeLimitSeconds > 0)
        {
            struct rlimit rl;
            rl.rlim_cur = timeLimitSeconds;
            rl.rlim_max = timeLimitSeconds;
            if (setrlimit(RLIMIT_CPU, &rl) < 0)
            {
                std::perror("time limit failed");
                exit(1);
            }
        }
        execl("/bin/sh", "sh", "-c", config.RunCommand.c_str(), nullptr);
        std::perror("execl failed");
        exit(1);
    }

    else
    {
        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status))
        {
            int exit_code = WEXITSTATUS(status);
            if (exit_code != 0)
            {
                std::cerr << "Runtime Error (Exit code: " << exit_code << ")" << std::endl;
            }
            else
            {
                std::cout << "OK" << std::endl;
            }
        }
        else if (WIFSIGNALED(status))
        {
            int sig = WTERMSIG(status);
            if (sig == SIGXCPU)
            {
                std::cerr << "Time Limit Exceeded" << std::endl;
            }
            else
            {
                std::cerr << "Runtime Error (Crashing signal: " << sig << ")" << std::endl;
            }
        }
    }
}