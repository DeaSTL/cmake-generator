#include "Frate/Utils/General.hpp"
#include <Frate/Command.hpp>
#include <fstream>
#include <iostream>

namespace Frate::Command {
  bool Interface::LoadProjectJson() {
    using nlohmann::json;
    std::fstream file;
    std::string file_name = "frate-project.json";

    if(project_present) return true;


    Frate::info << "Loading: " << (pro->project_path / file_name) << std::endl;
    try{
      file.open((pro->project_path / file_name).string());
    }catch(std::exception &e){
      Frate::error << e.what() << std::endl;
      Frate::error << "Error: Could not open: " << (pro->project_path / file_name) << std::endl;
      return false;
    }
    json data;
    try {
      json data = json::parse(file);
      pro->checkKeys(data);
      pro->fromJson(data);
      //Simplfied this fucking code
    } catch (json::exception &e) {
      Frate::error << e.what() << std::endl;
      Frate::error << "Error: Could not load: " << (pro->project_path / file_name) << std::endl;
      return false;
    }
    file.close();
    project_present = true;
    return true;
  };
} // namespace Command
