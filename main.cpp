

#include "ATPast.h"
extern int yyparse();
std::shared_ptr<ProgramAST> ATPhead = make_shared<ProgramAST>();
extern std::shared_ptr<std::vector<std::string>> vectornode;
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
  for (auto val : *vectornode)
  {
    std::cout << val << " "; //
  }
  
  ATPhead->vector_block_read_operation();
  cout << std::endl;
  ATPhead->vector_block_read_operation_line();

  yyparse_cleanup();

  return 0;
}