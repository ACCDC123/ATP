#include "DriveVectorAST.h"
#include "LoggerManager.h"
#include "VectorAST.h"

DriveVectorAST::DriveVectorAST() : vector_list(std::make_shared<std::vector<VectorAST>>())
{
}

void DriveVectorAST::push_vector_node(const VectorAST atp_vector)
{
    vector_list->push_back(atp_vector);
}

void DriveVectorAST::read_vector_list() const
{
    auto logger = LoggerManager::getLogger();
    logger->debug("There are the test vector for the ATP file:");
    for (auto vec : *vector_list)
    {
        vec.read_vector();
    }
}

void DriveVectorAST::read_operation_list() const
{
    auto logger = LoggerManager::getLogger();
    logger->debug("There are the vector's operation for the ATP file:");
    for (auto val : *vector_list)
    {
        val.read_operation();
    }
}

void DriveVectorAST::read_vector_line() const
{
    auto logger = LoggerManager::getLogger();
    int length=(*vector_list).size();
    logger->debug("This is the number of the vector:{}",std::to_string(length));
    
}
