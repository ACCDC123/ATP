

#include "ProgramAST.h"
extern int yyparse();
std::shared_ptr<ProgramAST> ATPhead = make_shared<ProgramAST>();

extern void yyparse_init(const char *filename);
extern void yyparse_cleanup();
int main(int argc, char **argv)
{
  const char *file_name;
  std::cout << "Please enter the file name:";
  std::string userInput;
  std::cin >> userInput;
  file_name = userInput.c_str();
  yyparse_init(file_name);
  // 词法分析
  yyparse();
  // std::cout<<"adsjahdahs"<<std::endl;
  // ATPhead->vector_block.drive_vector_node.read_vector_list();
  // std::cout<<"sjahjhd"<<std::endl;
  // ATPhead->vector_block.drive_vector_node.read_operation_line_list();
  // std::cout<<"uhuih"<<std::endl;

  // ATPhead->vector_block.drive_vector_node.read_operation_list();
  // (*(ATPhead->vector_block.drive_vector_node.vector_list))[0].read_vector();
  // (*(ATPhead->vector_block.drive_vector_node.vector_list))[0].read_operation();
  //  (*(ATPhead->vector_block.drive_vector_node.vector_list))[0].read_operation_line();
  //  (*(ATPhead->vector_block.drive_vector_node.vector_list))[1].read_vector();

  yyparse_cleanup();

  return 0;
}