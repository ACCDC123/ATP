#ifndef PINLISTAST_H
#define PINLISTAST_H

#include "ATPast.h"
#include <memory>
#include <vector>
#include <string>

class PinListAST {
public:
PinListAST();
void push_pin(std::string);
void read_pin_list();

std::shared_ptr<std::vector<std::string>> pin_list;
std::string timing;
};

#endif
