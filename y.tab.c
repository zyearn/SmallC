/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "myparse.y"

#include <stdio.h>
#include <stdlib.h>
#include "treeNode.h"
class treeNode;
#include <fstream>
#include <string.h>
#include <ctype.h>
#include "Global.h"
#include "codegen.h"
int yylex(void);
int yyerror(char* s);
extern FILE* yyin;
extern FILE* yyout;
void Tranverse(treeNode *, int);


/* Line 268 of yacc.c  */
#line 89 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IFX = 258,
     ELSE = 259,
     SRASN = 260,
     SLASN = 261,
     BORASN = 262,
     BXORASN = 263,
     BANDASN = 264,
     DIVASN = 265,
     MULASN = 266,
     MINASN = 267,
     ADDASN = 268,
     ASN = 269,
     LOR = 270,
     LAND = 271,
     BOR = 272,
     BXOR = 273,
     BAND = 274,
     NEQ = 275,
     EQ = 276,
     LTE = 277,
     LT = 278,
     GTE = 279,
     GT = 280,
     SR = 281,
     SL = 282,
     MIN = 283,
     ADD = 284,
     MOD = 285,
     DIV = 286,
     MUL = 287,
     BNOT = 288,
     PDEC = 289,
     PINC = 290,
     LNOT = 291,
     DOT = 292,
     INT = 293,
     ID = 294,
     SEMI = 295,
     COMMA = 296,
     TYPE = 297,
     LP = 298,
     RP = 299,
     LB = 300,
     RB = 301,
     LC = 302,
     RC = 303,
     STRUCT = 304,
     READ = 305,
     WRITE = 306,
     RETURN = 307,
     IF = 308,
     BREAK = 309,
     CONT = 310,
     FOR = 311
   };
#endif
/* Tokens.  */
#define IFX 258
#define ELSE 259
#define SRASN 260
#define SLASN 261
#define BORASN 262
#define BXORASN 263
#define BANDASN 264
#define DIVASN 265
#define MULASN 266
#define MINASN 267
#define ADDASN 268
#define ASN 269
#define LOR 270
#define LAND 271
#define BOR 272
#define BXOR 273
#define BAND 274
#define NEQ 275
#define EQ 276
#define LTE 277
#define LT 278
#define GTE 279
#define GT 280
#define SR 281
#define SL 282
#define MIN 283
#define ADD 284
#define MOD 285
#define DIV 286
#define MUL 287
#define BNOT 288
#define PDEC 289
#define PINC 290
#define LNOT 291
#define DOT 292
#define INT 293
#define ID 294
#define SEMI 295
#define COMMA 296
#define TYPE 297
#define LP 298
#define RP 299
#define LB 300
#define RB 301
#define LC 302
#define RC 303
#define STRUCT 304
#define READ 305
#define WRITE 306
#define RETURN 307
#define IF 308
#define BREAK 309
#define CONT 310
#define FOR 311




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 19 "myparse.y"

	treeNode* node;



/* Line 293 of yacc.c  */
#line 243 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 255 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   726

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNRULES -- Number of states.  */
#define YYNSTATES  174

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   311

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    13,    17,    19,    23,
      24,    26,    28,    34,    37,    39,    40,    42,    47,    52,
      56,    58,    59,    62,    67,    70,    71,    74,    76,    80,
      86,    94,   104,   107,   110,   116,   122,   125,   126,   130,
     134,   136,   138,   142,   144,   148,   151,   154,   157,   160,
     164,   168,   172,   176,   180,   184,   188,   192,   196,   200,
     204,   208,   212,   216,   220,   224,   228,   232,   236,   240,
     244,   248,   252,   256,   260,   264,   268,   272,   276,   281,
     284,   288,   290,   291,   296,   297,   301
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      58,     0,    -1,    59,    -1,    60,    59,    -1,    -1,    62,
      61,    40,    -1,    62,    66,    69,    -1,    75,    -1,    75,
      41,    61,    -1,    -1,    42,    -1,    63,    -1,    49,    64,
      47,    72,    48,    -1,    49,    39,    -1,    39,    -1,    -1,
      39,    -1,    65,    45,    38,    46,    -1,    39,    43,    67,
      44,    -1,    68,    41,    67,    -1,    68,    -1,    -1,    62,
      65,    -1,    47,    72,    70,    48,    -1,    71,    70,    -1,
      -1,    77,    40,    -1,    69,    -1,    52,    77,    40,    -1,
      53,    43,    77,    44,    71,    -1,    53,    43,    77,    44,
      71,     4,    71,    -1,    56,    43,    77,    40,    77,    40,
      77,    44,    71,    -1,    55,    40,    -1,    54,    40,    -1,
      50,    43,    77,    44,    40,    -1,    51,    43,    77,    44,
      40,    -1,    73,    72,    -1,    -1,    62,    74,    40,    -1,
      75,    41,    74,    -1,    75,    -1,    65,    -1,    65,    14,
      76,    -1,    77,    -1,    47,    79,    48,    -1,    36,    77,
      -1,    35,    77,    -1,    34,    77,    -1,    33,    77,    -1,
      77,    32,    77,    -1,    77,    31,    77,    -1,    77,    30,
      77,    -1,    77,    29,    77,    -1,    77,    28,    77,    -1,
      77,    27,    77,    -1,    77,    26,    77,    -1,    77,    25,
      77,    -1,    77,    24,    77,    -1,    77,    23,    77,    -1,
      77,    22,    77,    -1,    77,    21,    77,    -1,    77,    20,
      77,    -1,    77,    19,    77,    -1,    77,    18,    77,    -1,
      77,    17,    77,    -1,    77,    16,    77,    -1,    77,    15,
      77,    -1,    77,    14,    77,    -1,    77,    13,    77,    -1,
      77,    12,    77,    -1,    77,    11,    77,    -1,    77,    10,
      77,    -1,    77,     9,    77,    -1,    77,     8,    77,    -1,
      77,     7,    77,    -1,    77,     6,    77,    -1,    77,     5,
      77,    -1,    43,    77,    44,    -1,    39,    43,    79,    44,
      -1,    39,    78,    -1,    77,    37,    39,    -1,    38,    -1,
      -1,    45,    77,    46,    78,    -1,    -1,    77,    41,    79,
      -1,    77,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    52,    52,    69,    76,    79,    89,   101,   107,   115,
     118,   124,   132,   142,   151,   157,   160,   166,   177,   188,
     196,   202,   206,   215,   226,   233,   236,   243,   249,   257,
     267,   279,   293,   300,   307,   317,   329,   336,   339,   349,
     357,   365,   371,   381,   387,   398,   405,   412,   419,   426,
     434,   442,   450,   458,   466,   474,   482,   490,   498,   506,
     514,   522,   530,   538,   546,   554,   562,   570,   578,   586,
     594,   602,   610,   618,   626,   634,   642,   650,   658,   667,
     674,   682,   688,   691,   700,   703,   711
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IFX", "ELSE", "SRASN", "SLASN",
  "BORASN", "BXORASN", "BANDASN", "DIVASN", "MULASN", "MINASN", "ADDASN",
  "ASN", "LOR", "LAND", "BOR", "BXOR", "BAND", "NEQ", "EQ", "LTE", "LT",
  "GTE", "GT", "SR", "SL", "MIN", "ADD", "MOD", "DIV", "MUL", "BNOT",
  "PDEC", "PINC", "LNOT", "DOT", "INT", "ID", "SEMI", "COMMA", "TYPE",
  "LP", "RP", "LB", "RB", "LC", "RC", "STRUCT", "READ", "WRITE", "RETURN",
  "IF", "BREAK", "CONT", "FOR", "$accept", "PROGRAM", "EXTDEFS", "EXTDEF",
  "EXTVARS", "SPEC", "STSPEC", "OPTTAG", "VAR", "FUNC", "PARAS", "PARA",
  "STMTBLOCK", "STMTS", "STMT", "DEFS", "DEF", "DECS", "DEC", "INIT",
  "EXP", "ARRS", "ARGS", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    59,    59,    60,    60,    61,    61,    61,
      62,    62,    63,    63,    64,    64,    65,    65,    66,    67,
      67,    67,    68,    69,    70,    70,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    72,    72,    73,    74,
      74,    75,    75,    76,    76,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    78,    78,    79,    79
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     3,     1,     3,     0,
       1,     1,     5,     2,     1,     0,     1,     4,     4,     3,
       1,     0,     2,     4,     2,     0,     2,     1,     3,     5,
       7,     9,     2,     2,     5,     5,     2,     0,     3,     3,
       1,     1,     3,     1,     3,     2,     2,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     4,     2,
       3,     1,     0,     4,     0,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    10,    15,     0,     2,     4,     9,    11,    13,     0,
       1,     3,    16,     0,    41,     0,     7,    37,    21,     5,
      82,     0,    37,     6,     9,     0,     0,    37,     0,     0,
      20,    82,    82,    82,    82,    81,    84,    82,    82,    42,
      43,     0,    82,    16,     8,     0,    40,    12,    36,    22,
      18,    21,    48,    47,    46,    45,    82,    82,    79,     0,
      86,     0,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
       0,    17,     0,     0,    82,     0,     0,     0,     0,    27,
       0,    82,     0,    38,     0,    19,     0,     0,    77,    82,
      44,    76,    75,    74,    73,    72,    71,    70,    69,    68,
      67,    66,    65,    64,    63,    62,    61,    60,    59,    58,
      57,    56,    55,    54,    53,    52,    51,    50,    49,    80,
      82,    82,     0,    82,    33,    32,    82,    23,    24,    26,
      39,    78,    84,    85,     0,     0,    28,     0,     0,    83,
       0,     0,    82,    82,    34,    35,    29,     0,    82,    82,
      30,     0,    82,    31
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,    13,    25,     7,     9,    14,    15,
      29,    30,    99,   100,   101,    26,    27,    45,    16,    39,
     102,    58,    61
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -147
static const yytype_int16 yypact[] =
{
     -21,  -147,   -36,    23,  -147,   -21,   -15,  -147,    -7,    -6,
    -147,  -147,   -16,    30,   -12,    26,    45,   -21,   -21,  -147,
     679,    80,   -21,  -147,    86,    86,    79,   -21,    86,    84,
      88,    -4,    -4,    -4,    -4,  -147,    42,    -4,    -4,  -147,
     526,    98,   531,  -147,  -147,    90,   104,  -147,  -147,   101,
    -147,   -21,   111,   111,   111,   111,    -4,    -4,  -147,   145,
     345,   130,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
     140,  -147,   137,   138,    -4,   141,   143,   146,   142,  -147,
     139,   531,   382,  -147,    86,  -147,   144,    85,  -147,    -4,
    -147,   526,   526,   526,   526,   526,   526,   526,   526,   526,
     526,   596,   617,   637,   656,   674,   110,   110,   -22,   -22,
     -22,   -22,    47,    47,    51,    51,   111,   111,   111,  -147,
      -4,    -4,   418,    -4,  -147,  -147,    -4,  -147,  -147,  -147,
    -147,  -147,   173,  -147,   185,   225,  -147,   265,   454,  -147,
     179,   180,   555,    -4,  -147,  -147,   217,   490,   555,    -4,
    -147,   305,   555,  -147
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -147,  -147,   218,  -147,   200,    20,  -147,  -147,   197,  -147,
     175,  -147,   212,   127,  -146,    97,  -147,   154,   -24,  -147,
     -20,   107,   -37
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -26
static const yytype_int16 yytable[] =
{
      40,    46,    20,     8,    83,    84,    85,    86,    87,    88,
      89,    52,    53,    54,    55,    90,   166,    59,    60,   106,
       6,     1,   170,    10,    12,     6,   173,    18,     2,    31,
      32,    33,    34,    21,    35,    36,    60,   107,    28,    37,
     -14,    17,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
      19,    28,   153,    22,   142,    85,    86,    87,    88,    89,
      46,    87,    88,    89,    90,    56,    24,    57,    90,    60,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    41,    42,
     154,   155,    90,   157,    48,    43,   158,    47,    50,    51,
     103,   152,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,   167,    91,   104,    21,    90,    90,   171,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,   110,   139,
     140,   141,    90,   144,   143,   146,   145,   147,   151,   108,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    57,   164,
     165,   168,    90,    11,    44,    49,   105,    23,   148,   160,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,   150,   159,
       0,     0,    90,     0,     0,     0,     0,     0,     0,   161,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,     0,     0,
       0,     0,    90,     0,     0,     0,     0,     0,     0,   162,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,     0,     0,
       0,     0,    90,     0,     0,     0,     0,     0,     0,   172,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,     0,     0,
       0,     0,    90,     0,     0,     0,   109,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,     0,     0,     0,     0,    90,
       0,     0,   149,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,     0,     0,     0,     0,    90,     0,     0,   156,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,     0,     0,     0,
       0,    90,     0,     0,   163,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,     0,     0,     0,     0,    90,     0,     0,
     169,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,     0,
       0,     0,     0,    90,    31,    32,    33,    34,     0,    35,
      36,     0,     0,     0,    37,     0,     0,     0,    22,   -25,
       0,    92,    93,    94,    95,    96,    97,    98,    31,    32,
      33,    34,     0,    35,    36,     0,     0,     0,    37,     0,
       0,     0,    22,     0,     0,    92,    93,    94,    95,    96,
      97,    98,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,     0,
       0,     0,     0,    90,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
       0,     0,     0,     0,    90,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
       0,     0,     0,     0,    90,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,     0,
       0,     0,     0,    90,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,     0,     0,     0,
       0,    90,    31,    32,    33,    34,     0,    35,    36,     0,
       0,     0,    37,     0,     0,     0,    38
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-147))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      20,    25,    14,    39,    26,    27,    28,    29,    30,    31,
      32,    31,    32,    33,    34,    37,   162,    37,    38,    56,
       0,    42,   168,     0,    39,     5,   172,    43,    49,    33,
      34,    35,    36,    45,    38,    39,    56,    57,    18,    43,
      47,    47,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      40,    51,   109,    47,    94,    28,    29,    30,    31,    32,
     104,    30,    31,    32,    37,    43,    41,    45,    37,   109,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    38,    22,
     140,   141,    37,   143,    27,    39,   146,    48,    44,    41,
      40,    46,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,   163,    46,    41,    45,    37,    37,   169,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    48,    39,
      43,    43,    37,    40,    43,    43,    40,    48,    44,    44,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    45,    40,
      40,     4,    37,     5,    24,    28,    51,    15,   101,    44,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,   104,   152,
      -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,    44,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,    44,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,    44,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    37,    -1,    -1,    -1,    41,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    37,
      -1,    -1,    40,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    37,    -1,    -1,    40,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    37,    -1,    -1,    40,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    37,    -1,    -1,
      40,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    37,    33,    34,    35,    36,    -1,    38,
      39,    -1,    -1,    -1,    43,    -1,    -1,    -1,    47,    48,
      -1,    50,    51,    52,    53,    54,    55,    56,    33,    34,
      35,    36,    -1,    38,    39,    -1,    -1,    -1,    43,    -1,
      -1,    -1,    47,    -1,    -1,    50,    51,    52,    53,    54,
      55,    56,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    37,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    37,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    37,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    37,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    37,    33,    34,    35,    36,    -1,    38,    39,    -1,
      -1,    -1,    43,    -1,    -1,    -1,    47
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    42,    49,    58,    59,    60,    62,    63,    39,    64,
       0,    59,    39,    61,    65,    66,    75,    47,    43,    40,
      14,    45,    47,    69,    41,    62,    72,    73,    62,    67,
      68,    33,    34,    35,    36,    38,    39,    43,    47,    76,
      77,    38,    72,    39,    61,    74,    75,    48,    72,    65,
      44,    41,    77,    77,    77,    77,    43,    45,    78,    77,
      77,    79,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      37,    46,    50,    51,    52,    53,    54,    55,    56,    69,
      70,    71,    77,    40,    41,    67,    79,    77,    44,    41,
      48,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    39,
      43,    43,    77,    43,    40,    40,    43,    48,    70,    40,
      74,    44,    46,    79,    77,    77,    40,    77,    77,    78,
      44,    44,    44,    40,    40,    40,    71,    77,     4,    40,
      71,    77,    44,    71
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
      yychar = YYLEX;
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1806 of yacc.c  */
#line 53 "myparse.y"
    {
			treeNode* tmp = new treeNode("PROGRAM",1,1);
			tmp->child[0] = (yyvsp[(1) - (1)].node);
			(yyval.node) = tmp;
			//Tranverse(tmp,0);
		//	printf("ready to genProgram\n");
			if(FT["_G"] == NULL)
			{
				FT["_G"] = new map<string, int>();
			}
			freopen(outputFile.c_str(), "w", stdout);
			genProgram(tmp);
			tmp->Clear(tmp);
		}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 70 "myparse.y"
    {
			treeNode *tmp = new treeNode("EXTDEFS",2,1);
			tmp->child[0] = (yyvsp[(1) - (2)].node);
			tmp->child[1] = (yyvsp[(2) - (2)].node);
			(yyval.node) = tmp;
		}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 76 "myparse.y"
    {(yyval.node) = new treeNode("EXTDEFS",0,2);}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 80 "myparse.y"
    {
			treeNode *tmp = new treeNode("EXTDEF",3,1);
			tmp->child[0] = (yyvsp[(1) - (3)].node);
			tmp->child[1] = (yyvsp[(2) - (3)].node);
			tmp->child[2] = (yyvsp[(3) - (3)].node);
			(yyval.node) = tmp;
		//	printf("ready to genGT\n");
			genGT(tmp);
		}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 90 "myparse.y"
    {
			treeNode *tmp = new treeNode("EXTDEF",3,2);
			tmp->child[0] = (yyvsp[(1) - (3)].node);
			tmp->child[1] = (yyvsp[(2) - (3)].node);
			tmp->child[2] = (yyvsp[(3) - (3)].node);
			(yyval.node) = tmp;
		//	printf("ready to genFT\n");
			genFT(tmp);
		}
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 102 "myparse.y"
    {
			treeNode *tmp = new treeNode((yyvsp[(1) - (1)].node)->data,1,1);
			tmp->child[0] = (yyvsp[(1) - (1)].node);
			(yyval.node) = tmp;
		}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 108 "myparse.y"
    {
			treeNode *tmp = new treeNode((yyvsp[(1) - (3)].node)->data+","+(yyvsp[(3) - (3)].node)->data,3,2);
			tmp->child[0] = (yyvsp[(1) - (3)].node);
			tmp->child[1] = (yyvsp[(2) - (3)].node);
			tmp->child[2] = (yyvsp[(3) - (3)].node);
			(yyval.node) = tmp;
		}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 115 "myparse.y"
    {(yyval.node) = new treeNode("",0,3);}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 119 "myparse.y"
    {
			treeNode *tmp = new treeNode("",1,1);	//·µ»Ø¿Õ
			tmp->child[0] = (yyvsp[(1) - (1)].node);
			(yyval.node) = tmp;
		}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 125 "myparse.y"
    {
			treeNode *tmp = new treeNode((yyvsp[(1) - (1)].node)->data,1,2);
			tmp->child[0] = (yyvsp[(1) - (1)].node);
			(yyval.node) = tmp;
		}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 133 "myparse.y"
    {
			treeNode *tmp = new treeNode("|"+(yyvsp[(4) - (5)].node)->data+"|",5,1);
			tmp->child[0] = (yyvsp[(1) - (5)].node);
			tmp->child[1] = (yyvsp[(2) - (5)].node);
			tmp->child[2] = (yyvsp[(3) - (5)].node);
			tmp->child[3] = (yyvsp[(4) - (5)].node);
			tmp->child[4] = (yyvsp[(5) - (5)].node);
			(yyval.node) = tmp;
		}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 143 "myparse.y"
    {
			treeNode *tmp = new treeNode("STSPEC",2,2);
			tmp->child[0] = (yyvsp[(1) - (2)].node);
			tmp->child[1] = (yyvsp[(2) - (2)].node);
			(yyval.node) = tmp;
		}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 152 "myparse.y"
    {
			treeNode* tmp = new treeNode((yyvsp[(1) - (1)].node)->data,1,1);
			tmp->child[0] = (yyvsp[(1) - (1)].node);
			(yyval.node) = tmp;
		}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 157 "myparse.y"
    {(yyval.node) = new treeNode("",0,2);}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 161 "myparse.y"
    {
			treeNode* tmp = new treeNode((yyvsp[(1) - (1)].node)->data,1,1);
			tmp->child[0] = (yyvsp[(1) - (1)].node);
			(yyval.node) = tmp;
		}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 167 "myparse.y"
    {
			treeNode *tmp = new treeNode((yyvsp[(1) - (4)].node)->data+"["+(yyvsp[(3) - (4)].node)->data+"]",4,2);
			tmp->child[0] = (yyvsp[(1) - (4)].node);
			tmp->child[1] = (yyvsp[(2) - (4)].node);
			tmp->child[2] = (yyvsp[(3) - (4)].node);
			tmp->child[3] = (yyvsp[(4) - (4)].node);
			(yyval.node) = tmp;
		}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 178 "myparse.y"
    {
			treeNode *tmp = new treeNode("FUNC",4,1);
			tmp->child[0] = (yyvsp[(1) - (4)].node);
			tmp->child[1] = (yyvsp[(2) - (4)].node);
			tmp->child[2] = (yyvsp[(3) - (4)].node);
			tmp->child[3] = (yyvsp[(4) - (4)].node);
			(yyval.node) = tmp;
		}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 189 "myparse.y"
    {
			treeNode *tmp = new treeNode((yyvsp[(1) - (3)].node)->data+","+(yyvsp[(3) - (3)].node)->data,3,1);
			tmp->child[0] = (yyvsp[(1) - (3)].node);
			tmp->child[1] = (yyvsp[(2) - (3)].node);
			tmp->child[2] = (yyvsp[(3) - (3)].node);
			(yyval.node) = tmp;
		}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 197 "myparse.y"
    {
			treeNode *tmp = new treeNode((yyvsp[(1) - (1)].node)->data,1,2);
			tmp->child[0] = (yyvsp[(1) - (1)].node);
			(yyval.node) = tmp;
		}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 202 "myparse.y"
    {(yyval.node) = new treeNode("",0,3);}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 207 "myparse.y"
    {
			treeNode *tmp = new treeNode((yyvsp[(2) - (2)].node)->data,2,1);
			tmp->child[0] = (yyvsp[(1) - (2)].node);
			tmp->child[1] = (yyvsp[(2) - (2)].node);
			(yyval.node) = tmp;
		}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 216 "myparse.y"
    {
			treeNode *tmp = new treeNode("STMTBLOCK",4,1);
			tmp->child[0] = (yyvsp[(1) - (4)].node);
			tmp->child[1] = (yyvsp[(2) - (4)].node);
			tmp->child[2] = (yyvsp[(3) - (4)].node);
			tmp->child[3] = (yyvsp[(4) - (4)].node);
			(yyval.node) = tmp;
		}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 227 "myparse.y"
    {
			treeNode *tmp = new treeNode("STMTS",2,1);
			tmp->child[0] = (yyvsp[(1) - (2)].node);
			tmp->child[1] = (yyvsp[(2) - (2)].node);
			(yyval.node) = tmp;
		}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 233 "myparse.y"
    {(yyval.node) = new treeNode("STMTS",0,2);}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 237 "myparse.y"
    {
			treeNode *tmp = new treeNode("STMT",2,1);
			tmp->child[0] = (yyvsp[(1) - (2)].node);
			tmp->child[1] = (yyvsp[(2) - (2)].node);
			(yyval.node) = tmp;
		}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 244 "myparse.y"
    {
			treeNode* tmp = new treeNode("STMT",1,2);
			tmp->child[0] = (yyvsp[(1) - (1)].node);
			(yyval.node) = tmp;
		}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 250 "myparse.y"
    {
			treeNode *tmp = new treeNode("STMT",3,3);
			tmp->child[0] = (yyvsp[(1) - (3)].node);
			tmp->child[1] = (yyvsp[(2) - (3)].node);
			tmp->child[2] = (yyvsp[(3) - (3)].node);
			(yyval.node) = tmp;
		}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 258 "myparse.y"
    {
			treeNode *tmp = new treeNode("STMT",5,4);
			tmp->child[0] = (yyvsp[(1) - (5)].node);
			tmp->child[1] = (yyvsp[(2) - (5)].node);
			tmp->child[2] = (yyvsp[(3) - (5)].node);
			tmp->child[3] = (yyvsp[(4) - (5)].node);
			tmp->child[4] = (yyvsp[(5) - (5)].node);
			(yyval.node) = tmp;
		}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 268 "myparse.y"
    {
			treeNode *tmp = new treeNode("STMT",7,5);
			tmp->child[0] = (yyvsp[(1) - (7)].node);
			tmp->child[1] = (yyvsp[(2) - (7)].node);
			tmp->child[2] = (yyvsp[(3) - (7)].node);
			tmp->child[3] = (yyvsp[(4) - (7)].node);
			tmp->child[4] = (yyvsp[(5) - (7)].node);
			tmp->child[5] = (yyvsp[(6) - (7)].node);
			tmp->child[6] = (yyvsp[(7) - (7)].node);
			(yyval.node) = tmp;
		}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 280 "myparse.y"
    {
			treeNode *tmp = new treeNode("STMT",9,6);
			tmp->child[0] = (yyvsp[(1) - (9)].node);
			tmp->child[1] = (yyvsp[(2) - (9)].node);
			tmp->child[2] = (yyvsp[(3) - (9)].node);
			tmp->child[3] = (yyvsp[(4) - (9)].node);
			tmp->child[4] = (yyvsp[(5) - (9)].node);
			tmp->child[5] = (yyvsp[(6) - (9)].node);
			tmp->child[6] = (yyvsp[(7) - (9)].node);
			tmp->child[7] = (yyvsp[(8) - (9)].node);
			tmp->child[8] = (yyvsp[(9) - (9)].node);
			(yyval.node) = tmp;
		}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 294 "myparse.y"
    {
			treeNode *tmp = new treeNode("STMT",2,7);
			tmp->child[0] = (yyvsp[(1) - (2)].node);
			tmp->child[1] = (yyvsp[(2) - (2)].node);
			(yyval.node) = tmp;
		}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 301 "myparse.y"
    {
			treeNode *tmp = new treeNode("STMT",2,8);
			tmp->child[0] = (yyvsp[(1) - (2)].node);
			tmp->child[1] = (yyvsp[(2) - (2)].node);
			(yyval.node) = tmp;
		}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 308 "myparse.y"
    {
			treeNode *tmp = new treeNode("STMT",5,9);
			tmp->child[0] = (yyvsp[(1) - (5)].node);
			tmp->child[1] = (yyvsp[(2) - (5)].node);
			tmp->child[2] = (yyvsp[(3) - (5)].node);
			tmp->child[3] = (yyvsp[(4) - (5)].node);
			tmp->child[4] = (yyvsp[(5) - (5)].node);
			(yyval.node) = tmp;
		}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 318 "myparse.y"
    {
			treeNode *tmp = new treeNode("STMT",5,10);
			tmp->child[0] = (yyvsp[(1) - (5)].node);
			tmp->child[1] = (yyvsp[(2) - (5)].node);
			tmp->child[2] = (yyvsp[(3) - (5)].node);
			tmp->child[3] = (yyvsp[(4) - (5)].node);
			tmp->child[4] = (yyvsp[(5) - (5)].node);
			(yyval.node) = tmp;
		}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 330 "myparse.y"
    {
			treeNode *tmp = new treeNode((yyvsp[(1) - (2)].node)->data+","+(yyvsp[(2) - (2)].node)->data,2,1);
			tmp->child[0] = (yyvsp[(1) - (2)].node);
			tmp->child[1] = (yyvsp[(2) - (2)].node);
			(yyval.node) = tmp;
		}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 336 "myparse.y"
    {(yyval.node) = new treeNode("",0,2);}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 340 "myparse.y"
    {
			treeNode *tmp = new treeNode((yyvsp[(2) - (3)].node)->data,3,1);
			tmp->child[0] = (yyvsp[(1) - (3)].node);
			tmp->child[1] = (yyvsp[(2) - (3)].node);
			tmp->child[2] = (yyvsp[(3) - (3)].node);
			(yyval.node) = tmp;
		}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 350 "myparse.y"
    {
			treeNode *tmp = new treeNode((yyvsp[(1) - (3)].node)->data+","+(yyvsp[(3) - (3)].node)->data,3,1);
			tmp->child[0] = (yyvsp[(1) - (3)].node);
			tmp->child[1] = (yyvsp[(2) - (3)].node);
			tmp->child[2] = (yyvsp[(3) - (3)].node);
			(yyval.node) = tmp;
		}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 358 "myparse.y"
    {
			treeNode* tmp = new treeNode((yyvsp[(1) - (1)].node)->data,1,2);
			tmp->child[0] = (yyvsp[(1) - (1)].node);
			(yyval.node) = tmp;
		}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 366 "myparse.y"
    {
			treeNode* tmp = new treeNode((yyvsp[(1) - (1)].node)->data,1,1);
			tmp->child[0] = (yyvsp[(1) - (1)].node);
			(yyval.node) = tmp;
		}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 372 "myparse.y"
    {
			treeNode *tmp = new treeNode((yyvsp[(1) - (3)].node)->data,3,2);
			tmp->child[0] = (yyvsp[(1) - (3)].node);
			tmp->child[1] = (yyvsp[(2) - (3)].node);
			tmp->child[2] = (yyvsp[(3) - (3)].node);
			(yyval.node) = tmp;
		}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 382 "myparse.y"
    {
			treeNode* tmp = new treeNode("INIT",1,1);
			tmp->child[0] = (yyvsp[(1) - (1)].node);
			(yyval.node) = tmp;
		}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 388 "myparse.y"
    {
			treeNode *tmp = new treeNode("INIT",3,2);
			tmp->child[0] = (yyvsp[(1) - (3)].node);
			tmp->child[1] = (yyvsp[(2) - (3)].node);
			tmp->child[2] = (yyvsp[(3) - (3)].node);
			(yyval.node) = tmp;
			//Tranverse(tmp,0);
		}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 399 "myparse.y"
    {
			treeNode *tmp = new treeNode("EXP",2,1);
			tmp->child[0] = (yyvsp[(1) - (2)].node);
			tmp->child[1] = (yyvsp[(2) - (2)].node);
			(yyval.node) = tmp;
		}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 406 "myparse.y"
    {
			treeNode *tmp = new treeNode("EXP",2,2);
			tmp->child[0] = (yyvsp[(1) - (2)].node);
			tmp->child[1] = (yyvsp[(2) - (2)].node);
			(yyval.node) = tmp;
		}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 413 "myparse.y"
    {
			treeNode *tmp = new treeNode("EXP",2,3);
			tmp->child[0] = (yyvsp[(1) - (2)].node);
			tmp->child[1] = (yyvsp[(2) - (2)].node);
			(yyval.node) = tmp;
		}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 420 "myparse.y"
    {
			treeNode *tmp = new treeNode("EXP",2,4);
			tmp->child[0] = (yyvsp[(1) - (2)].node);
			tmp->child[1] = (yyvsp[(2) - (2)].node);
			(yyval.node) = tmp;
		}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 427 "myparse.y"
    {
			treeNode *tmp = new treeNode("EXP",3,5);
			tmp->child[0] = (yyvsp[(1) - (3)].node);
			tmp->child[1] = (yyvsp[(2) - (3)].node);
			tmp->child[2] = (yyvsp[(3) - (3)].node);
			(yyval.node) = tmp;
		}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 435 "myparse.y"
    {
			treeNode *tmp = new treeNode("EXP",3,6);
			tmp->child[0] = (yyvsp[(1) - (3)].node);
			tmp->child[1] = (yyvsp[(2) - (3)].node);
			tmp->child[2] = (yyvsp[(3) - (3)].node);
			(yyval.node) = tmp;
		}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 443 "myparse.y"
    {
			treeNode *tmp = new treeNode("EXP",3,7);
			tmp->child[0] = (yyvsp[(1) - (3)].node);
			tmp->child[1] = (yyvsp[(2) - (3)].node);
			tmp->child[2] = (yyvsp[(3) - (3)].node);
			(yyval.node) = tmp;
		}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 451 "myparse.y"
    {
			treeNode *tmp = new treeNode("EXP",3,8);
			tmp->child[0] = (yyvsp[(1) - (3)].node);
			tmp->child[1] = (yyvsp[(2) - (3)].node);
			tmp->child[2] = (yyvsp[(3) - (3)].node);
			(yyval.node) = tmp;
		}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 459 "myparse.y"
    {
			treeNode *tmp = new treeNode("EXP",3,9);
			tmp->child[0] = (yyvsp[(1) - (3)].node);
			tmp->child[1] = (yyvsp[(2) - (3)].node);
			tmp->child[2] = (yyvsp[(3) - (3)].node);
			(yyval.node) = tmp;
		}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 467 "myparse.y"
    {
			treeNode *tmp = new treeNode("EXP",3,10);
			tmp->child[0] = (yyvsp[(1) - (3)].node);
			tmp->child[1] = (yyvsp[(2) - (3)].node);
			tmp->child[2] = (yyvsp[(3) - (3)].node);
			(yyval.node) = tmp;
		}
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 475 "myparse.y"
    {
			treeNode *tmp = new treeNode("EXP",3,11);
			tmp->child[0] = (yyvsp[(1) - (3)].node);
			tmp->child[1] = (yyvsp[(2) - (3)].node);
			tmp->child[2] = (yyvsp[(3) - (3)].node);
			(yyval.node) = tmp;
		}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 483 "myparse.y"
    {
			treeNode *tmp = new treeNode("EXP",3,12);
			tmp->child[0] = (yyvsp[(1) - (3)].node);
			tmp->child[1] = (yyvsp[(2) - (3)].node);
			tmp->child[2] = (yyvsp[(3) - (3)].node);
			(yyval.node) = tmp;
		}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 491 "myparse.y"
    {
			treeNode *tmp = new treeNode("EXP",3,13);
			tmp->child[0] = (yyvsp[(1) - (3)].node);
			tmp->child[1] = (yyvsp[(2) - (3)].node);
			tmp->child[2] = (yyvsp[(3) - (3)].node);
			(yyval.node) = tmp;
		}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 499 "myparse.y"
    {
			treeNode *tmp = new treeNode("EXP",3,14);
			tmp->child[0] = (yyvsp[(1) - (3)].node);
			tmp->child[1] = (yyvsp[(2) - (3)].node);
			tmp->child[2] = (yyvsp[(3) - (3)].node);
			(yyval.node) = tmp;
		}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 507 "myparse.y"
    {
			treeNode *tmp = new treeNode("EXP",3,15);
			tmp->child[0] = (yyvsp[(1) - (3)].node);
			tmp->child[1] = (yyvsp[(2) - (3)].node);
			tmp->child[2] = (yyvsp[(3) - (3)].node);
			(yyval.node) = tmp;
		}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 515 "myparse.y"
    {
			treeNode *tmp = new treeNode("EXP",3,16);
			tmp->child[0] = (yyvsp[(1) - (3)].node);
			tmp->child[1] = (yyvsp[(2) - (3)].node);
			tmp->child[2] = (yyvsp[(3) - (3)].node);
			(yyval.node) = tmp;
		}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 523 "myparse.y"
    {
			treeNode *tmp = new treeNode("EXP",3,17);
			tmp->child[0] = (yyvsp[(1) - (3)].node);
			tmp->child[1] = (yyvsp[(2) - (3)].node);
			tmp->child[2] = (yyvsp[(3) - (3)].node);
			(yyval.node) = tmp;
		}
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 531 "myparse.y"
    {
			treeNode *tmp = new treeNode("EXP",3,18);
			tmp->child[0] = (yyvsp[(1) - (3)].node);
			tmp->child[1] = (yyvsp[(2) - (3)].node);
			tmp->child[2] = (yyvsp[(3) - (3)].node);
			(yyval.node) = tmp;
		}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 539 "myparse.y"
    {
			treeNode *tmp = new treeNode("EXP",3,19);
			tmp->child[0] = (yyvsp[(1) - (3)].node);
			tmp->child[1] = (yyvsp[(2) - (3)].node);
			tmp->child[2] = (yyvsp[(3) - (3)].node);
			(yyval.node) = tmp;
		}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 547 "myparse.y"
    {
			treeNode *tmp = new treeNode("EXP",3,20);
			tmp->child[0] = (yyvsp[(1) - (3)].node);
			tmp->child[1] = (yyvsp[(2) - (3)].node);
			tmp->child[2] = (yyvsp[(3) - (3)].node);
			(yyval.node) = tmp;
		}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 555 "myparse.y"
    {
			treeNode *tmp = new treeNode("EXP",3,21);
			tmp->child[0] = (yyvsp[(1) - (3)].node);
			tmp->child[1] = (yyvsp[(2) - (3)].node);
			tmp->child[2] = (yyvsp[(3) - (3)].node);
			(yyval.node) = tmp;
		}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 563 "myparse.y"
    {
			treeNode *tmp = new treeNode("EXP",3,22);
			tmp->child[0] = (yyvsp[(1) - (3)].node);
			tmp->child[1] = (yyvsp[(2) - (3)].node);
			tmp->child[2] = (yyvsp[(3) - (3)].node);
			(yyval.node) = tmp;
		}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 571 "myparse.y"
    {
			treeNode *tmp = new treeNode("EXP",3,23);
			tmp->child[0] = (yyvsp[(1) - (3)].node);
			tmp->child[1] = (yyvsp[(2) - (3)].node);
			tmp->child[2] = (yyvsp[(3) - (3)].node);
			(yyval.node) = tmp;
		}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 579 "myparse.y"
    {
			treeNode *tmp = new treeNode("EXP",3,24);
			tmp->child[0] = (yyvsp[(1) - (3)].node);
			tmp->child[1] = (yyvsp[(2) - (3)].node);
			tmp->child[2] = (yyvsp[(3) - (3)].node);
			(yyval.node) = tmp;
		}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 587 "myparse.y"
    {
			treeNode *tmp = new treeNode("EXP",3,25);
			tmp->child[0] = (yyvsp[(1) - (3)].node);
			tmp->child[1] = (yyvsp[(2) - (3)].node);
			tmp->child[2] = (yyvsp[(3) - (3)].node);
			(yyval.node) = tmp;
		}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 595 "myparse.y"
    {
			treeNode *tmp = new treeNode("EXP",3,26);
			tmp->child[0] = (yyvsp[(1) - (3)].node);
			tmp->child[1] = (yyvsp[(2) - (3)].node);
			tmp->child[2] = (yyvsp[(3) - (3)].node);
			(yyval.node) = tmp;
		}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 603 "myparse.y"
    {
			treeNode *tmp = new treeNode("EXP",3,27);
			tmp->child[0] = (yyvsp[(1) - (3)].node);
			tmp->child[1] = (yyvsp[(2) - (3)].node);
			tmp->child[2] = (yyvsp[(3) - (3)].node);
			(yyval.node) = tmp;
		}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 611 "myparse.y"
    {
			treeNode *tmp = new treeNode("EXP",3,28);
			tmp->child[0] = (yyvsp[(1) - (3)].node);
			tmp->child[1] = (yyvsp[(2) - (3)].node);
			tmp->child[2] = (yyvsp[(3) - (3)].node);
			(yyval.node) = tmp;
		}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 619 "myparse.y"
    {
			treeNode *tmp = new treeNode("EXP",3,29);
			tmp->child[0] = (yyvsp[(1) - (3)].node);
			tmp->child[1] = (yyvsp[(2) - (3)].node);
			tmp->child[2] = (yyvsp[(3) - (3)].node);
			(yyval.node) = tmp;
		}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 627 "myparse.y"
    {
			treeNode *tmp = new treeNode("EXP",3,30);
			tmp->child[0] = (yyvsp[(1) - (3)].node);
			tmp->child[1] = (yyvsp[(2) - (3)].node);
			tmp->child[2] = (yyvsp[(3) - (3)].node);
			(yyval.node) = tmp;
		}
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 635 "myparse.y"
    {
			treeNode *tmp = new treeNode("EXP",3,31);
			tmp->child[0] = (yyvsp[(1) - (3)].node);
			tmp->child[1] = (yyvsp[(2) - (3)].node);
			tmp->child[2] = (yyvsp[(3) - (3)].node);
			(yyval.node) = tmp;
		}
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 643 "myparse.y"
    {
			treeNode *tmp = new treeNode("EXP",3,32);
			tmp->child[0] = (yyvsp[(1) - (3)].node);
			tmp->child[1] = (yyvsp[(2) - (3)].node);
			tmp->child[2] = (yyvsp[(3) - (3)].node);
			(yyval.node) = tmp;
		}
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 651 "myparse.y"
    {
			treeNode *tmp = new treeNode("EXP",3,33);
			tmp->child[0] = (yyvsp[(1) - (3)].node);
			tmp->child[1] = (yyvsp[(2) - (3)].node);
			tmp->child[2] = (yyvsp[(3) - (3)].node);
			(yyval.node) = tmp;
		}
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 659 "myparse.y"
    {
			treeNode *tmp = new treeNode("EXP",4,34);
			tmp->child[0] = (yyvsp[(1) - (4)].node);
			tmp->child[1] = (yyvsp[(2) - (4)].node);
			tmp->child[2] = (yyvsp[(3) - (4)].node);
			tmp->child[3] = (yyvsp[(4) - (4)].node);
			(yyval.node) = tmp;
		}
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 668 "myparse.y"
    {
			treeNode *tmp = new treeNode("EXP",2,35);
			tmp->child[0] = (yyvsp[(1) - (2)].node);
			tmp->child[1] = (yyvsp[(2) - (2)].node);
			(yyval.node) = tmp;
		}
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 675 "myparse.y"
    {
			treeNode *tmp = new treeNode("EXP",3,36);
			tmp->child[0] = (yyvsp[(1) - (3)].node);
			tmp->child[1] = (yyvsp[(2) - (3)].node);
			tmp->child[2] = (yyvsp[(3) - (3)].node);
			(yyval.node) = tmp;
		}
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 683 "myparse.y"
    {
			treeNode *tmp = new treeNode("EXP",1,37);
			tmp->child[0] = (yyvsp[(1) - (1)].node);
			(yyval.node) = tmp;
		}
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 688 "myparse.y"
    {(yyval.node) = new treeNode("EXP",0,38);}
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 692 "myparse.y"
    {
			treeNode *tmp = new treeNode("ARRS",4,1);
			tmp->child[0] = (yyvsp[(1) - (4)].node);
			tmp->child[1] = (yyvsp[(2) - (4)].node);
			tmp->child[2] = (yyvsp[(3) - (4)].node);
			tmp->child[3] = (yyvsp[(4) - (4)].node);
			(yyval.node) = tmp;
		}
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 700 "myparse.y"
    {(yyval.node) = new treeNode("ARRS",0,2);}
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 704 "myparse.y"
    {
			treeNode *tmp = new treeNode("ARGS",3,1);
			tmp->child[0] = (yyvsp[(1) - (3)].node);
			tmp->child[1] = (yyvsp[(2) - (3)].node);
			tmp->child[2] = (yyvsp[(3) - (3)].node);
			(yyval.node) = tmp;
		}
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 712 "myparse.y"
    {
			treeNode *tmp = new treeNode("ARGS",1,2);
			tmp->child[0] = (yyvsp[(1) - (1)].node);
			(yyval.node) = tmp;
		}
    break;



/* Line 1806 of yacc.c  */
#line 2799 "y.tab.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 718 "myparse.y"


#include "lex.yy.c"

int main(int argc, char* argv[])
{
//	printf("111\n");
//	printf("enter file name: ");
//	char name[20];
//	scanf("%s",name);
	if(argc != 3)
	{
		fprintf(stderr,"Usage: ./scc <input> <output>\n");
		return 0;
	}
	yyin = fopen(argv[1],"r");
//	yyout = fopen(argv[2],"w");
	outputFile = argv[2];

	if(yyin == NULL)
		printf("yyin == NULL!\n");
//	printf("111\n");
	yyparse();

	fclose(yyin);
	fclose(yyout);
	return 0;
}

int yyerror(char* s)
{
	printf("line%4d Error :%s,%s\n",yylineno,s,yytext);
}


void Tranverse(treeNode *t, int n)
{
	int i;
	for(i=0; i<n; i++) fprintf(yyout,"\t");
	fprintf(yyout,"%s\n",(t->data).c_str());
	if(t->childnum >= 1)
	{
		for(i=0; i< (t->childnum); i++)
			Tranverse(t->child[i],n+1);
	}
}



