#include <iostream>

#include <thales/command_line_parser.hpp>
#include <thales/interpreter.hpp>

using std::cout;
using std::endl;

int main(int argc, char *argv[]) {

  std::cout << "Welcome to Thales!\n";

  CommandLineParser parser = CommandLineParser("Thales - code for simple maths in multiple bases");
  parser.AddArgument("-h", "--help", "Print help");

  parser.PrintArguments();

  Interpreter interpreter = Interpreter();
  interpreter.Run();

  return 0;
}

