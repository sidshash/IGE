#pragma once
#include <string>
#include <fstream>
#include <filesystem>
#include <Core.h>
#include <Windows.h>
class Script;
typedef ScriptBehaviour* (*CreateScriptInstanceFunc)();

class ScriptAPI {
private:

public:
    static void CompileScript(const std::string path, const std::string name) {
        Logger::Log(LogLevel::Info, std::string("Compiling Script: " + name).c_str(), "ScriptAPI");
        std::string command =
            "cmd /c \""
            "call \"C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Auxiliary\\Build\\vcvars64.bat\" && "
            "cl /LD /std:c++20 "
            "/Fo:" + path + name + ".obj " +
            "/Fe:" + path + name + ".dll " +
            path + name + ".cpp" + " /I..\\Core\\src /link /LIBPATH:..\\x64\\Debug Core.lib\"";
        int result = std::system((command /*+" >nul 2>&1"*/).c_str());
        std::filesystem::remove(path + name + ".obj");
        std::filesystem::remove(path + name + ".lib");
        std::filesystem::remove(path + name + ".exp");
        Logger::Log(LogLevel::Info, "Script Compiled", "Script API");
    }
    static void CreateScript(const std::string& name) {
        std::string folderPath = "src/Assets/Scripts/";

        if (!std::filesystem::exists(folderPath)) {
            std::filesystem::create_directories(folderPath);
        }

        std::string filePath = folderPath + name + ".cpp";

        std::string content =
            "#include <Core.h>\n"
            "\n"
            "class " + name + " : public ScriptBehaviour {\n"
            "public:\n"
            "    void OnStart() override {\n"
            "        // This code runs on instantiation\n"
            "    }\n"
            "\n"
            "    void OnUpdate() override {\n"
            "        // This code runs on update\n"
            "    }\n"
            "\n"
            "    void OnFixedUpdate() override {\n"
            "        // This code runs on fixed update\n"
            "    }\n"
            "};\n"
            "\n"
            "extern \"C\" __declspec(dllexport) ScriptBehaviour* CreateScriptInstance() {\n"
            "    return new " + name + "();\n"
            "}\n";

        std::ofstream outFile(filePath, std::ios::binary);
        if (outFile.is_open()) {
            outFile << content;
            outFile.close();
        }
        else {
            printf("Failed to open file: %s\n", filePath.c_str());
        }
        CompileScript(folderPath, name);
    }
    static HMODULE LoadScript(const std::string name) {
        std::string path = "src/Assets/Scripts/" + name + ".dll";
        HMODULE hModule = LoadLibraryA(path.c_str());
        if (!hModule) {
            Logger::Log(LogLevel::Error, std::string("Could not load "+ name + ".dll").c_str(), "ScriptAPI");
            return nullptr;
        }



        //delete script;
        return hModule;
    }

    static ScriptBehaviour* CreateBehaviour(HMODULE hModule) {

        auto createFunc = (CreateScriptInstanceFunc)GetProcAddress(hModule, "CreateScriptInstance");
        if (!createFunc) {
            std::cerr << "\n";
            Logger::Log(LogLevel::Error, std::string("Could not find factory function").c_str(), "ScriptAPI");
            return nullptr;
        }


        ScriptBehaviour* script = createFunc();

        return script;
    }

    static void DestroyScript(HMODULE hModule) {
        FreeLibrary(hModule);
    }
    

    //TODO: RELOAD ON FILE UPDATE
    static void Reload(Script* script);
};

