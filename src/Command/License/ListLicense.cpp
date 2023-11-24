#include "nlohmann/json_fwd.hpp"
#include <Frate/Command/License.hpp>
#include <Frate/Utils/General.hpp>

namespace Command::License {
using nlohmann::json;

bool list(Interface *inter) {
  Utils::Info info;
  json github_licenses = Utils::fetchJson("https://api.github.com/licenses");

  for (License license : github_licenses) {
    info << license.name << std::endl;
  }

  return true;
  }
}
