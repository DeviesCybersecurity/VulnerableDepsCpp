#include <iostream>
#include <fstream>
#include <string>
#include <nlohmann/json.hpp>


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