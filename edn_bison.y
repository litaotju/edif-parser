%{

 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 #include "type.h"
 #include "node_util.h"

#ifndef YYLINENO
int yylineno;
#define YYLINENO yylineno
#else
extern int yylineno;
#endif


 /*---------------------------------------------------------------------------------*/
 /*宏定义与函数声明*/
 /*---------------------------------------------------------------------------------*/
//#define TO_VIEW_LIB_REF

#ifdef TO_VIEW_LIB_REF
#define to_view_lib_ref 1
#else 
#define to_view_lib_ref 0
#endif

extern top_EDIF *p_top_edif;


 void yyerror(const char *str);
 int yywrap();
 extern int yylex();

 // RESPONCE in an error
 void yyerror(const char *str){fprintf(stderr,"error in parsing: %s - on line number %d\n",str, yylineno);}
// point of continued file reading
 int yywrap(){printf("come to the end of this file\n");return 1;}

//virables global
int prim_type_count;
//virables to record some tmp number
int cnt_tmp;  //just a variable to use for alloction of mem for a port list

%}


 /*---------------------------------------------------------------------------------*/
 /*语意值的数据结构*/
 /*---------------------------------------------------------------------------------*/
%union{
	char *id; 
	int  num_value;
	
	top_EDIF              *top_EDIF_NODE;
	//struct just for ref_lib
    REF_LIBRARY          *ref_library_node;
	PRIM_CELL            *prim_node; 
	PORT         		 *port_node;
	
	CELL				 *cell_node;
	VIEW				 *view_node;
    VIEW_CELL_LIB_REF    *view_cell_lib_ref_node;
	PROPERTY    		 *property_node;
	INSTANCE             *instance_node;
	
	PORTREF				 *portref_node;
	NET					 *net_node;
}



 /*---------------------------------------------------------------------------------*/
 /*终结符*/
 /*---------------------------------------------------------------------------------*/

 /*keywords donot need a semantic value, just help to build the structure of a edif */
 /*edif infomation */
%token EDIF EDIFVERSION EDIFLEVEL EKEYWORDMAP EKEYWORDLEVEL ESTATUS
%token EWRITTEN ETIMESTAMP EAUTHOR EPROGRAM EVERSION
 /* keywords of all lib */
%token eLIBRARY eTECHNOLOGY eLIBRARYREF
%token eCELL eCELLTYPE  eCELLREF
%token eVIEW  eVIEWTYPE  eVIEWREF
%token eINTERFACE ePORT eARRAY eDIRECTION 
%token eINPUT eOUTPUT eINOUT
 /*tokens belong to cells in work */
%token eCONTENTS 
%token eINSTANCE eRENAME ePROPERTY eSTRING eINTEGER
%token eNET eJOINED ePORTREF eMEMBER eINSTANCEREF 
 /*design information */
%token eDESIGN
 /*-----------------------------------------------------------------------------------*/
 /*标点符号token ，作为网表中的定界符
 /*in before name there are bus and bit by [ : ] */
%token LP RP MD
 /*other words just treated as words to inform the commercial infomation */
%token QUOTE 
%token '(' ')'

 /*------------------------------------------------------------------------------------*/
 /*后续处理中会用到其语义值的token，因此在flex扫描之中，应该赋予其yylval

 /*library name */
 //%token<num_value> eUNILIB eVIRTEX eVIRTEXR 
%token<num_value> eWORK
 /*cell的基本信息*/
%token<num_value> eGENERIC ePRIM eNETLIST   
 /*LUT的初始化值*/
%token<id> eINITIAL_VALUE
 /*其他标识符 identifier */
%token<id> eIDENTIFIER eWORD_QUOTED
 /* 出现在EDN网表中的数字 */
%token<num_value> eNUMBER 





 /*---------------------------------------------------------------------------------*/
 /*非终结符*/
 /*----------------------------------------------------------------------------------*/
%type<top_EDIF_NODE> top_edif

%type<ref_library_node> ref_library_list ref_library
%type<prim_node> prim_list   prim_cell
%type<port_node> interface   port_list port  

%type<cell_node> library_work cell_list cell
%type<view_node> view
%type<instance_node> instance_list instance
%type<view_cell_lib_ref_node> view_cell_lib_ref
%type<property_node> property_list property 

%type<net_node>	net_list net
%type<portref_node>	portref_list portref
%type<id> rename  lib_ref design
%error-verbose
%%

 /*---------------------------------------------------------------------------------*/
 /*网表语法描述开始*/
 /*----------------------------------------------------------------------------------*/
/* 1 top_edif */
top_edif    : '('  EDIF eIDENTIFIER edif_info ref_library_list library_work  design ')' 
					{p_top_edif=createEdif($3,$5,$6,$7);$$=p_top_edif=createEdif($3,$5,$6,$7);}
;

/*---------------------------------------------------------------------------------------*/
/*1.1 edif_info begin */
/*---------------------------------------------------------------------------------------*/
edif_info   : edif_version edif_level keywordmap edif_status  
;
edif_version: '(' EDIFVERSION eNUMBER eNUMBER eNUMBER ')'
;
edif_level  : '('  EDIFLEVEL eNUMBER ')'
;
keywordmap  : '(' EKEYWORDMAP '(' EKEYWORDLEVEL eNUMBER ')'')'
;
edif_status : '(' ESTATUS '(' EWRITTEN time_stamp author program ')' ')'
;
time_stamp  : '(' ETIMESTAMP eNUMBER eNUMBER eNUMBER eNUMBER eNUMBER eNUMBER ')'
;
author      : '(' EAUTHOR  QUOTE quoted_info_list QUOTE ')'
;
program     : '(' EPROGRAM QUOTE quoted_info_list QUOTE version  ')'
;
version     : '(' EVERSION QUOTE quoted_info_list QUOTE ')'
;
quoted_info_list : eWORD_QUOTED
				  |quoted_info_list eWORD_QUOTED
				  |quoted_info_list eNUMBER
				  |eNUMBER
;


/*---------------------------------------------------------------------------------------*/
/*1.2 ref_library begin */
/*---------------------------------------------------------------------------------------*/

ref_library_list :ref_library_list ref_library
						{cnt_tmp++;$$=newRef_Lib_List_Entry($1,$2,cnt_tmp);}
				 |ref_library
						{cnt_tmp=1;$$=newRef_Lib_List($1);}
;
					
ref_library : '(' eLIBRARY eIDENTIFIER  lib_info prim_list ')'
								{$$=createRef_Lib($3,$5);}					
;

prim_list :prim_cell 			 {cnt_tmp=1;$$=newPrim_List($1);}
		  |prim_list prim_cell   {cnt_tmp++;$$=newPrim_List_Entry($1,$2,cnt_tmp);}
;

prim_cell :'(' eCELL eIDENTIFIER '(' eCELLTYPE eGENERIC ')' '(' eVIEW ePRIM '('eVIEWTYPE eNETLIST ')'interface')'')'
								 {$$=createPrim($3,$6,$10,$13,$15);}
;


	//all the view have interface ,they are same in lib_work and lib_XILINX
	//interface below
interface    : '(' eINTERFACE port_list ')' {$$=$3;}
;

port_list    : port_list port     {cnt_tmp++;$$=newPort_List_Entry($1,$2,cnt_tmp);}
			 | port 			  {cnt_tmp=1;$$=newPort_List($1);}
;
port         :  '(' ePORT '(' eARRAY rename eNUMBER ')''(' eDIRECTION eINPUT  ')' ')'  {$$=createPort($6,$5,1);}
			 |  '(' ePORT '(' eARRAY rename eNUMBER ')''(' eDIRECTION eOUTPUT ')' ')'  {$$=createPort($6,$5,2);}
	  		 |  '(' ePORT '(' eARRAY rename eNUMBER ')''(' eDIRECTION eINOUT  ')' ')'  {$$=createPort($6,$5,3);}
	  		
	  		 |	'(' ePORT  rename     '(' eDIRECTION eINPUT  ')' ')'				   {$$=createPort(1,$3,1);}
	  		 |	'(' ePORT  rename     '(' eDIRECTION eOUTPUT ')' ')'				   {$$=createPort(1,$3,2);}
	  		 |  '(' ePORT  rename     '(' eDIRECTION eINOUT ')' ')'				       {$$=createPort(1,$3,3);}
	  		 
			 |	'(' ePORT eIDENTIFIER '(' eDIRECTION eINPUT   ')' ')'			       {$$=createPort(1,$3,1);}
			 |	'(' ePORT eIDENTIFIER '(' eDIRECTION eOUTPUT  ')' ')'			       {$$=createPort(1,$3,2);}
			 |  '(' ePORT eIDENTIFIER '(' eDIRECTION eINOUT   ')' ')'				   {$$=createPort(1,$3,3);}
			 			
;
	//interface above


/*---------------------------------------------------------------------------------------*/
// 1.3 library_work begin
/*---------------------------------------------------------------------------------------*/

library_work :'('eLIBRARY eWORK lib_info cell_list ')'
			              		    {$$=$5;}
;
lib_info	 : '(' EDIFLEVEL eNUMBER ')' '(' eTECHNOLOGY '('eIDENTIFIER ')' ')'
;
  //cell begins 
cell_list    :cell_list cell 		{cnt_tmp++;$$=newCell_List_Entry($1,$2,cnt_tmp);}
			 |cell  				{cnt_tmp=1;$$=newCell_List($1);}
;

cell         : '(' eCELL eIDENTIFIER '(' eCELLTYPE eGENERIC ')' view ')'
				            		{$$=createCell($3,$6,$8);}
;

view         : '(' eVIEW eIDENTIFIER '('eVIEWTYPE eNETLIST ')' interface '(' eCONTENTS instance_list net_list ')'  property_list ')'
									{$$=createView($3,$6,$8,$11,$12,$14);}
;

		//instance list below
instance_list: instance_list instance	{cnt_tmp++;$$=newInstance_List_Entry($1,$2,cnt_tmp);}
			 | instance     			{cnt_tmp=1;$$=newInstance_List($1);}

;
instance     : '(' eINSTANCE eIDENTIFIER view_cell_lib_ref       property_list  ')'		
					{
						$$=createInstance($3,$4,$5); 
					 	printf("instance : %s find\n",$3);
					}
			 | '(' eINSTANCE rename      view_cell_lib_ref       property_list  ')'		
					{
						$$=createInstance($3,$4,$5);
						printf("instance : %s find\n",$3);
					}
			 | '(' eINSTANCE eIDENTIFIER view_cell_lib_ref ')'				
					{
						$$=createInstance($3,$4,NULL);
						printf("instance : %s find\n",$3);
					}
			 | '(' eINSTANCE rename      view_cell_lib_ref')'	 			
					{	
						$$=createInstance($3,$4,NULL);
						printf("instance : %s find\n",$3);
					}

;
	/*
	instance_property_list :instance_property_list instance_property
						   |instance_property
						   
	;
	instance_property : '(' ePROPERTY eINIT       '(' eSTRING QUOTE eINITIAL_VALUE QUOTE ')' ')'  
									//the lut property initiated a value
							{$$=createInstance_Property("INIT",$7);printf("a instance initiated by a value: %s find\n",$7);}
					  |'(' ePROPERTY eIDENTIFIER  '(' eSTRING QUOTE eINITIAL_VALUE QUOTE ')' ')'  
					  		{$$=createInstance_Property($3,$7);}
					  |'(' ePROPERTY eIDENTIFIER  '(' eSTRING QUOTE eWORD_QUOTED QUOTE ')' ')'
					  		{$$=createInstance_Property($3,$7);}  
					  |'(' ePROPERTY eIDENTIFIER  '(' eIDENTIFIER eNUMBER ')' ')'  
					  		{$$=createInstance_Property($3,$5);}
	;
	*/
rename       : '(' eRENAME eIDENTIFIER QUOTE eWORD_QUOTED LP eNUMBER MD eNUMBER RP     QUOTE ')'				{ $$=$3;}
			 | '(' eRENAME eIDENTIFIER QUOTE eWORD_QUOTED LP eNUMBER RP                QUOTE ')'				{ $$=$3;}
			 | '(' eRENAME eIDENTIFIER QUOTE eWORD_QUOTED      QUOTE ')'					                    { $$=$3;}
	
;

view_cell_lib_ref: '(' eVIEWREF eIDENTIFIER  '(' eCELLREF eIDENTIFIER ')' ')'
							{$$=decideInstance_Ref($3,$6,"work");}
				 | '(' eVIEWREF ePRIM        '(' eCELLREF eIDENTIFIER  lib_ref ')' ')'
						    {$$=decideInstance_Ref("PRIM",$6,$7);}
;

lib_ref			 : '(' eLIBRARYREF eIDENTIFIER  ')'	{$$=$3;    if(to_view_lib_ref) printf("%s       lib called\n",$3);}
				/* | '(' eLIBRARYREF eWORK     ')'	{$$="work";if(to_view_lib_ref) printf("WORK     lib called\n");}*/
;
		//intance list above


		//net_list below

net_list     :net_list net			{cnt_tmp++;$$=newNet_List_Entry($1,$2,cnt_tmp);}
			 |net					{cnt_tmp=1;$$=newNet_List($1);}
;
net          :'(' eNET eIDENTIFIER  '(' eJOINED portref_list ')' property_list')'  {$$=findNet($3,$6);printf("net : %s find\n",$3);}
			 |'(' eNET rename       '(' eJOINED portref_list ')' property_list ')' {$$=findNet($3,$6);printf("net : %s find\n",$3);}
			 |'(' eNET eIDENTIFIER  '(' eJOINED portref_list ')' ')' 			   {$$=findNet($3,$6);printf("net : %s find\n",$3);}
			 |'(' eNET rename       '(' eJOINED portref_list ')' ')' 			   {$$=findNet($3,$6);printf("net : %s find\n",$3);}
;

portref_list   :portref_list portref   {cnt_tmp++;$$=newPortref_List_Entry($1,$2,cnt_tmp);}
			   |portref				   {cnt_tmp=1;$$=newPortref_List($1);}
;

portref        :'(' ePORTREF eIDENTIFIER '(' eINSTANCEREF eIDENTIFIER ')' ')'
						{$$=createPortref(1,$3,0,$6);/*Joined to INSTANCE'S PORT*/}
			   |'(' ePORTREF '(' eMEMBER eIDENTIFIER eNUMBER ')' ')'
						{$$=createPortref(0,$5,$6,NULL);/*Joined to THIS CELL'S PORT bus*/}
			   |'(' ePORTREF '(' eMEMBER eIDENTIFIER eNUMBER ')' '(' eINSTANCEREF eIDENTIFIER ')' ')'
			   			{$$=createPortref(0,$5,$6,$10);/*Joined to THIS CELL'S PORT bus*/}
			   |'(' ePORTREF  eIDENTIFIER ')'
						{$$=createPortref(0,$3,0,NULL);/*Joined to THIS CELL'S PORT*/}
;
		//net_lsit above 
	//contents above
	
	//properties below
property_list  :property_list property		{cnt_tmp++;$$=newProperty_List_Entry($1,$2,cnt_tmp);}
			   |property					{cnt_tmp=1;$$=newProperty_List($1);}
;	
property       :'(' ePROPERTY eIDENTIFIER '(' eINTEGER eNUMBER ')' ')'						  {$$=createProperty_Integer($3,"integer",$6);}
			   |'(' ePROPERTY eIDENTIFIER '(' eSTRING  QUOTE eINITIAL_VALUE     QUOTE ')' ')' {$$=createProperty($3,"string" ,$7);}			   
			   |'(' ePROPERTY eIDENTIFIER '(' eSTRING  QUOTE eWORD_QUOTED       QUOTE ')' ')' {$$=createProperty($3,"string" ,$7);}			   
			   |'(' ePROPERTY eIDENTIFIER '(' eSTRING  QUOTE                    QUOTE ')' ')' {$$=createProperty($3,"string" ,NULL);}

;
	//properties above
/*---------------------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------------------*/
//1.4 design begins
design: '(' eDESIGN eIDENTIFIER '('eCELLREF eIDENTIFIER '(' eLIBRARYREF  eWORK ')'')' design_property')'
											{$$=$3;printf("Congtulations !!!!!!find a design in this edn file successfully\n");}
;
design_property:'(' ePROPERTY eIDENTIFIER '(' eSTRING  QUOTE eWORD_QUOTED       QUOTE ')' '('eIDENTIFIER QUOTE eWORD_QUOTED QUOTE ')' ')' 
			   								{/*这一行的property是为design所设计的,所以暂时在这里没有考虑其语意值*/}
;
%%


