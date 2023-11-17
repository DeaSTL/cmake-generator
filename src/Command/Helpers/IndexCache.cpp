#include "../Command.hpp"
#include <nlohmann/json.hpp>
#include "../../Utils/General.hpp"

namespace Command{
  using nlohmann::json;
  using std::cout;
  using std::ifstream;
  using std::ofstream;
  using std::string;
  using std::filesystem::create_directories;
  std::string indexFileName =
    std::string(std::getenv("HOME")) + "/.local/cmaker/index.json";
  std::string indexUrl =
    "https://github.com/cmaker-dev/index/releases/latest/download/index.json";
  /*
   * If index is not in path then we create one
   * returns fetched index
   */
  json fetchIndex() {
    json index;
    if (std::filesystem::exists(indexFileName)) {

      ifstream indexFile;
      indexFile = std::ifstream(indexFileName);
      index = json::parse(indexFile);
      std::cout << "index file exists" << ENDL;

    } else {
      ofstream indexFile;
      cout << "Creating a new index file" << ENDL;

      try {
        create_directories(string(std::getenv("HOME")) + "/.local/cmaker");
      }catch(std::exception& e){
        std::cout << "Failed to create index file" << ENDL;
        exit(-1);
      }

      index = Utils::fetchJson(indexUrl);
      indexFile = std::ofstream(indexFileName);
      indexFile << index.dump(2);
      std::cout << "index file created" <<ENDL;

    }

    return index;
  }
  /*
   * Very similar to the fetch index function but this one will always update the index
   * TODO: Add a check to see if the index is up to date
   * TODO: Add this to the interface caching the index in memory
   */
  void updateIndex(){
    std::ofstream indexFile;

    try{

      //Checks if the index file exists
      indexFile = std::ofstream(indexFileName);

    }catch(std::exception& e){

      std::cout << "Creating a new index file" << ENDL;

      try{

        create_directories(string(std::getenv("HOME")) + "/.local/cmaker");

      }catch(std::exception& e){

        std::cout << "Failed to create index file" << ENDL;
        exit(-1);

      }

      std::ifstream indexFile(indexFileName);
    }

    json data = Utils::fetchJson(indexUrl);
    indexFile << data.dump(2);
  }
  std::pair<bool,Package> getExactPackage(std::string package_name){

    json index = fetchIndex();

    for(auto package : index){

      if(package["name"] == package_name){

        Package p;
        p.name = package["name"];
        p.versions = package["versions"];
        p.git = package["git"];
        p.description = package["description"];
        return std::pair<bool,Package>{true,p};

      }
    }
    return std::pair<bool,Package>{false,Package{}};
  }
}