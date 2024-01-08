#include "DriveVectorAST.h"

#include <iostream>

DriveVectorAST::DriveVectorAST(): vector_list(std::make_shared<std::vector<VectorAST>>())
{}

void DriveVectorAST::push_vector_node(const VectorAST atp_vector) {
vector_list->push_back(atp_vector);
}

void DriveVectorAST::read_vector_list()const {
for(auto val : *vector_list) {
val.read_vector();
std::cout<<std::endl;
}

}
void DriveVectorAST::read_operation_list()const{
for (auto val : *vector_list) {
    val.read_operation();
  }
  
}
void DriveVectorAST::read_vector_line_list()const{
for (auto val : *vector_list) {
    val.read_vector_line();
  }
  
}