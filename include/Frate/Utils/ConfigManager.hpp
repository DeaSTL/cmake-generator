#include "Frate/Command.hpp"
namespace Frate::Config {
  //TODO: work in progress
  typedef struct ConfigManager_s {
    bool first_time_setup{false};
    std::string default_remote_server;
    std::vector<Command::RemoteServer> servers;
  } ConfigManager;
}