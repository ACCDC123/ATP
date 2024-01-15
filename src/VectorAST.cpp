#include "VectorAST.h"
#include "LoggerManager.h"

VectorAST::VectorAST()
    : atp_vector(std::make_shared<std::vector<std::string>>()) {}

void VectorAST::push_vector(const std::vector<std::string> vec)
{
    atp_vector->assign(vec.begin(), vec.end());
}

void VectorAST::push_operation(const std::string op)
{
    atp_operation = op;
}

void VectorAST::push_vector_line(const int line)
{
    vector_line = line;
}

void VectorAST::read_vector() const
{
    auto logger = LoggerManager::getLogger();
    std::string vec;
    for (auto val : *atp_vector)
    {
        vec = vec + val + " ";
    }
    logger->debug(vec);
}

void VectorAST::read_operation() const
{
    auto logger = LoggerManager::getLogger();
    if (!atp_operation.empty())
    {
        logger->debug("There is the operation for the vector:"+atp_operation);
    }
}
void VectorAST::read_vector_line() const
{
    auto logger = LoggerManager::getLogger();
    logger->debug("This is the line for the vector"+vector_line);
}
