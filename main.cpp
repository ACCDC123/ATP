
#include "LoggerManager.h"
#include "ProgramAST.h"
extern int yyparse();
std::shared_ptr<ProgramAST> ATPhead = make_shared<ProgramAST>();

extern void yyparse_init(const char *filename);
extern void yyparse_cleanup();
int main(int argc, char **argv)
{
  auto logger = LoggerManager::getLogger();
  const char *file_name;
  logger->info("Please enter the file name:");
  std::string user_input;
  std::cin >> user_input;
  file_name = user_input.c_str();
  yyparse_init(file_name);
  // 词法分析
  yyparse();

  ATPhead->vector_block.drive_vector_node.read_operation_list();
  // (*(ATPhead->vector_block.drive_vector_node.vector_list))[0].read_vector();
  // (*(ATPhead->vector_block.drive_vector_node.vector_list))[0].read_operation();
  //  (*(ATPhead->vector_block.drive_vector_node.vector_list))[0].read_operation_line();
  //  (*(ATPhead->vector_block.drive_vector_node.vector_list))[1].read_vector();

  yyparse_cleanup();

  return 0;
}