#include <iostream>
#include "Command.hpp"
#include "../Utils/CLI.hpp"

namespace Command{
  using Utils::CLI::Prompt;
  using namespace Utils::CLI::Ansi;
  bool Interface::ftp() {
    bool test = this->LoadPackageJson();
    if(!test) {
      std::cout << "Error: Could not load config.json" << std::endl;
      return false;
    }

    Prompt<bool> *prompt = new Prompt<bool>("Are you sure you would like to delete the entire project?");
    prompt->Run();
    if(!prompt->Get()) {
      std::cout << "Aborting..." << std::endl;
      return false;
    }

    Prompt<int> *prompt2 = new Prompt<int>("Enter the port number");
    prompt2->Validator([](int port) -> bool {
      return port > 0 && port < 65535;
    });
    prompt2->Run();
    int port = prompt2->Get();

    std::cout << "Starting FTP server on port " << port << std::endl;



    
  #ifdef DEBUG
    system("rm -rf ./build/*");
   #else
      system("rm -rf ./*");
    #endif // DEBUG
    return true;
  }
}
