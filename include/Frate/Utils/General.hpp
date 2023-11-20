#pragma once
#include <string>
#include <vector>
#include <nlohmann/json.hpp>
#include <iomanip>
#include <iostream>
#define DEBUGTHIS(x) std::cout << "##x" << " -> " << x << std::endl;

#ifdef DEBUG
#include <cpptrace/cpptrace.hpp>
#endif

#ifdef TEST 
#include <cpptrace/cpptrace.hpp>
#endif


namespace Utils {
  using nlohmann::json;
  std::string getFolderName();
  /*
   * Split the string by the delimiter
   * @param str The string to be splitted
   * @param delimiter The delimiter to be splitted by
   * @return The vector of splitted string
   */
  std::vector<std::string> split(std::string str, char delimiter);
  /*
   * Convert the string to lower case
   * @param str The string to be converted
   */
  void toLower(std::string& str);
  /*
   * Fetch the json from the url
   * @param url The url to be fetched
   * @return The json fetched from the url
   */
  json fetchJson(std::string url);
  /*
   * Fetch the text from the url
   * @param url The url to be fetched
   * @return The text fetched from the url
   */
  std::string fetchText(std::string url);
  /*
   * A new Utils::hSystem command which returns the exit code of the command
   * And we also take std::string
   * @param command The command to be executed
   * @return The exit code of the command
   */
  int hSystem(std::string command);
  struct TableFormat {
      int width;
      char fill;
      TableFormat(): width(14), fill(' ') {}
      template<typename T>
      TableFormat& operator<<(const T& data) {
          std::cout<<  std::setw(width) << data << std::setfill(fill);
          return *this;
      }
  };
  /*
   * FUCKING MAGIC
   */
  int levensteinDistance(std::string aStr, std::string bStr);
  int getStringScore(std::string &text, std::string &query);


  /*
   * Debug stuff
   */
  void debug(std::string something);
}
