#include "DriveVectorAST.h"

#include <iostream>

DriveVectorAST::DriveVectorAST(): operation_list(std::make_shared<std::vector<std::string>>()),
operation_line(std::make_shared<std::vector<int>>()),
vector_list(std::make_shared<std::vector<std::vector<std::string>>>())
{}

void DriveVectorAST::push_vector(const std::vector<std::string> vec) {
vector_list->push_back(vec);
}

void DriveVectorAST::push_operation(const string op) {
operation_list->push_back(op);
}

void DriveVectorAST::push_operation_line(int line) {
operation_line->push_back(line);
}

void DriveVectorAST::read_vector(){
for(auto v : *vector_list) {
for(auto s : v)
cout << s << " ";
cout << endl;
}
}
