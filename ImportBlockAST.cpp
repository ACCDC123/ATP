#include "ImportBlockAST.h"

#include <iostream>

ImportBlockAST::ImportBlockAST() : tset(std::make_shared<std::vector<std::string>>()) {}

void ImportBlockAST::push_tset(std::string import) {
  tset->push_back(import);
}

void ImportBlockAST::read_tset() {
  for (auto val : *tset) {
    std::cout << val << " ";
  }
}