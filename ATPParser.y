%{
	#include "ATPast.h"
	#include <stdio.h>
	#include "ATPParser.hpp"
	#include <cstring>

	extern int yylex();
	void yyerror(const char* s)
	{
		printf("Error: %s\n", s);
	}
	extern std::shared_ptr<ProgramAST> ATPhead;
	auto vectornode = make_shared<std::vector<std::string>>();
	int linenode =0;
	%}
%union
{
	
    class ATPAST* atpAST;
    class VectorBlockAST* vectorBlockAST;
    class PinListAST* pinListAST;
    class DriveVectorAST* driveVectorAST;
    class OperationAST* OperationAST;
    class ATPAST* ATPAST;
	std::string* string;
	int token;
	std::vector<std::string>* atpvector;
	
	
}

%token <string>  IMPORT TSET IDENTIFIER H L X VECTOR TIMNG LOOP HALT START STOP DASH DOUBLE INTEGER STRING MATCH REPEAT HYPHEN

%token <token>  L_SQUARE_BRACKET R_SQUARE_BRACKET L_PARENTHESIS R_PARENTHESIS L_BRACE R_BRACE MULTI_LINE_ANNOTATION 
%token <token>  LESS_THAN LESS_EQUAL_THAN GREAT_THAN GREAT_EQUAL_THAN  COLON QUOTATION SEMICOLON COMMA  ANNOTATION

%type <atpAST> ATP


%type <pinListAST> plist
%type <driveVectorAST> vectorblock
%type <atpvector>   drives vector pinnames




%type <string> pinname 



%defines  
%start ATP
%%

ATP: importblockAST vectorblockAST{
	
}
       ;

importblockAST: IMPORT TSET tsets SEMICOLON
                | ANNOTATION importblockAST
				| MULTI_LINE_ANNOTATION importblockAST
      ;

tsets:IDENTIFIER{
	std::string import;
	import=*$1;
	(*ATPhead).import_block_push_tset(import);
	
}
     | tsets COMMA IDENTIFIER{
		std::string import;
	    import=*$3;
	    (*ATPhead).import_block_push_tset(import);
	 }  
;

vectorblockAST: VECTOR  plist  L_BRACE vectorblock R_BRACE
                 |ANNOTATION vectorblockAST
				 |MULTI_LINE_ANNOTATION vectorblockAST
        ; 

plist:L_PARENTHESIS TIMNG COMMA pinnames R_PARENTHESIS{
	std::string Timing;
	Timing=*$2;
	ATPhead->vector_block.pin_list_node.timing=Timing;
}
         | L_PARENTHESIS pinnames R_PARENTHESIS   
		 {

		 }
;

pinnames:pinname
{
	std::string pinnode = *$1;
	(*ATPhead).vector_block_push_pin(pinnode);
}
         |pinnames COMMA pinname
		 {
				std::string pinnode = *$3;
				(*ATPhead).vector_block_push_pin(pinnode);
		 }
		;


pinname:STRING{
    $$=$1;
}
         |IDENTIFIER{
         $$=$1;
         }
         ;

vectorblock:vector  vectorblock{ 
}
             |vector {
			 }
			 |ANNOTATION vectorblock{}
			 |MULTI_LINE_ANNOTATION vectorblock{}
;



vector:GREAT_THAN  drives SEMICOLON{
	linenode++;
	ATPhead->vector_block_push_vector(*vectornode);
	vectornode->clear();
	vectornode.reset(new vector<string>()); 
}
|START COLON vector{
			ATPhead->vector_block_push_operation(*$1);
			ATPhead->vector_block_push_operation_line(linenode);
		  }
		  |STOP COLON vector{
			ATPhead->vector_block_push_operation(*$1);
			ATPhead->vector_block_push_operation_line(linenode);
		  }
		  |HALT COLON vector{
			ATPhead->vector_block_push_operation(*$1);
			ATPhead->vector_block_push_operation_line(linenode);
		  }
		  |MATCH INTEGER vector{
			ATPhead->vector_block_push_operation(*$1+*$2);
			ATPhead->vector_block_push_operation_line(linenode);
		  }
		  |REPEAT INTEGER vector{
			ATPhead->vector_block_push_operation(*$1+*$2);
			ATPhead->vector_block_push_operation_line(linenode);
		  }
		  |LOOP INTEGER vector{
			ATPhead->vector_block_push_operation(*$1+*$2);
			ATPhead->vector_block_push_operation_line(linenode);
		  }
		  |DASH INTEGER vector{
			ATPhead->vector_block_push_operation(*$1+*$2);
			ATPhead->vector_block_push_operation_line(linenode);
		  }
          |vector ANNOTATION{}
		  |vector MULTI_LINE_ANNOTATION{};
		 ;

drives:INTEGER{
	
    vectornode ->push_back(*$1);
}
	     |HYPHEN
		 {
			vectornode->push_back(*$1);
		 }
         |IDENTIFIER{
				
    vectornode ->push_back(*$1);
		 }
         |H{
					
    vectornode ->push_back(*$1);
         }
         |L{
					
    vectornode ->push_back(*$1);
         }
         |X{
					
    vectornode ->push_back(*$1);
         }
		 |drives INTEGER  
		 {
					
    vectornode ->push_back(*$2);
		 }
		 |drives HYPHEN  {
			  vectornode ->push_back(*$2);
		 }
		 |drives H  {
					
    vectornode ->push_back(*$2);
		 }
		 |drives L  {
					
    vectornode ->push_back(*$2);
		 }
		 |drives X  {
					
    vectornode ->push_back(*$2);
		 }
		  | drives IDENTIFIER  {
					
    vectornode ->push_back(*$2);
		 }
    
        ;
 %%