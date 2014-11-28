/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_EDN_BISON_H_INCLUDED
# define YY_YY_EDN_BISON_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    EDIF = 258,
    EDIFVERSION = 259,
    EDIFLEVEL = 260,
    EKEYWORDMAP = 261,
    EKEYWORDLEVEL = 262,
    ESTATUS = 263,
    EWRITTEN = 264,
    ETIMESTAMP = 265,
    EAUTHOR = 266,
    EPROGRAM = 267,
    EVERSION = 268,
    eLIBRARY = 269,
    eTECHNOLOGY = 270,
    eLIBRARYREF = 271,
    eCELL = 272,
    eCELLTYPE = 273,
    eCELLREF = 274,
    eVIEW = 275,
    eVIEWTYPE = 276,
    eVIEWREF = 277,
    eINTERFACE = 278,
    ePORT = 279,
    eARRAY = 280,
    eDIRECTION = 281,
    eINPUT = 282,
    eOUTPUT = 283,
    eINOUT = 284,
    eCONTENTS = 285,
    eINSTANCE = 286,
    eRENAME = 287,
    ePROPERTY = 288,
    eSTRING = 289,
    eINTEGER = 290,
    eNET = 291,
    eJOINED = 292,
    ePORTREF = 293,
    eMEMBER = 294,
    eINSTANCEREF = 295,
    eDESIGN = 296,
    LP = 297,
    RP = 298,
    MD = 299,
    QUOTE = 300,
    eWORK = 301,
    eGENERIC = 302,
    ePRIM = 303,
    eNETLIST = 304,
    eINITIAL_VALUE = 305,
    eIDENTIFIER = 306,
    eWORD_QUOTED = 307,
    eNUMBER = 308
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 51 "edn_bison.y" /* yacc.c:1909  */

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

#line 128 "edn_bison.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_EDN_BISON_H_INCLUDED  */
