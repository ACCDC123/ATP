#include "PinListAST.h"
#include "LoggerManager.h"

PinListAST::PinListAST()
    : pin_list(std::make_shared<std::vector<std::string>>())
{
}

void PinListAST::push_pin(const std::string pin)
{
    pin_list->push_back(pin);
}

void PinListAST::read_pin_list() const
{
    auto logger = LoggerManager::getLogger();
    string pin;
    for (auto val : *pin_list)
    {
        pin = pin + val + " ";
    }
    logger->debug("There are the pin list for the ATP file:"+pin);
}