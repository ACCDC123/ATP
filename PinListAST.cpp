#include "PinListAST.h"

PinListAST::PinListAST()
:  pin_list(std::make_shared<std::vector<std::string>>())
{}

void PinListAST::push_pin(const std::string pin) {
pin_list->push_back(pin);
}

void PinListAST::read_pin_list() const {
for(auto val : *pin_list) {
std::cout << val << " ";
}
}