#ifndef THALES_COMMAND_LINE_PARSER_HPP_
#define THALES_COMMAND_LINE_PARSER_HPP_

#include <vector>
#include <string>
#include <tuple>
#include <utility>

class CommandLineParser {

  public:

    CommandLineParser(void) = delete;
    CommandLineParser(std::string);
    void AddArgument(std::string short_name, std::string long_name, std::string description);
    void PrintArguments(void) const;

  protected:

  private:

    std::vector<std::tuple<std::string, std::string, std::string>> arguments_;
    const std::string description_;


};

#endif