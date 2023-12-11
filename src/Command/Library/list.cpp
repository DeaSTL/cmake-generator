#include <Frate/Command/Library.hpp>

namespace Frate::Command::Library{
  bool list(Interface* inter){
    for(std::string& lib : inter->pro->libs){
      std::cout << lib << std::endl;
    }
    return true;
  }
}