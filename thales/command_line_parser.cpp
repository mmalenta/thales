#include <iostream>
#include <tuple>

#include <thales/command_line_parser.hpp>

CommandLineParser::CommandLineParser(std::string description) : description_(description) {
  std::cout << "Created an empty command line parser\n";
}

void CommandLineParser::AddArgument(std::string short_name, std::string long_name, std::string description) {

  arguments_.push_back(std::make_tuple(short_name, long_name, description));

}

void CommandLineParser::PrintArguments(void) const {

  for (auto argument : arguments_) {
    std::cout << std::get<0>(argument) << " "
              << std::get<1>(argument) << " "
              << std::get<2>(argument) << "\n";
  }

}