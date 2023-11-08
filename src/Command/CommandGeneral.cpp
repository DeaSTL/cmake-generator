#include "Command.hpp"
#include <cstddef>
#include <format>
#include <iostream>

namespace Command {
  bool Interface::LoadPackageJson() {
    using nlohmann::json;
    std::fstream file;
    try {
      std::cout << "Project path: " << pro->project_path << std::endl;
      std::string file_name = "config.json";
      file = std::fstream((pro->project_path / file_name).string());
      json data = json::parse(file);
      pro->fromJson(data);
      //Simplfied this fucking code
    } catch (json::exception &e) {
      std::cout << "Error: Could not load config.json" << std::endl;
      return false;
    }
    file.close();

    return true;
  };

} // namespace Command
