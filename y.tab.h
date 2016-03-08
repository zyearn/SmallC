/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
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

/* Line 2068 of yacc.c  */
#line 19 "myparse.y"

	treeNode* node;



/* Line 2068 of yacc.c  */
#line 168 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


