#include <iostream>
#include <fstream>
#include <string>
#include <nlohmann/json.hpp>

//https://medium.com/@dexterchan_44737/visual-studio-code-build-and-debug-a-c-with-cmake-on-mac-os-7633bc59bf34
//https://code.visualstudio.com/docs/cpp/CMake-linux

//https://github.com/nlohmann/json
//https://github.com/eclipse/mosquitto
//https://github.com/iDoka/awesome-canbus


//SBOM in ubuntu & debian :  https://discourse.ubuntu.com/t/creating-a-software-bill-of-materials-sbom/25519

//https://security.snyk.io/vuln/SNYK-UNMANAGED-POCOPROJECTPOCO-2404465

using json = nlohmann::json;

int main(void) {
    std::cout << "Reading config.\n";
    try {
        std::ifstream f("config.json");
        json data = json::parse(f);

        for (auto& [key, value] : data.items()) {
            std::cout << key << " : " << value << "\n";
        }

    }
    catch(const std::ifstream::failure& e) {
        std::cout << "Error " << e.what();
    }
    catch(const nlohmann::detail::parse_error &pe){
        std::cout << "Error " << pe.what();
    }
    return 0;
}