#ifndef __CALCULATOR_HPP
#define __CALCULATOR_HPP

#include <string>

// this function should expect that `expression` has already been
// validated and thus throw no exceptions
double parse_number(const std::string &expression);
bool isNum(std::string numb);
std::string str_adder(std::string operand_one, std::string operand_two);

#endif // __CALCULATOR_HPP
