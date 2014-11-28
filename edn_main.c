#include <stdio.h>
#include <string.h>
#include "type.h"
#include "edn_bison.h"  //the header include yyparse() created by bison

#define DEBUG_LEX_ALONE 0
//in edn_flex.c

extern int yylex();
extern FILE *yyin;

top_EDIF *p_top_edif;

#if DEBUG_LEX_ALONE
	extern int instance_num;
	extern int net_num;	
	int 	   token_num=0;
#endif

int main(int argc ,char **argv){
	printf("runing the main func\n");
	
	//open files 
	if(argc >1){

		if(!(yyin=fopen(argv[1],"r"))){
			printf("opening the file with errors\n");
			perror(argv[1]);
			return (1);
		}
		else printf("opening the file\n");
	}

	//open the default test
	else{ 
        argv[1]="/home/litao/edn_parse/test_dir/and_2bits.edn";
		if(!(yyin=fopen(argv[1],"r"))){
			printf("opening the default file with errors !!\n");
			perror(argv[1]);
			return (1);
		}
		else printf("opening the default file: %s\n",argv[1]);
	}

	#if DEBUG_LEX_ALONE

		do{
			token_num++;
		}
		while(yylex()!=0);

			printf("the instance number is %d\n",instance_num);
			printf("the net      number is %d\n",net_num);
			printf("the token    number is %d\n",token_num);
	#else
	// 本注释以上可以正确运行,也就是说yylex().产生的lexer是可以正常运行的
    //bison 产生的parser存在错误.在运行当中报的错误如下:
	//error in parsing: syntax error - on line number 1
		yyparse();
		printf("yyparse() has been excuted.\n");
		printf("find top edif:%s",p_top_edif->edif_name);
	#endif

	return 1;
}
