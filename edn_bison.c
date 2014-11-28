/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "edn_bison.y" /* yacc.c:339  */


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


#line 112 "edn_bison.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "edn_bison.h".  */
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
#line 51 "edn_bison.y" /* yacc.c:355  */

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

#line 226 "edn_bison.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_EDN_BISON_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 241 "edn_bison.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   337

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  335

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      46,    47,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    48,    49,    50,    51,    52,    53,    54,    55
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   145,   145,   152,   154,   156,   158,   160,   162,   164,
     166,   168,   170,   171,   172,   173,   181,   183,   187,   191,
     192,   195,   202,   205,   206,   208,   209,   210,   212,   213,
     214,   216,   217,   218,   228,   231,   234,   235,   238,   242,
     247,   248,   251,   256,   261,   266,   289,   290,   291,   295,
     297,   301,   309,   310,   312,   313,   314,   315,   318,   319,
     322,   324,   326,   328,   335,   336,   338,   339,   340,   341,
     350,   353
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "EDIF", "EDIFVERSION", "EDIFLEVEL",
  "EKEYWORDMAP", "EKEYWORDLEVEL", "ESTATUS", "EWRITTEN", "ETIMESTAMP",
  "EAUTHOR", "EPROGRAM", "EVERSION", "eLIBRARY", "eTECHNOLOGY",
  "eLIBRARYREF", "eCELL", "eCELLTYPE", "eCELLREF", "eVIEW", "eVIEWTYPE",
  "eVIEWREF", "eINTERFACE", "ePORT", "eARRAY", "eDIRECTION", "eINPUT",
  "eOUTPUT", "eINOUT", "eCONTENTS", "eINSTANCE", "eRENAME", "ePROPERTY",
  "eSTRING", "eINTEGER", "eNET", "eJOINED", "ePORTREF", "eMEMBER",
  "eINSTANCEREF", "eDESIGN", "LP", "RP", "MD", "QUOTE", "'('", "')'",
  "eWORK", "eGENERIC", "ePRIM", "eNETLIST", "eINITIAL_VALUE",
  "eIDENTIFIER", "eWORD_QUOTED", "eNUMBER", "$accept", "top_edif",
  "edif_info", "edif_version", "edif_level", "keywordmap", "edif_status",
  "time_stamp", "author", "program", "version", "quoted_info_list",
  "ref_library_list", "ref_library", "prim_list", "prim_cell", "interface",
  "port_list", "port", "library_work", "lib_info", "cell_list", "cell",
  "view", "instance_list", "instance", "rename", "view_cell_lib_ref",
  "lib_ref", "net_list", "net", "portref_list", "portref", "property_list",
  "property", "design", "design_property", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,    40,    41,   301,   302,
     303,   304,   305,   306,   307,   308
};
# endif

#define YYPACT_NINF -211

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-211)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -24,     7,    31,   -17,  -211,    10,    61,    57,    58,    45,
      60,    59,  -211,   101,    62,    56,    63,    93,  -211,    64,
      65,   103,    66,    67,    68,   -42,    72,    70,    71,    69,
     111,  -211,    74,   118,    78,    68,    73,  -211,  -211,   120,
      79,  -211,    75,   112,    -3,  -211,    82,    85,    77,   124,
      87,    83,  -211,  -211,   121,    12,  -211,   116,    90,    94,
      95,    96,    86,  -211,  -211,    91,    98,   133,   100,   132,
     130,   104,   105,  -211,    97,   138,   107,   108,   106,   139,
     140,   109,   113,   147,   114,   110,   115,   117,   119,   122,
       6,   123,   125,   126,   128,   129,   131,   127,  -211,  -211,
     -38,     6,  -211,   134,   145,   137,   141,   135,   142,  -211,
    -211,   -36,  -211,   136,   149,   144,   146,   143,  -211,   148,
     150,   151,  -211,   152,   153,   154,   157,   155,   158,   159,
     156,  -211,  -211,   161,  -211,   160,   163,   162,     6,   165,
     164,   169,   -31,   167,   170,   171,   172,   174,   173,   167,
     168,  -211,   175,   176,   178,   180,   183,    16,  -211,  -211,
     184,   179,   -41,  -211,  -211,   181,   182,     0,   185,   186,
     187,   188,  -211,   177,   189,   190,   203,   207,   -20,     3,
    -211,    21,  -211,   191,   205,   192,   193,    19,    22,   194,
     194,   -18,   206,   195,  -211,   196,   197,   198,   199,   201,
     202,   204,   208,   209,   217,    23,    30,   211,   212,   166,
      32,  -211,   200,   213,    -4,   214,   215,   216,   218,   219,
     220,    -8,  -211,    34,  -211,    36,   223,   227,   221,  -211,
    -211,   222,   228,   224,   225,  -211,  -211,  -211,  -211,  -211,
    -211,   229,   230,  -211,  -211,   231,   231,   232,   226,    25,
      28,  -211,   234,   249,   233,    38,  -211,    40,    54,  -211,
     235,   236,   237,   240,   238,   239,   241,   -16,    44,  -211,
      46,   242,   243,   244,   248,   250,   252,   245,   254,   255,
     247,    48,  -211,    50,  -211,    52,   -25,   256,  -211,  -211,
    -211,  -211,   251,   264,   257,   258,   253,   261,  -211,  -211,
    -211,   260,   263,   265,   262,   266,   259,   267,  -211,   268,
     269,   270,   271,   272,  -211,  -211,   273,  -211,   274,   277,
    -211,   278,   279,  -211,    55,   280,  -211,  -211,   275,  -211,
    -211,   276,   281,   283,  -211
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,    17,     0,     0,     0,     0,     0,    16,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     3,     0,     0,     0,     0,     0,     2,     5,     0,
       0,     4,     0,     0,     0,    19,     0,     0,     0,     0,
       0,     0,    18,    20,     0,     0,    37,     0,     0,     0,
       0,     0,     0,    34,    36,     0,     0,     0,     0,     0,
       0,     0,     0,     6,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    12,    15,
       0,     0,     7,     0,     0,     0,     0,     0,     0,    13,
      14,     0,    35,     0,     0,     0,     0,     0,     9,     0,
       0,     0,    38,     0,     0,     0,     0,     0,     0,     0,
       0,    70,     8,     0,    10,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    11,     0,     0,     0,     0,     0,     0,    24,    21,
       0,     0,     0,    22,    23,     0,     0,     0,     0,     0,
       0,     0,    41,     0,     0,     0,     0,     0,     0,     0,
      40,     0,    53,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    52,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    65,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    44,     0,    45,     0,     0,     0,     0,    39,
      64,     0,     0,     0,     0,    31,    32,    33,    28,    29,
      30,     0,     0,    42,    43,     0,     0,     0,     0,     0,
       0,    48,     0,     0,     0,     0,    59,     0,     0,    71,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    58,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    56,     0,    57,     0,     0,     0,    25,    26,
      27,    47,     0,     0,     0,     0,     0,     0,    63,    54,
      55,     0,     0,     0,     0,     0,     0,     0,    49,     0,
       0,     0,     0,     0,    66,    46,     0,    50,     0,     0,
      69,     0,     0,    51,     0,     0,    67,    68,     0,    61,
      60,     0,     0,     0,    62
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,   -98,  -211,   300,  -211,   246,    11,  -211,    14,  -211,
     296,  -211,   282,  -211,  -211,     4,  -170,   -10,  -211,  -211,
      29,   -59,  -200,  -204,  -210,  -211,  -211
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     7,     8,    14,    22,    31,    68,    76,    84,
     127,   100,    11,    12,    44,    45,   148,   157,   158,    19,
      34,    55,    56,   115,   171,   172,   169,   205,   294,   181,
     182,   255,   256,   210,   211,    27,   124
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     230,   223,   225,   111,   185,   167,    35,   108,   190,   119,
       3,    24,   168,   230,   146,   230,   109,   110,   109,   110,
     301,   208,     1,   109,   110,   174,   184,   302,   184,   303,
     280,     4,   175,   189,   178,   207,     5,   281,   233,   191,
     142,   234,   241,    43,    52,   242,   198,   199,   200,   201,
     202,   203,   260,   261,   262,   269,     6,   269,    54,    63,
      98,    99,   156,   163,   283,     9,   285,   192,   193,   209,
     222,   263,   264,   230,    16,   230,   209,   224,   209,   229,
     209,   243,   209,   244,   254,   268,   254,   270,   271,   272,
     209,   282,   209,   284,   297,   298,   209,   299,   209,   300,
      15,   328,   329,    10,    13,    17,    20,    25,    21,    29,
      26,    23,    30,    36,    33,    39,    24,    37,    38,    40,
      28,    41,    32,    42,    43,    49,    47,    48,    54,    51,
      50,    57,    58,    59,    60,    65,    61,    66,    62,    71,
      67,    69,    70,    74,    72,    73,    75,    77,    78,    82,
      79,    80,    81,    83,    85,    86,    88,    87,    90,    91,
     154,    92,    94,    93,    89,   113,    95,    96,   101,   121,
     133,   164,   102,   103,   104,   180,   105,    97,   106,   135,
     206,   112,   107,   114,   140,   130,   120,   257,   116,   118,
     117,   122,   123,     0,   126,     0,   128,   152,   125,   228,
     131,   132,   134,   145,   129,   136,   138,   162,   141,   137,
     194,   139,   143,   147,   165,   144,   150,   149,   178,   151,
     153,   156,   155,   159,   160,   161,   166,   170,   173,   187,
     183,   176,   177,   188,   179,   184,   195,   175,   197,   221,
     204,   209,   191,   186,   213,   231,   215,   196,   216,   217,
     212,   218,   214,   265,   249,   219,   220,   226,   227,   232,
     245,   235,   236,   237,   246,   238,   239,   240,   266,   248,
       0,   267,   251,   259,   247,   252,   253,   254,   258,   250,
     306,     0,   273,   274,   275,   276,   296,   286,   292,     0,
      53,   288,   278,   277,   279,   289,   305,   290,   287,   291,
     293,   310,   295,   304,   307,   308,   309,   311,   312,   314,
     313,    18,   316,   315,   317,   331,     0,   320,   321,   322,
     323,   324,   319,   318,   325,   326,   327,   330,   333,   332,
     334,    46,     0,     0,     0,     0,     0,    64
};

static const yytype_int16 yycheck[] =
{
     210,   205,   206,   101,   174,    46,    48,    45,   178,    45,
       3,    53,    53,   223,    45,   225,    54,    55,    54,    55,
      45,   191,    46,    54,    55,    25,    46,    52,    46,    54,
      46,     0,    32,    53,    31,    53,    53,    53,    42,    36,
     138,    45,    50,    46,    47,    53,    27,    28,    29,    27,
      28,    29,    27,    28,    29,   255,    46,   257,    46,    47,
      54,    55,    46,    47,   268,     4,   270,    46,    47,    46,
      47,    43,    44,   283,    14,   285,    46,    47,    46,    47,
      46,    47,    46,    47,    46,    47,    46,    47,    34,    35,
      46,    47,    46,    47,    46,    47,    46,    47,    46,    47,
      55,    46,    47,    46,    46,    46,     5,    14,    46,     6,
      46,    55,    46,    41,    46,    46,    53,    47,    47,     8,
      55,    47,    55,     5,    46,    46,    53,     7,    46,    17,
      55,    46,    55,     9,    47,    19,    53,    47,    17,    53,
      46,    46,    46,    10,    53,    47,    46,    15,    18,    11,
      46,    46,    55,    46,    46,    49,    16,    18,    45,    12,
     149,    47,    47,    53,    55,    20,    49,    48,    45,    20,
      13,   157,    47,    47,    46,   171,    47,    55,    47,    21,
     190,    47,    55,    46,    21,    33,    50,   246,    47,    47,
      55,    47,    46,    -1,    46,    -1,    46,    23,    55,    33,
      47,    47,    47,    34,    53,    46,    45,    24,    46,    53,
     181,    51,    47,    46,    30,    51,    45,    47,    31,    47,
      47,    46,    54,    47,    46,    45,    47,    46,    46,    26,
      53,    46,    46,    26,    46,    46,    45,    32,    45,    22,
      46,    46,    36,    53,    47,    45,    47,    55,    47,    47,
      54,    47,    54,    19,    26,    47,    47,    46,    46,    46,
      37,    47,    47,    47,    37,    47,    47,    47,    19,    47,
      -1,    38,    47,    47,    53,    46,    46,    46,    46,    55,
      16,    -1,    47,    47,    47,    45,    39,    45,    43,    -1,
      44,    47,    53,    55,    53,    47,    45,    47,    55,    47,
      46,    40,    47,    47,    47,    47,    53,    47,    45,    47,
      45,    11,    53,    47,    47,    40,    -1,    47,    47,    47,
      47,    47,    53,    55,    47,    47,    47,    47,    47,    53,
      47,    35,    -1,    -1,    -1,    -1,    -1,    55
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    46,    57,     3,     0,    53,    46,    58,    59,     4,
      46,    68,    69,    46,    60,    55,    14,    46,    69,    75,
       5,    46,    61,    55,    53,    14,    46,    91,    55,     6,
      46,    62,    55,    46,    76,    48,    41,    47,    47,    46,
       8,    47,     5,    46,    70,    71,    76,    53,     7,    46,
      55,    17,    47,    71,    46,    77,    78,    46,    55,     9,
      47,    53,    17,    47,    78,    19,    47,    46,    63,    46,
      46,    53,    53,    47,    10,    46,    64,    15,    18,    46,
      46,    55,    11,    46,    65,    46,    49,    18,    16,    55,
      45,    12,    47,    53,    47,    49,    48,    55,    54,    55,
      67,    45,    47,    47,    46,    47,    47,    55,    45,    54,
      55,    67,    47,    20,    46,    79,    47,    55,    47,    45,
      50,    20,    47,    46,    92,    55,    46,    66,    46,    53,
      33,    47,    47,    13,    47,    21,    46,    53,    45,    51,
      21,    46,    67,    47,    51,    34,    45,    46,    72,    47,
      45,    47,    23,    47,    72,    54,    46,    73,    74,    47,
      46,    45,    24,    47,    74,    30,    47,    46,    53,    82,
      46,    80,    81,    46,    25,    32,    46,    46,    31,    46,
      81,    85,    86,    53,    46,    82,    53,    26,    26,    53,
      82,    36,    46,    47,    86,    45,    55,    45,    27,    28,
      29,    27,    28,    29,    46,    83,    83,    53,    82,    46,
      89,    90,    54,    47,    54,    47,    47,    47,    47,    47,
      47,    22,    47,    89,    47,    89,    46,    46,    33,    47,
      90,    45,    46,    42,    45,    47,    47,    47,    47,    47,
      47,    50,    53,    47,    47,    37,    37,    53,    47,    26,
      55,    47,    46,    46,    46,    87,    88,    87,    46,    47,
      27,    28,    29,    43,    44,    19,    19,    38,    47,    88,
      47,    34,    35,    47,    47,    47,    45,    55,    53,    53,
      46,    53,    47,    89,    47,    89,    45,    55,    47,    47,
      47,    47,    43,    46,    84,    47,    39,    46,    47,    47,
      47,    45,    52,    54,    47,    45,    16,    47,    47,    53,
      40,    47,    45,    45,    47,    47,    53,    47,    55,    53,
      47,    47,    47,    47,    47,    47,    47,    47,    46,    47,
      47,    40,    53,    47,    47
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    67,    67,    67,    68,    68,    69,    70,
      70,    71,    72,    73,    73,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    75,    76,    77,    77,    78,    79,
      80,    80,    81,    81,    81,    81,    82,    82,    82,    83,
      83,    84,    85,    85,    86,    86,    86,    86,    87,    87,
      88,    88,    88,    88,    89,    89,    90,    90,    90,    90,
      91,    92
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     4,     6,     4,     7,     9,     9,     6,
       7,     6,     1,     2,     2,     1,     2,     1,     6,     1,
       2,    17,     4,     2,     1,    12,    12,    12,     8,     8,
       8,     8,     8,     8,     6,    10,     2,     1,     9,    15,
       2,     1,     6,     6,     5,     5,    12,    10,     7,     8,
       9,     4,     2,     1,     9,     9,     8,     8,     2,     1,
       8,     8,    12,     4,     2,     1,     8,    10,    10,     9,
      13,    16
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 146 "edn_bison.y" /* yacc.c:1646  */
    {p_top_edif=createEdif((yyvsp[-5].id),(yyvsp[-3].ref_library_node),(yyvsp[-2].cell_node),(yyvsp[-1].id));(yyval.top_EDIF_NODE)=p_top_edif=createEdif((yyvsp[-5].id),(yyvsp[-3].ref_library_node),(yyvsp[-2].cell_node),(yyvsp[-1].id));}
#line 1523 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 16:
#line 182 "edn_bison.y" /* yacc.c:1646  */
    {cnt_tmp++;(yyval.ref_library_node)=newRef_Lib_List_Entry((yyvsp[-1].ref_library_node),(yyvsp[0].ref_library_node),cnt_tmp);}
#line 1529 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 17:
#line 184 "edn_bison.y" /* yacc.c:1646  */
    {cnt_tmp=1;(yyval.ref_library_node)=newRef_Lib_List((yyvsp[0].ref_library_node));}
#line 1535 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 18:
#line 188 "edn_bison.y" /* yacc.c:1646  */
    {(yyval.ref_library_node)=createRef_Lib((yyvsp[-3].id),(yyvsp[-1].prim_node));}
#line 1541 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 19:
#line 191 "edn_bison.y" /* yacc.c:1646  */
    {cnt_tmp=1;(yyval.prim_node)=newPrim_List((yyvsp[0].prim_node));}
#line 1547 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 20:
#line 192 "edn_bison.y" /* yacc.c:1646  */
    {cnt_tmp++;(yyval.prim_node)=newPrim_List_Entry((yyvsp[-1].prim_node),(yyvsp[0].prim_node),cnt_tmp);}
#line 1553 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 21:
#line 196 "edn_bison.y" /* yacc.c:1646  */
    {(yyval.prim_node)=createPrim((yyvsp[-14].id),(yyvsp[-11].num_value),(yyvsp[-7].num_value),(yyvsp[-4].num_value),(yyvsp[-2].port_node));}
#line 1559 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 22:
#line 202 "edn_bison.y" /* yacc.c:1646  */
    {(yyval.port_node)=(yyvsp[-1].port_node);}
#line 1565 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 23:
#line 205 "edn_bison.y" /* yacc.c:1646  */
    {cnt_tmp++;(yyval.port_node)=newPort_List_Entry((yyvsp[-1].port_node),(yyvsp[0].port_node),cnt_tmp);}
#line 1571 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 24:
#line 206 "edn_bison.y" /* yacc.c:1646  */
    {cnt_tmp=1;(yyval.port_node)=newPort_List((yyvsp[0].port_node));}
#line 1577 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 25:
#line 208 "edn_bison.y" /* yacc.c:1646  */
    {(yyval.port_node)=createPort((yyvsp[-6].num_value),(yyvsp[-7].id),1);}
#line 1583 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 26:
#line 209 "edn_bison.y" /* yacc.c:1646  */
    {(yyval.port_node)=createPort((yyvsp[-6].num_value),(yyvsp[-7].id),2);}
#line 1589 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 27:
#line 210 "edn_bison.y" /* yacc.c:1646  */
    {(yyval.port_node)=createPort((yyvsp[-6].num_value),(yyvsp[-7].id),3);}
#line 1595 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 28:
#line 212 "edn_bison.y" /* yacc.c:1646  */
    {(yyval.port_node)=createPort(1,(yyvsp[-5].id),1);}
#line 1601 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 29:
#line 213 "edn_bison.y" /* yacc.c:1646  */
    {(yyval.port_node)=createPort(1,(yyvsp[-5].id),2);}
#line 1607 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 30:
#line 214 "edn_bison.y" /* yacc.c:1646  */
    {(yyval.port_node)=createPort(1,(yyvsp[-5].id),3);}
#line 1613 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 31:
#line 216 "edn_bison.y" /* yacc.c:1646  */
    {(yyval.port_node)=createPort(1,(yyvsp[-5].id),1);}
#line 1619 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 32:
#line 217 "edn_bison.y" /* yacc.c:1646  */
    {(yyval.port_node)=createPort(1,(yyvsp[-5].id),2);}
#line 1625 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 33:
#line 218 "edn_bison.y" /* yacc.c:1646  */
    {(yyval.port_node)=createPort(1,(yyvsp[-5].id),3);}
#line 1631 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 34:
#line 229 "edn_bison.y" /* yacc.c:1646  */
    {(yyval.cell_node)=(yyvsp[-1].cell_node);}
#line 1637 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 36:
#line 234 "edn_bison.y" /* yacc.c:1646  */
    {cnt_tmp++;(yyval.cell_node)=newCell_List_Entry((yyvsp[-1].cell_node),(yyvsp[0].cell_node),cnt_tmp);}
#line 1643 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 37:
#line 235 "edn_bison.y" /* yacc.c:1646  */
    {cnt_tmp=1;(yyval.cell_node)=newCell_List((yyvsp[0].cell_node));}
#line 1649 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 38:
#line 239 "edn_bison.y" /* yacc.c:1646  */
    {(yyval.cell_node)=createCell((yyvsp[-6].id),(yyvsp[-3].num_value),(yyvsp[-1].view_node));}
#line 1655 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 39:
#line 243 "edn_bison.y" /* yacc.c:1646  */
    {(yyval.view_node)=createView((yyvsp[-12].id),(yyvsp[-9].num_value),(yyvsp[-7].port_node),(yyvsp[-4].instance_node),(yyvsp[-3].net_node),(yyvsp[-1].property_node));}
#line 1661 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 40:
#line 247 "edn_bison.y" /* yacc.c:1646  */
    {cnt_tmp++;(yyval.instance_node)=newInstance_List_Entry((yyvsp[-1].instance_node),(yyvsp[0].instance_node),cnt_tmp);}
#line 1667 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 41:
#line 248 "edn_bison.y" /* yacc.c:1646  */
    {cnt_tmp=1;(yyval.instance_node)=newInstance_List((yyvsp[0].instance_node));}
#line 1673 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 42:
#line 252 "edn_bison.y" /* yacc.c:1646  */
    {
						(yyval.instance_node)=createInstance((yyvsp[-3].id),(yyvsp[-2].view_cell_lib_ref_node),(yyvsp[-1].property_node)); 
					 	printf("instance : %s find\n",(yyvsp[-3].id));
					}
#line 1682 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 43:
#line 257 "edn_bison.y" /* yacc.c:1646  */
    {
						(yyval.instance_node)=createInstance((yyvsp[-3].id),(yyvsp[-2].view_cell_lib_ref_node),(yyvsp[-1].property_node));
						printf("instance : %s find\n",(yyvsp[-3].id));
					}
#line 1691 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 44:
#line 262 "edn_bison.y" /* yacc.c:1646  */
    {
						(yyval.instance_node)=createInstance((yyvsp[-2].id),(yyvsp[-1].view_cell_lib_ref_node),NULL);
						printf("instance : %s find\n",(yyvsp[-2].id));
					}
#line 1700 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 45:
#line 267 "edn_bison.y" /* yacc.c:1646  */
    {	
						(yyval.instance_node)=createInstance((yyvsp[-2].id),(yyvsp[-1].view_cell_lib_ref_node),NULL);
						printf("instance : %s find\n",(yyvsp[-2].id));
					}
#line 1709 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 46:
#line 289 "edn_bison.y" /* yacc.c:1646  */
    { (yyval.id)=(yyvsp[-9].id);}
#line 1715 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 47:
#line 290 "edn_bison.y" /* yacc.c:1646  */
    { (yyval.id)=(yyvsp[-7].id);}
#line 1721 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 48:
#line 291 "edn_bison.y" /* yacc.c:1646  */
    { (yyval.id)=(yyvsp[-4].id);}
#line 1727 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 49:
#line 296 "edn_bison.y" /* yacc.c:1646  */
    {(yyval.view_cell_lib_ref_node)=decideInstance_Ref((yyvsp[-5].id),(yyvsp[-2].id),"work");}
#line 1733 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 50:
#line 298 "edn_bison.y" /* yacc.c:1646  */
    {(yyval.view_cell_lib_ref_node)=decideInstance_Ref("PRIM",(yyvsp[-3].id),(yyvsp[-2].id));}
#line 1739 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 51:
#line 301 "edn_bison.y" /* yacc.c:1646  */
    {(yyval.id)=(yyvsp[-1].id);    if(to_view_lib_ref) printf("%s       lib called\n",(yyvsp[-1].id));}
#line 1745 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 52:
#line 309 "edn_bison.y" /* yacc.c:1646  */
    {cnt_tmp++;(yyval.net_node)=newNet_List_Entry((yyvsp[-1].net_node),(yyvsp[0].net_node),cnt_tmp);}
#line 1751 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 53:
#line 310 "edn_bison.y" /* yacc.c:1646  */
    {cnt_tmp=1;(yyval.net_node)=newNet_List((yyvsp[0].net_node));}
#line 1757 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 54:
#line 312 "edn_bison.y" /* yacc.c:1646  */
    {(yyval.net_node)=findNet((yyvsp[-6].id),(yyvsp[-3].portref_node));printf("net : %s find\n",(yyvsp[-6].id));}
#line 1763 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 55:
#line 313 "edn_bison.y" /* yacc.c:1646  */
    {(yyval.net_node)=findNet((yyvsp[-6].id),(yyvsp[-3].portref_node));printf("net : %s find\n",(yyvsp[-6].id));}
#line 1769 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 56:
#line 314 "edn_bison.y" /* yacc.c:1646  */
    {(yyval.net_node)=findNet((yyvsp[-5].id),(yyvsp[-2].portref_node));printf("net : %s find\n",(yyvsp[-5].id));}
#line 1775 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 57:
#line 315 "edn_bison.y" /* yacc.c:1646  */
    {(yyval.net_node)=findNet((yyvsp[-5].id),(yyvsp[-2].portref_node));printf("net : %s find\n",(yyvsp[-5].id));}
#line 1781 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 58:
#line 318 "edn_bison.y" /* yacc.c:1646  */
    {cnt_tmp++;(yyval.portref_node)=newPortref_List_Entry((yyvsp[-1].portref_node),(yyvsp[0].portref_node),cnt_tmp);}
#line 1787 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 59:
#line 319 "edn_bison.y" /* yacc.c:1646  */
    {cnt_tmp=1;(yyval.portref_node)=newPortref_List((yyvsp[0].portref_node));}
#line 1793 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 60:
#line 323 "edn_bison.y" /* yacc.c:1646  */
    {(yyval.portref_node)=createPortref(1,(yyvsp[-5].id),0,(yyvsp[-2].id));/*Joined to INSTANCE'S PORT*/}
#line 1799 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 61:
#line 325 "edn_bison.y" /* yacc.c:1646  */
    {(yyval.portref_node)=createPortref(0,(yyvsp[-3].id),(yyvsp[-2].num_value),NULL);/*Joined to THIS CELL'S PORT bus*/}
#line 1805 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 62:
#line 327 "edn_bison.y" /* yacc.c:1646  */
    {(yyval.portref_node)=createPortref(0,(yyvsp[-7].id),(yyvsp[-6].num_value),(yyvsp[-2].id));/*Joined to THIS CELL'S PORT bus*/}
#line 1811 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 63:
#line 329 "edn_bison.y" /* yacc.c:1646  */
    {(yyval.portref_node)=createPortref(0,(yyvsp[-1].id),0,NULL);/*Joined to THIS CELL'S PORT*/}
#line 1817 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 64:
#line 335 "edn_bison.y" /* yacc.c:1646  */
    {cnt_tmp++;(yyval.property_node)=newProperty_List_Entry((yyvsp[-1].property_node),(yyvsp[0].property_node),cnt_tmp);}
#line 1823 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 65:
#line 336 "edn_bison.y" /* yacc.c:1646  */
    {cnt_tmp=1;(yyval.property_node)=newProperty_List((yyvsp[0].property_node));}
#line 1829 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 66:
#line 338 "edn_bison.y" /* yacc.c:1646  */
    {(yyval.property_node)=createProperty_Integer((yyvsp[-5].id),"integer",(yyvsp[-2].num_value));}
#line 1835 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 67:
#line 339 "edn_bison.y" /* yacc.c:1646  */
    {(yyval.property_node)=createProperty((yyvsp[-7].id),"string" ,(yyvsp[-3].id));}
#line 1841 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 68:
#line 340 "edn_bison.y" /* yacc.c:1646  */
    {(yyval.property_node)=createProperty((yyvsp[-7].id),"string" ,(yyvsp[-3].id));}
#line 1847 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 69:
#line 341 "edn_bison.y" /* yacc.c:1646  */
    {(yyval.property_node)=createProperty((yyvsp[-6].id),"string" ,NULL);}
#line 1853 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 70:
#line 351 "edn_bison.y" /* yacc.c:1646  */
    {(yyval.id)=(yyvsp[-10].id);printf("Congtulations !!!!!!find a design in this edn file successfully\n");}
#line 1859 "edn_bison.c" /* yacc.c:1646  */
    break;

  case 71:
#line 354 "edn_bison.y" /* yacc.c:1646  */
    {/*这一行的property是为design所设计的,所以暂时在这里没有考虑其语意值*/}
#line 1865 "edn_bison.c" /* yacc.c:1646  */
    break;


#line 1869 "edn_bison.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 356 "edn_bison.y" /* yacc.c:1906  */



