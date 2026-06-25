#include <iostream>
#include <string>
#include <cstdio>


std::string run_code_mvp(const std::string& executable_path, const std::string& lang) {
    std::string command = "";

    if (lang == "cpp") {
        std::string out_file = "./compiled_binary";
        command = "g++ " + executable_path + " -o " + out_file + " 2>&1 && ./" + out_file + " 2>&1";
    } else if (lang == "python") {
        command = "python3 " + executable_path + " 2>&1";
    }


    FILE* pipe = popen(command.c_str(), "r");
    if(!pipe) {
        return "error";
    }


    std::string result = "";
    char buffer[128];
    
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        result += buffer;
    }
    pclose(pipe);

    
    return result;
}


int main() {
    std::cout << run_code_mvp("main.cpp", "cpp");
    return 0;
}