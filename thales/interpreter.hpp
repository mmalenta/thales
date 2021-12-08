#ifndef THALES_INTERPRETER_HPP_
#define THALES_INTERPRETER_HPP_

#include <functional>
#include <string>
#include <utility>

class Interpreter {

  public:
  
    Interpreter(void);
    void Run(void);

  protected:

  private:

    void AddOperation(std::string, std::function<int(int, int)>);
    void ParseExpression(std::string expression);
    const std::string prompt_ = ":> ";
    std::vector<std::pair<std::string, std::function<int(int, int)>>> allowed_operations_;
};

#endif