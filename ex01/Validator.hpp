#ifndef VALIDATOR_HPP
#define VALIDATOR_HPP

#include "Validator.hpp"

#include <iostream>
#include <limits>
#include <sstream> 
#include <cstdlib> 

std::string getValidAlphaWord(const std::string& prompt, const std::string& errorMsg);
long getValidNum(const std::string& prompt, const std::string &errorMsg);
std::string getValidNickname(const std::string& prompt, const std::string& errorMsg);
std::string getValidSecret(const std::string& prompt);
int getValidIndex(const std::string& prompt, const std::string& errorMsg);

#endif