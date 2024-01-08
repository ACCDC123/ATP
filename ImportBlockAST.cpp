#include "ImportBlockAST.h"

#include <iostream>

ImportBlockAST::ImportBlockAST() : tset(std::make_shared<std::vector<std::string>>()) {}

void ImportBlockAST::push_tset(const std::string import) {
  tset->push_back(import);
}

void ImportBlockAST::read_tset() const{
  for (auto val : *tset) {
    std::cout << val << " ";
  }
}