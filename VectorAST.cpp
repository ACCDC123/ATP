#include "VectorAST.h"

VectorAST::VectorAST()
:atp_vector(std::make_shared<std::vector<std::string>>()){}

void VectorAST::push_vector(std::vector<std::string> vec)
{
    atp_vector->assign(vec.begin(), vec.end());
}

void VectorAST::push_operation(std::string op)
{
    atp_operation=op;
}

void VectorAST::push_vector_line(int line)
{
    vector_line=line;
}

void VectorAST::read_vector()
{
    for(auto val : *atp_vector) {
std::cout << val << " ";
}
}

void VectorAST::read_operation()
{
   if(!atp_operation.empty())
    std::cout<<atp_operation<<std::endl;
}
void VectorAST::read_vector_line()
{
    std::cout<<vector_line<<std::endl;
}

