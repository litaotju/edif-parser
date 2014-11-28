%option noyywrap
%option yylineno
%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "type.h"
#include "edn_bison.h"

 #define  to_view_parse  0
 #define  RECORD         1
/* the define below helps with watching the parser go token by token */
 #define  MP  {if(to_view_parse) printf("%d %s\n", yylineno, yytext);}

#if RECORD
 int instance_num=0;
 int net_num     =0;
 #define RECORD_INSTANCE_NUM instance_num++
 #define RECORD_NET_NUM      net_num++
#endif 

%}

%s READING_STRING

%%

 /* edif information */
<INITIAL>"edif"			{MP;return EDIF;}
<INITIAL>"edifVersion"	{MP;return EDIFVERSION;}
<INITIAL>"edifLevel"	{MP;return EDIFLEVEL;}
<INITIAL>"keywordMap"	{MP;return EKEYWORDMAP;}
<INITIAL>"keywordLevel"	{MP;return EKEYWORDLEVEL;}
<INITIAL>"status"		{MP;return ESTATUS;}
<INITIAL>"written"		{MP;return EWRITTEN;}
<INITIAL>"timeStamp"    {MP;return ETIMESTAMP;}
<INITIAL>"author"		{MP;return EAUTHOR;}
<INITIAL>"program"		{MP;return EPROGRAM;}
<INITIAL>"version"		{MP;return EVERSION;}

 /* library name  */
<INITIAL>"library"		{MP;return eLIBRARY;}
<INITIAL>"technology"	{MP;return eTECHNOLOGY;}
	
	/*
	<INITIAL>"UNILIB"		{MP;return eUNILIB;}
	<INITIAL>"VIRTEX"		{MP;return eVIRTEX;}
	<INITIAL>"VIRTEXR"		{MP;return eVIRTEXR;}
	*/
<INITIAL>"work"			{MP;return eWORK;}


 /* keywords of all lib */

<INITIAL>"cell"			{MP;return eCELL;}
<INITIAL>"cellType"		{MP;return eCELLTYPE;}
<INITIAL>"GENERIC"		{MP;yylval.num_value=1;return eGENERIC;}


<INITIAL>"view"			{MP;return eVIEW;}
<INITIAL>"PRIM"			{MP;yylval.num_value=1;return ePRIM;}
<INITIAL>"viewType"		{MP;return eVIEWTYPE;}	
<INITIAL>"NETLIST"		{MP;yylval.num_value=1;return eNETLIST;}



<INITIAL>"interface"		{MP;return eINTERFACE;}
<INITIAL>"port"			    {MP;return ePORT;}
<INITIAL>"array"		    {MP;return eARRAY;}
<INITIAL>"direction"		{MP;return eDIRECTION;}
<INITIAL>"INPUT"			{MP;return eINPUT;}
<INITIAL>"OUTPUT"		    {MP;return eOUTPUT;}
<INITIAL>"INOUT"			{MP;return eINOUT;}

 	/* tokens belong to cells in work */
<INITIAL>"contents"		{MP;return eCONTENTS;}
<INITIAL>"instance"     {MP;RECORD_INSTANCE_NUM;return eINSTANCE;}
<INITIAL>"rename"		{MP;return eRENAME;}
<INITIAL>"viewRef"		{MP;return eVIEWREF;}
<INITIAL>"cellRef"		{MP;return eCELLREF;}
<INITIAL>"libraryRef"	{MP;return eLIBRARYREF;}

	/*the instance of a LUT has a property */
<INITIAL>"property"		{MP;return ePROPERTY;}
	/*
		<INITIAL>"INIT"			{MP;return eINIT;}
	*/
	
<INITIAL>"string"		{MP;return eSTRING;}
<INITIAL>"integer"		{MP;return eINTEGER;}


<INITIAL>"net"			{MP;RECORD_NET_NUM;return eNET;};
<INITIAL>"joined"		{MP;return eJOINED;}
<INITIAL>"portRef"		{MP;return ePORTREF;}
<INITIAL>"member"       {MP;return eMEMBER;}
<INITIAL>"instanceRef"	{MP;return eINSTANCEREF;}



 /*design information */ 
<INITIAL>"design "		{MP;return eDESIGN;}


<INITIAL>\" 		    {MP;BEGIN READING_STRING;return QUOTE;}
 /*back to initial state  a " has been detected */
<READING_STRING>\"      {MP;BEGIN INITIAL;return QUOTE;}

 /*return the text itself if it is '[' ':' ']' when in a " "*/ 
<READING_STRING>\[                                   {MP;return LP;}
<READING_STRING>\]									 {MP;return RP;}
<READING_STRING>\:								     {MP;return MD;}

<READING_STRING>[0-9]+'[bdho][0-9A-F]+                     {yylval.id=strdup(yytext);MP;return eINITIAL_VALUE;}
 /*other words just treated as words to inform the commercial infomation and part-infomation */
<READING_STRING>[0-9]+									   {yylval.num_value=atoi(yytext);MP;return eNUMBER;}
<READING_STRING>[a-zA-Z0-9_]+[.-]*[a-zA-Z0-9_]*             {yylval.id=strdup(yytext);MP;return eWORD_QUOTED;}
 /* ignore the ,.- in a pair of quote */
<READING_STRING>[,]	                                       {MP;continue;}
<READING_STRING>[\f\r\t\b ]+           					   {continue;/* ignore spaces*/}
 /* others in a pair of quotes should been warned */ 
<READING_STRING>.		           						   {printf("User Waring:ignore   %s in a parir quote \n",yytext);continue;}



 /*the ( and ) leave to yyparse() to handle */
<INITIAL>[()]                   				{MP;return yytext[0];}

 /* identifier */
<INITIAL>[a-zA-Z][a-zA-Z0-9_]*					{yylval.id=strdup(yytext);return eIDENTIFIER;}

 /*number */
<INITIAL>[0-9]+									{yylval.num_value=atoi(yytext);MP;return eNUMBER;}

 /*white space and new line */
<INITIAL>[\f\r\t\b ]+           	{ /* ignore spaces   */ continue;}
<INITIAL>[\n] 					    { /* ignore new line */ continue;}			
<INITIAL>.						    {printf("User Warning:line no:%d text %s unrecogiized  in edif source \n",yylineno,yytext);continue;}		


