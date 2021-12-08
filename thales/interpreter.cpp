#include <algorithm>
#include <functional>
#include <iostream>
#include <regex>
#include <utility>

#include <thales/interpreter.hpp>

Interpreter::Interpreter(void) {

  auto ls_lambda = [](int op1, int op2) { return op1 << op2;};
  AddOperation("<<", ls_lambda);

  auto rs_lambda = [](int op1, int op2) { return op1 >> op2;};
  AddOperation(">>", rs_lambda);

  auto and_lambda = [](int op1, int op2) { return op1 & op2;};
  AddOperation("&", and_lambda);

}

void Interpreter::AddOperation(std::string op, std::function<int(int, int)> func) {

  allowed_operations_.push_back(std::make_pair(op, func));

}

void Interpreter::ParseExpression(std::string expression) {

  std::regex expression_regex("([[:digit:]]+)[[:space:]]*([[:punct:]]+)[[:space:]]*([[:digit:]]+)");
  std::smatch expression_match;
  std::regex_search(expression, expression_match, expression_regex);

  if (!expression_match.empty()) {

      std::string operation = expression_match[2];
      auto find_expression = std::find_if(allowed_operations_.begin(),
                                          allowed_operations_.end(),
                                          [&operation](std::pair<std::string, std::function<int(int, int)>> func){ return func.first == operation; });

      if (find_expression == allowed_operations_.end()) {
        std::cerr << "No suitable operation implemented for"
                  << operation << " yet!\n";
      } else {
        std::cout << (*find_expression).second(std::stoi(expression_match[1]), std::stoi(expression_match[3])) << std::endl;
      }

  }

}

void Interpreter::Run(void) {

    std::string input;

    std::cout << prompt_;

    while(std::getline(std::cin, input) ) {
        ParseExpression(input);
        std::cout << prompt_;

    }
}