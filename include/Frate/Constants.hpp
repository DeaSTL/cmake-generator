#pragma once
#include <filesystem>
#include <string>
#include <vector>

namespace Frate::Constants {

#ifdef __linux__
  const std::string BUILD_OS = "linux";
#elif _WIN32
  const std::string BUILD_OS = "windows32";
#elif _WIN64
  const std::string BUILD_OS = "windows64";
#elif __APPLE__ const std::string BUILD_OS = "macos";
#else
  const std::string BUILD_OS = "unknown";
#endif

  const std::string NAME = "frate";
  const std::string DESCRIPTION =
      "CLI utility for managing your project, a modern touch for C/C++";
  const std::string PROJECT_URL = "https://github.com/frate-dev/frate";

  const std::string PACKAGE_INDEX_URL =
      "https://github.com/frate-packages/index/releases/latest/download/"
      "index.json";
  const std::string TEMPLATE_INDEX_URL =
      "https://github.com/frate-templates/templates/releases/latest/download/"
      "index.json";

  const std::string TEMPLATE_PATH = "template/";
  const std::string TEMPLATE_CALLBACKS_PATH = "frate-callbacks/";
  const std::string INIT_SCRIPTS_PATH = "__init__/";
  const std::string POST_SCRIPTS_PATH = "__post__/";

  const std::string config_name = "config.json";

#ifdef _WIN64
  const std::filesystem::path CONFIG_DIR =
      std::filesystem::path(getenv("APPDATA")) / NAME;
  const std::filesystem::path LOCAL_DIR =
      std::filesystem::path(getenv("LOCALAPPDATA")) / NAME;
#else
  const std::filesystem::path CONFIG_DIR =
      std::filesystem::path(getenv("HOME")) / ".config" / NAME;
  const std::filesystem::path LOCAL_DIR =
      std::filesystem::path(getenv("HOME")) / ".local" / "share" / NAME;
#endif

  const std::filesystem::path CONFIG_PATH = CONFIG_DIR / config_name;

  const std::filesystem::path INSTALLED_TEMPLATE_PATH =
      LOCAL_DIR / "templates/";

  const std::filesystem::path INSTALLED_TEMPLATE_CONFIG_PATH =
      LOCAL_DIR / "installed_templates.json";

  const std::filesystem::path TEMPLATE_INDEX_PATH =
      LOCAL_DIR / "template_index.json";

  const std::filesystem::path PACKAGE_INDEX_PATH =
      LOCAL_DIR / "package_index.json";

#ifdef BRANCH_DEV
  const std::string TEMPLATE_BRANCH = "dev";
#else
  const std::string TEMPLATE_BRANCH = "main";
#endif

  const std::string VERSION =
      std::to_string(VMAJOR) + "." + std::to_string(VMINOR) + "." +
      std::to_string(VPATCH)
#ifdef VBUILD
      // If VBUILD is defined, append it to the version string
      + "." + std::to_string(VBUILD)
#endif
      ;

  const std::vector<std::string> SUPPORTED_CMAKE_VERSIONS = {
      "3.0",  "3.1",  "3.2",  "3.3",  "3.4",  "3.5",  "3.6",  "3.7",
      "3.8",  "3.9",  "3.10", "3.11", "3.12", "3.13", "3.14", "3.15",
      "3.16", "3.17", "3.18", "3.19", "3.20", "3.21", "3.22", "3.23",
      "3.24", "3.25", "3.26", "3.27", "3.28",
  };

  const std::vector<std::string> SUPPORTED_C_COMPILERS = {
      "clang",
      "gcc",
      "icc",
      "msvc",
  };

  const std::vector<std::string> SUPPORTED_CXX_COMPILERS = {
      "clang++",
      "g++",
      "icpc",
      "msvc",
  };

  const std::vector<std::string> SUPPORTED_C_STANDARDS = {
      "89", "90", "99", "11", "17", "18", "2x",
  };

  const std::vector<std::string> SUPPORTED_CXX_STANDARDS = {
      "98", "03", "11", "1x", "14", "17", "20", "2x", "23",
  };

  const std::vector<std::string> SUPPORTED_LANGUAGES = {
      "c",
      "cpp",
  };
} // namespace Frate::Constants
