#include "codegen.h"
#include "treeNode.h"
#include "Global.h"
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

void genGT(treeNode* node)	//for global construct symboltable
{
	//int a,b,c[10] ÀàÐÍµÄÇé¿ö
	if(FT["_G"] == NULL)
	{
		FT["_G"] = new map<string, int>();
	}
	if(ISA["_G"] == NULL)
	{
		ISA["_G"] = new map<string, int>();
	}
	if(node->child[0]->type == 1)	
	{
		int size = 0;
		if( (*FT["_G"])["#"] != 0)
		{
			size = (*FT["_G"])["#"] /4;
		}
		string tmp = node->child[1]->data;
		if(tmp[tmp.length()-1] != ',')
		{
			tmp += ",";
		}

		while(tmp.find(",")>=0 && tmp.find(",")<tmp.length() )
		{
			// int situation
			if(tmp.find(",") < tmp.find("["))
			{
				string s = tmp.substr(0,tmp.find(","));
				tmp.erase(0,tmp.find(","));
				tmp.erase(tmp.find(","),1);
				size++;
				if((*FT["_G"])[s] == 0)
					(*FT["_G"])[s] = size*4;
				else
				{
					freopen(outputFile.c_str(), "w", stdout);
					cout << "Error.";
					fprintf(stderr, "\nCompile fail!\n");
					fprintf(stderr, "error occurs, %s is redefined\n", s.c_str() );
					exit(0);
				}
			}
			// array£¬eg a[10]
			else if(tmp.find("[") < tmp.find(","))
			{
				string s = tmp.substr(0,tmp.find("["));
				string num = tmp.substr(tmp.find("[")+1, tmp.find("]"));
				tmp.erase(0,tmp.find(","));
				tmp.erase(tmp.find(","),1);				
				size += atoi(num.c_str());
				if((*FT["_G"])[s] == 0)
				{
					(*FT["_G"])[s] = size*4;
					(*ISA["_G"])[s] = 1;
				}
				else
				{
					freopen(outputFile.c_str(), "w", stdout);
					cout << "Error.";
					fprintf(stderr, "\nCompile fail!\n");
					fprintf(stderr, "error occurs, %s is redefined\n", s.c_str() );
					exit(0);
				}
			}
		}
		(*FT["_G"])["#"] = size*4;
	}
	//struct opt {DEFS} £¬modify ST
	else if (node->child[0]->child[0]->type == 1)
	{
		//printf("enter type == 2 (1)\n");
		treeNode *stspec = node->child[0]->child[0];
		string stname = stspec->child[1]->data;
		if( ST[stname] == 0)	//Èç¹ûstruct Ã»¶¨Òå£¬ÔòÐÞ¸Äsymboltable,
		{	//ÕâÀïÓÐ¸öÎÊÌâ£¬Èô¶¼Ã»ÓÐÖ¸¶¨OPTTAG£¬Ôò³öÏÖredefined´íÎó£¬µ«²»ÊÇËùÏ£ÍûµÄ
			ST[stname] = new map<string ,int>();
		}
		else
		{
			freopen(outputFile.c_str(), "w", stdout);
			cout << "Error.";
			fprintf(stderr, "\nCompile fail!\n");
			fprintf(stderr, "error occurs, %s is redefined\n", (stspec->child[2]->data).c_str() );
			exit(0);
		}
		string tmp = stspec->child[3]->data;
		if(tmp[tmp.length()-1] != ',')
		{
			tmp += ",";
		}
		int size = 0;
		while(tmp.find(",")>=0 && tmp.find(",")<tmp.length() )
		{
			string s = tmp.substr(0,tmp.find(","));
			tmp.erase(0,tmp.find(","));
			tmp.erase(tmp.find(","),1);
			size++;
			if((*ST[stname])[s] == 0)
			{
				(*ST[stname])[s] = size*4;
			}
			else
			{
				freopen(outputFile.c_str(), "w", stdout);
				cout << "Error.";
				fprintf(stderr, "\nCompile fail!\n");
				fprintf(stderr, "error occurs, %s is redefined\n", (stname+"."+s).c_str() );
				exit(0);
			}
		}
		(*ST[stname])["#"] = size*4;
		//´¦Àístruct id {..}id_1,id_2; Çé¿ö
		tmp = node->child[1]->data;
		if(tmp != "")
		{
			if(tmp[tmp.length()-1] != ',')
			{
				tmp += ",";
			}// + ","
			if((*FT["_G"])["#"] != 0)
			{	
				size = (*FT["_G"])["#"] /4;
			}
			while(tmp.find(",")>=0 && tmp.find(",")<tmp.length() )
			{
				string s = tmp.substr(0,tmp.find(","));
				tmp.erase(0,tmp.find(","));
				tmp.erase(tmp.find(","),1);
				size += ( (*ST[stname])["#"] )/4;
				if((*FT["_G"])[s] == 0)
				{
					(*FT["_G"])[s] = size*4;
					STAC[s] = stname;
				}
				else
				{
					freopen(outputFile.c_str(), "w", stdout);
					cout << "Error.";
					fprintf(stderr, "\nCompile fail!\n");
					fprintf(stderr, "error occurs, %s is redefined\n", s.c_str() );
					exit(0);
				}
			}
			(*FT["_G"])["#"] = size*4;
		}
	}
	//struct id xxx; Çé¿ö
	else if(node->child[0]->child[0]->type == 2)
	{
	//	printf("enter type == 2 (2)\n");
		string stname = node->child[0]->child[0]->child[1]->data;
		if(ST[stname] == NULL)
		{
			freopen(outputFile.c_str(), "w", stdout);
			cout << "Error.";
			fprintf(stderr, "\nCompile fail!\n");
			fprintf(stderr, "error occurs, %s is not defined\n", stname.c_str() );
			exit(0);
		}
		int size = 0;
		if((*FT["_G"])["#"] != 0)
		{
			size = (*FT["_G"])["#"] /4;
		}
		string tmp = node->child[1]->data;
		if(tmp[tmp.length()-1] != ',')
		{
			tmp += ",";
		}
		while(tmp.find(",")>=0 && tmp.find(",")<tmp.length() )
		{
			string s = tmp.substr(0,tmp.find(","));
			tmp.erase(0,tmp.find(","));
			tmp.erase(tmp.find(","),1);
			size += (*ST[stname])["#"]/4;
			if((*FT["_G"])[s] == 0)
			{
				(*FT["_G"])[s] = size*4;
				STAC[s] = stname;
			}
			else
			{
				freopen(outputFile.c_str(), "w", stdout);
				cout << "Error.";
				fprintf(stderr, "\nCompile fail!\n");
				fprintf(stderr, "error occurs, %s is redefined\n", s.c_str() );
				exit(0);
			}
		}
		(*FT["_G"])["#"] = size*4;
	}
}

void genFT(treeNode* node)	//ÎªfunctionµÄ²ÎÊýºÍ¾Ö²¿±äÁ¿½¨Á¢symboltable
{
	int size = 0;
	if(FT[node->child[1]->child[0]->data] == 0)
	{
		FT[node->child[1]->child[0]->data] = new map<string, int>();
	}
	if(ISA[node->child[1]->child[0]->data] == 0)
	{
		ISA[node->child[1]->child[0]->data] = new map<string, int>();
	}	

	string tmp = node->child[1]->child[2]->data;
	if(tmp[tmp.length()-1] != ',')
	{	
		tmp += ",";
	}
	if(node->child[1]->child[2]->type != 3)
	{
		while(tmp.find(",")>=0 && tmp.find(",")<tmp.length())
		{
			string s = tmp.substr(0,tmp.find(","));
			tmp.erase(0,tmp.find(","));
			tmp.erase(tmp.find(","),1);
			size++;
			if((*FT[node->child[1]->child[0]->data])[s] == 0)
				(*FT[node->child[1]->child[0]->data])[s] = size*4;
			else
			{
				freopen(outputFile.c_str(), "w", stdout);
				cout << "Error.";
				fprintf(stderr, "\nCompile fail!\n");
				fprintf(stderr, "error occurs, %s is redefined\n", s.c_str() );
				exit(0);
			}
		}
	}
	
	int localn = 0;//¼ÇÂ¼¾Ö²¿±äÁ¿µÄ¸öÊý
	tmp = node->child[2]->child[1]->data;
	if(tmp[tmp.length()-1] != ',')
	{
		tmp += ",";
	}// + ","
	if(node->child[2]->child[1]->type == 1)
	{
		while(tmp.find(",")>=0 && tmp.find(",")<tmp.length() )
		{
			// int 
			if(tmp.find(",") < tmp.find("[") && tmp.find(",") <tmp.find("|"))
			{
				localn++;	
				string s = tmp.substr(0,tmp.find(","));
				tmp.erase(0,tmp.find(","));
				tmp.erase(tmp.find(","),1);
				size++;
				if((*FT[node->child[1]->child[0]->data])[s] == 0)
					(*FT[node->child[1]->child[0]->data])[s] = size*4;
				else
				{
					freopen(outputFile.c_str(), "w", stdout);
					cout << "Error.";
					fprintf(stderr, "\nCompile fail!\n");
					fprintf(stderr, "error occurs, %s is redefined\n", s.c_str() );
					exit(0);
				}
			}
			// Êý×é£¬eg a[10]
			else if(tmp.find("[") < tmp.find(",") && tmp.find("[") < tmp.find("|"))
			{
				string s = tmp.substr(0,tmp.find("["));
				string num = tmp.substr(tmp.find("[")+1, tmp.find("]"));
				tmp.erase(0,tmp.find(","));
				tmp.erase(tmp.find(","),1);				
				size += atoi(num.c_str());
				localn += atoi(num.c_str());
				if((*FT[node->child[1]->child[0]->data])[s] == 0)
				{
					(*FT[node->child[1]->child[0]->data])[s] = size*4;
					(*ISA[node->child[1]->child[0]->data])[s] = 1;
				}
				else
				{
					freopen(outputFile.c_str(), "w", stdout);
					cout << "Error.";
					fprintf(stderr, "\nCompile fail!\n");
					fprintf(stderr, "error occurs, %s is redefined\n", s.c_str() );
					exit(0);
				}
			}
			//struct: |a,b,c|w| ÒÔºóÔÙËµ£¡
			/*else if(tmp.find("|") < tmp.find(",") && tmp.find("|") < tmp.find("["))
			{
				int n = tmp.find("|",1);
				int n2 = tmp.find("|",n+1);
				string t1 = tmp.substr(1,n);
				string t2 = tmp.substr(n+1,n2);
				t1
				
			}*/
			
		}
	}
	(*FT[node->child[1]->child[0]->data])["#"] = size*4;
	(*FT[node->child[1]->child[0]->data])["##"] = localn;
	
}


void genProgram(treeNode* node)
{
//	freopen("t.s","w",stdout);
	cout << ".data" << endl;
	cout << "newline: .asciiz \"\\n\"" << endl;
	cout << ".text\n.globl main\n";
	genExtdefs(node->child[0], node->child[0]->type);

}

void genExtdefs(treeNode* node,int type)
{
	switch(type)
	{
		case 1:
			genExtdef(node->child[0], node->child[0]->type);
			genExtdefs(node->child[1], node->child[1]->type);
			break;
		case 2:
			break;
	}
}


void genExtdef(treeNode* node,int type)
{
	if(type == 1)//type == 1´¦Àí¶ÔÈ«¾Ö±äÁ¿¸³Öµ
	{	
		if(node->child[0]->type == 1)//¶Ôint int[]¸³Öµ
		{
			genExtvars(node->child[1], node->child[1]->type, "_G");
		}
		else//¶Ôstruct¸³Öµ
		{
		
		}
	}
	else if(type == 2)
	{
		// type == 2 Éú³Éº¯Êý´úÂë
		cout << endl; 
		if (node->child[1]->child[0]->data != "main") cout << "__"; 
		cout << node->child[1]->child[0]->data << ":" << endl;
		
		//mainÈ«¾Ö±äÁ¿ºÍ¾Ö²¿±äÁ¿ÈëÕ»
		if (node->child[1]->child[0]->data == "main")
		{
			cout << "add $sp, $sp, -" << (*FT["_G"])["#"] << endl;
			cout << "move $s2, $sp" << endl;
			//ÒÔÉÏÊÇ´¦ÀíÈ«¾Ö±äÁ¿£¬$s2ÓÃÀ´×÷Îª»ùÖ·¼Ä´æÆ÷
			//´Ë´¦²åÈë¾Ö²¿±äÁ¿
			cout << "add $sp, $sp, -" << (*FT[node->child[1]->child[0]->data])["##"] * 4 << endl;
			cout << "add $sp, $sp, -4" << endl;
			cout << "move $s0, $sp" << endl;
			//È»ºóÌø×ªµ½ÉèÖÃÈ«¾Ö±äÁ¿µÄµØ·½, È«¾Ö±äÁ¿µÄ¸³Öµ
			if( globalNumber != 1)	// !=ËµÃ÷´æÔÚ
			{
				cout << "j _G_1" << endl;
				//Ìø»ØÀ´
				cout << "_G_" << globalNumber << ":" << endl;
			}			
		}

		cout << "add $sp, $sp, -4" << endl; 
		cout << "sw $ra, 0($sp)" << endl; ////ÉèÖÃÐÂµÄ·µ»ØµØÖ·
//		printf("ready to genStmtblock()\n");
		genStmtblock(node->child[2], node->child[2]->type, node->child[1]->child[0]->data);
		
		/*
		if (node->child[0]->data == "main"){
			cout << "li $v0, 1" << endl;
			cout << "la $a0, 0($t0)" << endl;
			cout << "syscall" << endl;
			cout << "li $v0, 4" << endl;
			cout << "la $a0, newline" << endl;
			cout << "syscall" << endl;
		}*/

		cout << "lw $s1 -4($s0)" << endl;
		cout << "jr $s1" << endl;
	}
}

void genExtvars(treeNode* node, int type, string scope)
{
	switch(type)
	{
		case 1:
		genDec(node->child[0], node->child[0]->type, "_G");
		break;
		case 2:
		genDec(node->child[0], node->child[0]->type, "_G");
		genExtvars(node->child[2], node->child[2]->type, "_G");
	}
}

void genStmtblock(treeNode* node, int type, string scope, int labelN)
{
	genDefs(node->child[1], node->child[1]->type, scope);
	genStmts(node->child[2],node->child[2]->type, scope, labelN);
}

void genStmts(treeNode* node, int type, string scope, int labelN)
{
	switch(type)
	{
		case 1:
		genStmt(node->child[0], node->child[0]->type, scope, labelN);
		//
				genStmts(node->child[1], node->child[1]->type, scope, labelN);
		break;
		case 2:
		break;
	}
}

void genStmt(treeNode* node, int type, string scope, int labelN)
{
	switch(type)
	{
		case 1:
		genExp(node->child[0],node->child[0]->type, scope);
		break;
		case 2:
		genStmtblock(node->child[0],node->child[0]->type, scope, labelN);
		break;
		case 3:	
		{
			genExp(node->child[1],node->child[1]->type, scope);
			/*
			if(scope == "main")
			{
				cout << "li $v0, 1" << endl;
				cout << "move $a0, $t0" << endl;
				cout << "syscall" << endl;
				cout << "li $v0, 4" << endl;
				cout << "la $a0, newline" << endl;
				cout << "syscall" << endl;
			}*/
			cout << "lw $s1 -4($s0)" << endl;
			cout << "jr $s1" << endl;
		}
		break;
		case 4:
		{
			int local = labelNumber;
			labelNumber++;
			genExp(node->child[2], node->child[2]->type, scope);
			cout << "beqz $t0, _labelExit" << local+1 << endl;
			genStmt(node->child[4], node->child[4]->type, scope, labelN);
			cout << "_labelExit" << local+1 << ":"<< endl;
			break;
		}
		case 5:
		{
			int local = labelNumber;
			labelNumber = labelNumber + 2;
			genExp(node->child[2],node->child[2]->type, scope);
			cout << "beqz $t0, _labelElse" << local+1 << endl;
			genStmt(node->child[4], node->child[4]->type, scope, labelN);
			cout << "j _labelExit" << local+2 << endl;
			cout << "_labelElse" << local+1 << ":" << endl;
			genStmt(node->child[6], node->child[6]->type, scope, labelN);
			cout << "_labelExit" << local+2 << ":" << endl;
			break;
		}
		case 6:
		{
			int local = labelNumber;
			labelNumber = labelNumber + 3;
			genExp(node->child[2], node->child[2]->type, scope);
			cout << "_labelFor" << local+1 <<":"<< endl;
			genExp(node->child[4], node->child[4]->type, scope);
			cout << "beqz $t0, _labelExit" << local+3 << endl;
			genStmt(node->child[8], node->child[8]->type, scope, labelNumber);
			cout << "_labelUpdate" << local+2 << ":" << endl;
			genExp(node->child[6], node->child[6]->type, scope);
			cout << "j _labelFor" << local+1 << endl;
			cout << "_labelExit" << local+3 << ":" << endl;
			break;
		}
		case 7:
		{
			if(labelN != 0)
			{
				cout << "j _labelUpdate" << labelN-1 << endl;
			}
			else
				cout << "j _labelUpdate" << labelNumber-1 << endl;
		}
		case 8:
		{
			if(labelN != 0)
				cout << "j _labelExit" << labelN << endl;
			else
				cout << "j _labelExit" << labelNumber << endl;
			break;
		}
		case 9:		//read
		{
			cout << "li $v0, 5" << endl;
			cout << "syscall" << endl;
			if(node->child[2]->type == 35)	//int int[]
			{

			//	genExp(node->child[2], node->child[2]->type, scope);
				node = node->child[2];
				if(node->child[1]->type == 2) //int
				{
					if((*FT[scope])[node->child[0]->data] != 0)
						cout << "sw $v0, " << 4 + (*FT[scope])["#"] - (*FT[scope])[node->child[0]->data] << "($s0)" << endl;
					else if ( (*FT["_G"])[node->child[0]->data] != 0)	
						cout << "sw $v0, " << (*FT["_G"])["#"] - (*FT["_G"])[node->child[0]->data] << "($s2)" << endl;
				}
				else	//int[]
				{
					genExp(node->child[1]->child[1], node->child[1]->child[1]->type, scope);
					cout << "mul $t0, $t0, 4" << endl;
					if((*FT[scope])[node->child[0]->data] != 0 && (*ISA[scope])[node->child[0]->data]== 1)
					{
						cout << "add $t0, $t0, " << 4 + (*FT[scope])["#"] - (*FT[scope])[node->child[0]->data] << endl;
						cout << "add $t0, $t0, $s0" << endl;
						cout << "sw $v0, 0($t0)" << endl;
					}
					else if ((*FT["_G"])[node->child[0]->data] != 0 && (*ISA["_G"])[node->child[0]->data]== 1)	
					{
						cout << "add $t0, $t0, " << (*FT["_G"])["#"] - (*FT["_G"])[node->child[0]->data] << endl;
						cout << "add $t0, $t0, $s2" << endl;
						cout << "sw $v0, 0($t0)" << endl;
					}
					else
					{
						freopen(outputFile.c_str(), "w", stdout);
						cout << "Error.";
						fprintf(stderr, "\nCompile fail!\n");
						fprintf(stderr, "error occurs, %s is not defined\n",  (node->child[0]->data).c_str() );
						exit(0);
					}
				}
			}
			else if(node->child[2]->type == 36)
			{
				node = node->child[2];
				string stname = STAC[node->child[0]->child[0]->data];
				
				if(stname != "")
				{
				if((*FT[scope])[node->child[0]->child[0]->data] != 0)
					cout << "sw $v0, " << 4 + (*FT[scope])["#"] - (*FT[scope])[node->child[0]->child[0]->data]
							+(*ST[stname])["#"] - (*ST[stname])[node->child[2]->data]
						<< "($s0)" << endl;
				else if ((*FT["_G"])[node->child[0]->child[0]->data] != 0)	
					cout << "sw $v0, " << (*FT["_G"])["#"] - (*FT["_G"])[node->child[0]->child[0]->data] 
					+(*ST[stname])["#"] - (*ST[stname])[node->child[2]->data]
					<< "($s2)" << endl;
				}
				else
				{
					freopen(outputFile.c_str(), "w", stdout);
					cout << "Error.";
					fprintf(stderr, "\nCompile fail!\n");
					fprintf(stderr, "error occurs, %s is not defined\n",  (node->child[0]->child[0]->data).c_str() );
					exit(0);

				}

			}
			else
			{
				freopen(outputFile.c_str(), "w", stdout);
				cout << "Error.";
				fprintf(stderr, "\nCompile fail!\n");
				fprintf(stderr, "error occurs,can't assign a value to a left value.\n" );
				exit(0);
			}
			break;
		}
		case 10:
		{
			genExp(node->child[2], node->child[2]->type, scope);
			cout << "li $v0, 1" << endl;
			cout << "move $a0, $t0" << endl;
			cout << "syscall" << endl;
			break;
		}
	}
}

void genDefs(treeNode* node, int type, string scope)
{	
	//printf("has entered genDefs() ,type =%d \n", type);
	
	switch(type)
	{
		case 1:
	//	printf("ready to enter genDef()\n");
		genDef(node->child[0], node->child[0]->type, scope);
		genDefs(node->child[1], node->child[1]->type, scope);
		break;
		case 2:
		/*
		if(FT[scope] == 0)
		{
			FT[scope] = new map<string, int>();
		}*/
		break;
	}
}

void genDef(treeNode* node, int type, string scope)
{	
	//ÔÝÊ±²»¿¼ÂÇÔÚº¯ÊýÀï¶¨ÒåstructµÄÇé¿ö,TAËµ¼ò»¯Æð¼û²»ÓÃ¿¼ÂÇÁË
	genDecs(node->child[1],node->child[1]->type, scope);
}

void genDecs(treeNode* node, int type, string scope)
{
	//printf("has entered genDecs()\n");

	switch(type)
	{
		case 1:
		genDec(node->child[0],node->child[0]->type, scope);
		genDecs(node->child[2],node->child[2]->type, scope);
		break;
		case 2:
		genDec(node->child[0],node->child[0]->type, scope);
		break;
	}
}



void genDec(treeNode* node, int type, string scope)
{
	switch(type)
	{
		case 1://´ËÇé¿öÃ»ÓÐ¸³Öµ£¬²»¿¼ÂÇ
		break;
		case 2:
		{	
			if(scope == "_G")
				cout << "_G_" << globalNumber << ":" << endl;
			//¶Ô±äÁ¿¸³Öµ
			if ( node->child[0]->type==1)
			{
				genInit(node->child[2],node->child[2]->type,scope);
				if((*FT[scope])[node->child[0]->child[0]->data] != 0 && scope != "_G")
					cout << "sw $t0, " << 4 + (*FT[scope])["#"] - (*FT[scope])[node->child[0]->child[0]->data] << "($s0)" << endl;
				else if((*FT["_G"])[node->child[0]->child[0]->data] != 0 )	
					cout << "sw $t0, " << (*FT["_G"])["#"] - (*FT["_G"])[node->child[0]->child[0]->data] << "($s2)" << endl;
				else
				{
					freopen(outputFile.c_str(), "w", stdout);
					cout << "Error.";
					fprintf(stderr, "\nCompile fail!\n");
					fprintf(stderr, "error occurs, %s is not defined\n",  (node->child[0]->child[0]->data).c_str() );
					exit(0);
				}
			}
			//¶ÔÊý×é¸³Öµ
			else if(node->child[0]->type==2)
			{
				if(node->child[2]->childnum != 3)
				{
					freopen(outputFile.c_str(), "w", stdout);
					cout << "Error.";
					fprintf(stderr, "\nCompile fail!\n");
					fprintf(stderr, "error occurs, %s wrong array initialization\n",(node->child[0]->child[0]->child[0]->data).c_str() );
					exit(0);
				}
				//cout << "sw $t0, " << 4 + (*FT[scope])["#"] - (*FT[scope])[node->child[0]->data] << "($s0)" << endl;
				string num = node->child[0]->child[2]->data;
				int n = atoi(num.c_str());
				int size = 1;
				treeNode *tmp = node->child[2]->child[1];
				while(tmp->childnum == 3)
				{
					size++;
					tmp = tmp->child[2];
				}
				if(size > n)
				{
					freopen(outputFile.c_str(), "w", stdout);
					cout << "Error.";
					fprintf(stderr, "\nCompile fail!\n");
					fprintf(stderr, "error occurs, %s argument is too large\n",( node->child[0]->child[0]->child[0]->data ).c_str() );
					exit(0);
				}
				tmp = node->child[2]->child[1];
				for(int i=0; i<size; i++)
				{
					genExp(tmp->child[0],tmp->child[0]->type, scope);
					//if(i == 0)
					//	cout << tmp->child[0]->child[0]->data << endl;
					if(tmp->childnum == 3)
						tmp = tmp->child[2];
					if(scope != "_G")
						cout << "sw $t0, " << 4 + (*FT[scope])["#"]-(*FT[scope])[node->child[0]->child[0]->child[0]->data]+i*4 << "($s0)" << endl;
					else
						cout << "sw $t0, " << (*FT[scope])["#"]-(*FT[scope])[node->child[0]->child[0]->child[0]->data]+i*4 << "($s2)" << endl;
				}
			}
			if(scope == "_G")
				cout << "j _G_" << ++globalNumber << endl;
			break;
		}
	}
}

void genInit(treeNode* node, int type, string scope)
{
	switch(type)
	{
		case 1:
			genExp(node->child[0], node->child[0]->type, scope);
			break;
		case 2:// struct
			break;
	}
}

void genExp(treeNode* node, int type, string scope, int pre)
{
	switch(type)
	{
		case 1:
		genExp(node->child[1], node->child[1]->type, scope);
		cout << "seq $t0, $t0, 0" << endl;
		break;
		
		case 2:
		genExp(node->child[1], node->child[1]->type, scope, 1);
		//cout << "add $t0, $t0, 1" << endl;
		break;
		
		case 3:
		genExp(node->child[1], node->child[1]->type, scope, 2);
	//	cout << "add $t0, $t0, -1" << endl;
		break;
		
		case 4:
		genExp(node->child[1], node->child[1]->type, scope);
		cout << "nor $t1, $t0, $t0" << endl;
		cout << "move $t0, $t1" << endl;
		break;
		
		case 5:
		genExp(node->child[0], node->child[0]->type, scope);
		cout << "add $sp, $sp, -4" << endl;
		cout << "sw $t0, 0($sp)" << endl;
		genExp(node->child[2], node->child[2]->type, scope);
		cout << "lw $t1, 0($sp)" << endl;
		cout << "add $sp, $sp, 4" << endl;
		cout << "mul $t0, $t1, $t0" << endl;
		break;
		
		case 6:
		genExp(node->child[0], node->child[0]->type, scope);
		cout << "add $sp, $sp, -4" << endl;
		cout << "sw $t0, 0($sp)" << endl;
		genExp(node->child[2], node->child[2]->type, scope);
		cout << "lw $t1, 0($sp)" << endl;
		cout << "add $sp, $sp, 4" << endl;
		cout << "div $t0, $t1, $t0" << endl;
		break;
		
		case 7:
		genExp(node->child[0], node->child[0]->type, scope);
		cout << "add $sp, $sp, -4" << endl;
		cout << "sw $t0, 0($sp)" << endl;
		genExp(node->child[2], node->child[2]->type, scope);
		cout << "lw $t1, 0($sp)" << endl;
		cout << "add $sp, $sp, 4" << endl;
		cout << "div $t2, $t1, $t0" << endl;
		cout << "mul $t2, $t0, $t2" << endl;
		cout << "sub $t0, $t1, $t2" << endl;
		break;
		
		case 8:
		genExp(node->child[0], node->child[0]->type, scope);
		cout << "add $sp, $sp, -4" << endl;
		cout << "sw $t0, 0($sp)" << endl;
		genExp(node->child[2], node->child[2]->type, scope);
		cout << "lw $t1, 0($sp)" << endl;
		cout << "add $sp, $sp, 4" << endl;
		cout << "add $t0, $t1, $t0" << endl;
		break;
		
		case 9:
		genExp(node->child[0], node->child[0]->type, scope);
		cout << "add $sp, $sp, -4" << endl;
		cout << "sw $t0, 0($sp)" << endl;
		genExp(node->child[2], node->child[2]->type, scope);
		cout << "lw $t1, 0($sp)" << endl;
		cout << "add $sp, $sp, 4" << endl;
		cout << "sub $t0, $t1, $t0" << endl;
		break;
		
		case 10:
		genExp(node->child[0], node->child[0]->type, scope);
		cout << "add $sp, $sp, -4" << endl;
		cout << "sw $t0, 0($sp)" << endl;
		genExp(node->child[2], node->child[2]->type, scope);
		cout << "lw $t1, 0($sp)" << endl;
		cout << "add $sp, $sp, 4" << endl;
		cout << "sll $t0, $t1, $t0" << endl;
		break;
		
		case 11:
		genExp(node->child[0], node->child[0]->type, scope);
		cout << "add $sp, $sp, -4" << endl;
		cout << "sw $t0, 0($sp)" << endl;
		genExp(node->child[2], node->child[2]->type, scope);
		cout << "lw $t1, 0($sp)" << endl;
		cout << "add $sp, $sp, 4" << endl;
		cout << "srl $t0, $t1, $t0" << endl;
		break;
		
		case 12:
		genExp(node->child[0], node->child[0]->type, scope);
		cout << "add $sp, $sp, -4" << endl;
		cout << "sw $t0, 0($sp)" << endl;
		genExp(node->child[2], node->child[2]->type, scope);
		cout << "lw $t1, 0($sp)" << endl;
		cout << "add $sp, $sp, 4" << endl;
		cout << "slt $t0, $t0, $t1" << endl;
		break;
		
		case 13:
		genExp(node->child[0], node->child[0]->type, scope);
		cout << "add $sp, $sp, -4" << endl;
		cout << "sw $t0, 0($sp)" << endl;
		genExp(node->child[2], node->child[2]->type, scope);
		cout << "lw $t1, 0($sp)" << endl;
		cout << "add $sp, $sp, 4" << endl;
		cout << "seq $t2, $t1, $t0" << endl;
		cout << "slt $t3, $t0, $t1" << endl;
		cout << "or $t0, $t2, $t3" << endl;
		break;
		
		case 14:
		genExp(node->child[0], node->child[0]->type, scope);
		cout << "add $sp, $sp, -4" << endl;
		cout << "sw $t0, 0($sp)" << endl;
		genExp(node->child[2], node->child[2]->type, scope);
		cout << "lw $t1, 0($sp)" << endl;
		cout << "add $sp, $sp, 4" << endl;
		cout << "slt $t0, $t1, $t0" << endl;
		break;
		
		case 15:
		genExp(node->child[0], node->child[0]->type, scope);
		cout << "add $sp, $sp, -4" << endl;
		cout << "sw $t0, 0($sp)" << endl;
		genExp(node->child[2], node->child[2]->type, scope);
		cout << "lw $t1, 0($sp)" << endl;
		cout << "add $sp, $sp, 4" << endl;
		cout << "slt $t2, $t1, $t0" << endl;
		cout << "seq $t3, $t1, $t0" << endl;
		cout << "or $t0, $t2, $t3" << endl;
		break;
		
		case 16:
		genExp(node->child[0], node->child[0]->type, scope);
		cout << "add $sp, $sp, -4" << endl;
		cout << "sw $t0, 0($sp)" << endl;
		genExp(node->child[2], node->child[2]->type, scope);
		cout << "lw $t1, 0($sp)" << endl;
		cout << "add $sp, $sp, 4" << endl;
		cout << "seq $t0, $t1, $t0" << endl;
		break;
		
		case 17:
		genExp(node->child[0], node->child[0]->type, scope);
		cout << "add $sp, $sp, -4" << endl;
		cout << "sw $t0, 0($sp)" << endl;
		genExp(node->child[2], node->child[2]->type, scope);
		cout << "lw $t1, 0($sp)" << endl;
		cout << "add $sp, $sp, 4" << endl;
		cout << "seq $t0, $t1, $t0" << endl;
		cout << "seq $t0, $t0 , 0" << endl;
		break;
		
		case 18:
		genExp(node->child[0], node->child[0]->type, scope);
		cout << "add $sp, $sp, -4" << endl;
		cout << "sw $t0, 0($sp)" << endl;
		genExp(node->child[2], node->child[2]->type, scope);
		cout << "lw $t1, 0($sp)" << endl;
		cout << "add $sp, $sp, 4" << endl;
		cout << "and $t0, $t1, $t0" << endl;
		break;
		
		case 19:
		genExp(node->child[0], node->child[0]->type, scope);
		cout << "add $sp, $sp, -4" << endl;
		cout << "sw $t0, 0($sp)" << endl;
		genExp(node->child[2], node->child[2]->type, scope);
		cout << "lw $t1, 0($sp)" << endl;
		cout << "add $sp, $sp, 4" << endl;
		cout << "xor $t0, $t1, $t0" << endl;
		break;
		
		case 20:
		genExp(node->child[0], node->child[0]->type, scope);
		cout << "add $sp, $sp, -4" << endl;
		cout << "sw $t0, 0($sp)" << endl;
		genExp(node->child[2], node->child[2]->type, scope);
		cout << "lw $t1, 0($sp)" << endl;
		cout << "add $sp, $sp, 4" << endl;
		cout << "or $t0, $t1, $t0" << endl;
		break;
		
		case 21:
		genExp(node->child[0], node->child[0]->type, scope);
		cout << "add $sp, $sp, -4" << endl;
		cout << "sw $t0, 0($sp)" << endl;
		genExp(node->child[2], node->child[2]->type, scope);
		cout << "lw $t1, 0($sp)" << endl;
		cout << "add $sp, $sp, 4" << endl;
		cout << "seq $t2, $t1, 0" << endl;
		cout << "seq $t3, $t0, 0" << endl;
		cout << "or $t2, $t2, $t3" << endl;
		cout << "seq $t0, $t2, 0" << endl;
		break;
		
		case 22:
		genExp(node->child[0], node->child[0]->type, scope);
		cout << "add $sp, $sp, -4" << endl;
		cout << "sw $t0, 0($sp)" << endl;
		genExp(node->child[2], node->child[2]->type, scope);
		cout << "lw $t1, 0($sp)" << endl;
		cout << "add $sp, $sp, 4" << endl;
		cout << "seq $t2, $t1, 0" << endl;
		cout << "seq $t3, $t0, 0" << endl;
		cout << "seq $t2, $t2, 0" << endl;
		cout << "seq $t3, $t3, 0" << endl;
		cout << "or $t0, $t2, $t3" << endl;
		break;
		
		case 23:	// exp = exp
		{
			if(node->child[0]->type == 35)	//int int[]
			{
				genExp(node->child[2], node->child[2]->type, scope);
				if(node->child[0]->child[1]->type == 2) //int
				{
					if((*FT[scope])[node->child[0]->child[0]->data] != 0)
						cout << "sw $t0, " << 4 + (*FT[scope])["#"] - (*FT[scope])[node->child[0]->child[0]->data] << "($s0)" << endl;
					else if ( (*FT["_G"])[node->child[0]->child[0]->data] != 0)	
						cout << "sw $t0, " << (*FT["_G"])["#"] - (*FT["_G"])[node->child[0]->child[0]->data] << "($s2)" << endl;
					else
					{
						freopen(outputFile.c_str(), "w", stdout);
						cout << "Error.";
						fprintf(stderr, "\nCompile fail!\n");
						fprintf(stderr, "error occurs, %s is undefined\n" ,
								(node->child[0]->child[0]->data).c_str() );
						exit(0);

					}
				}
				else	//int[]
				{
				//	fprintf(stderr, "!!!%d,%d!!", (*ISA["_G"])[node->child[0]->child[0]->data], (*FT["_G"])[node->child[0]->child[0]->data]);
				//	cout << "\n\n\n!!!!ready to assign int[]!!!\n\n\n";
					cout << "add $sp, $sp, -4" << endl;
					cout << "sw $t0, 0($sp)" << endl;
					genExp(node->child[0]->child[1]->child[1], node->child[0]->child[1]->child[1]->type, scope);
					cout << "lw $t1, 0($sp)" << endl;
					cout << "add $sp, $sp, 4" << endl;
					cout << "mul $t0, $t0, 4" << endl;
					if((*FT[scope])[node->child[0]->child[0]->data] != 0 && (*ISA[scope])[node->child[0]->child[0]->data] == 1) 
					{
						cout << "add $t0, $t0, " << 4 + (*FT[scope])["#"] - (*FT[scope])[node->child[0]->child[0]->data] << endl;
						cout << "add $t0, $t0, $s0" << endl;
						cout << "sw $t1, 0($t0)" << endl;
					}
					else if ((*FT["_G"])[node->child[0]->child[0]->data] != 0 && (*ISA["_G"])[node->child[0]->child[0]->data] == 1)	
					{
						cout << "add $t0, $t0, " << (*FT["_G"])["#"] - (*FT["_G"])[node->child[0]->child[0]->data] << endl;
						cout << "add $t0, $t0, $s2" << endl;
						cout << "sw $t1, 0($t0)" << endl;
					}
					else
					{
						freopen(outputFile.c_str(), "w", stdout);
						cout << "Error.";
						fprintf(stderr, "\nCompile fail!\n");
						fprintf(stderr, "error occurs, array %s is undefined\n" ,(node->child[0]->child[0]->data).c_str() );
						exit(0);
					}
				}
			}
			else if(node->child[0]->type == 36)	//xx.xx
			{
				genExp(node->child[2], node->child[2]->type, scope);
				string stname = STAC[node->child[0]->child[0]->child[0]->data];
				
				if(stname != "")
				{
				if((*FT[scope])[node->child[0]->child[0]->child[0]->data] != 0)
					cout << "sw $t0, " << 4 + (*FT[scope])["#"] - (*FT[scope])[node->child[0]->child[0]->child[0]->data]
							+(*ST[stname])["#"] - (*ST[stname])[node->child[0]->child[2]->data]
						<< "($s0)" << endl;
				else if ((*FT["_G"])[node->child[0]->child[0]->child[0]->data] != 0)	
					cout << "sw $t0, " << (*FT["_G"])["#"] - (*FT["_G"])[node->child[0]->child[0]->child[0]->data] 
					+(*ST[stname])["#"] - (*ST[stname])[node->child[0]->child[2]->data]
					<< "($s2)" << endl;
				}
				else
				{
					freopen(outputFile.c_str(), "w", stdout);
					cout << "Error.";
					fprintf(stderr, "\nCompile fail!\n");
					fprintf(stderr, "struct %s is not defined\n",(node->child[0]->child[0]->child[0]->data).c_str() );
					exit(0);
				}
			}
			else
			{
				freopen(outputFile.c_str(), "w", stdout);
				cout << "Error.";
				fprintf(stderr, "\nCompile fail!\n");
				fprintf(stderr, "error occurs, can't assign a value to a left value.\n");
				exit(0);
			}
			break;
		}
		
		case 24:	//+=
		{
			genExp(node->child[0], node->child[0]->type, scope);
			cout << "add $sp, $sp, -4" << endl;
			cout << "sw $t0, 0($sp)" << endl;
			genExp(node->child[2], node->child[2]->type, scope);
			cout << "lw $t1, 0($sp)" << endl;
			cout << "add $sp, $sp, 4" << endl;
			cout << "add $t0, $t1, $t0" << endl;
			if(node->child[0]->type == 35)	//int int[]
			{
				if(node->child[0]->child[1]->type == 2) //int
				{
					if((*FT[scope])[node->child[0]->child[0]->data] != 0)
						cout << "sw $t0, " << 4 + (*FT[scope])["#"] - (*FT[scope])[node->child[0]->child[0]->data] << "($s0)" << endl;
					else if ((*FT["_G"])[node->child[0]->child[0]->data] != 0)	
						cout << "sw $t0, " << (*FT["_G"])["#"] - (*FT["_G"])[node->child[0]->child[0]->data] << "($s2)" << endl;	
					else
					{
						freopen(outputFile.c_str(), "w", stdout);
						cout << "Error.";
						fprintf(stderr, "\nCompile fail!\n");
						fprintf(stderr, "error occurs, %s is undefined\n" ,
								(node->child[0]->child[0]->data).c_str() );
						exit(0);
					}
				}
				else	//int[]
				{
					cout << "add $sp, $sp, -4" << endl;
					cout << "sw $t0, 0($sp)" << endl;
					genExp(node->child[0]->child[1]->child[1], node->child[0]->child[1]->child[1]->type, scope);
					cout << "lw $t1, 0($sp)" << endl;
					cout << "add $sp, $sp, 4" << endl;
					cout << "mul $t0, $t0, 4" << endl;
					if((*FT[scope])[node->child[0]->child[0]->data] != 0 && (*ISA[scope])[node->child[0]->child[0]->data] == 1)
					{
						cout << "add $t0, $t0, " << 4 + (*FT[scope])["#"] - (*FT[scope])[node->child[0]->child[0]->data] << endl;
						cout << "add $t0, $t0, $s0" << endl; cout << "sw $t1, 0($t0)" << endl;
					}
					else if ((*FT["_G"])[node->child[0]->child[0]->data] != 0 && (*ISA["_G"])[node->child[0]->child[0]->data] == 1)	
					{
						cout << "add $t0, $t0, " << (*FT["_G"])["#"] - (*FT["_G"])[node->child[0]->child[0]->data] << endl;
						cout << "add $t0, $t0, $s2" << endl; cout << "sw $t1, 0($t0)" << endl;
					}
					else
					{
						freopen(outputFile.c_str(), "w", stdout);
						cout << "Error.";
						fprintf(stderr, "\nCompile fail!\n");
						fprintf(stderr, "error occurs, %s is undefined\n",  (node->child[0]->child[0]->data).c_str() );
						exit(0);
					}
				}
			}
			else if(node->child[0]->type == 36)
			{
				string stname = STAC[node->child[0]->child[0]->child[0]->data];
				if(stname != "")
				{
				if((*FT[scope])[node->child[0]->child[0]->child[0]->data] != 0)
					cout << "sw $t0, " << 4 + (*FT[scope])["#"] - (*FT[scope])[node->child[0]->child[0]->child[0]->data]
							+(*ST[stname])["#"] - (*ST[stname])[node->child[0]->child[2]->data]
						<< "($s0)" << endl;
				else if ((*FT["_G"])[node->child[0]->child[0]->child[0]->data] != 0)	
					cout << "sw $t0, " << (*FT["_G"])["#"] - (*FT["_G"])[node->child[0]->child[0]->child[0]->data] 
					+(*ST[stname])["#"] - (*ST[stname])[node->child[0]->child[2]->data]
					<< "($s2)" << endl;
				}
				else
				{
					freopen(outputFile.c_str(), "w", stdout);
					cout << "Error.";
					fprintf(stderr, "\nCompile fail!\n");
					fprintf(stderr, "struct %s is not defined\n",(node->child[0]->child[0]->child[0]->data).c_str() );
					exit(0);
				}
			}
			else
			{
				freopen(outputFile.c_str(), "w", stdout);
				cout << "Error.";
				fprintf(stderr, "\nCompile fail!\n");
				fprintf(stderr, "error occurs, can't assign a value to a left value.\n");
				exit(0);
			}
			break;
		}
		case 25:
		{
			genExp(node->child[0], node->child[0]->type, scope);
			cout << "add $sp, $sp, -4" << endl;
			cout << "sw $t0, 0($sp)" << endl;
			genExp(node->child[2], node->child[2]->type, scope);
			cout << "lw $t1, 0($sp)" << endl;
			cout << "add $sp, $sp, 4" << endl;
			cout << "sub $t0, $t1, $t0" << endl;
			if(node->child[0]->type == 35)	//int int[]
			{
				if(node->child[0]->child[1]->type == 2) //int
				{
					if((*FT[scope])[node->child[0]->child[0]->data] != 0)
						cout << "sw $t0, " << 4 + (*FT[scope])["#"] - (*FT[scope])[node->child[0]->child[0]->data] << "($s0)" << endl;
					else if ((*FT["_G"])[node->child[0]->child[0]->data] != 0)	
						cout << "sw $t0, " << (*FT["_G"])["#"] - (*FT["_G"])[node->child[0]->child[0]->data] << "($s2)" << endl;
					else
					{
						freopen(outputFile.c_str(), "w", stdout);
						cout << "Error.";
						fprintf(stderr, "\nCompile fail!\n");
						fprintf(stderr, "error occurs, %s is undefined\n" ,
								(node->child[0]->child[0]->data).c_str() );
						exit(0);
					}
				}
				else	//int[]
				{
					cout << "add $sp, $sp, -4" << endl;
					cout << "sw $t0, 0($sp)" << endl;
					genExp(node->child[0]->child[1]->child[1], node->child[0]->child[1]->child[1]->type, scope);
					cout << "lw $t1, 0($sp)" << endl;
					cout << "add $sp, $sp, 4" << endl;
					cout << "mul $t0, $t0, 4" << endl;
					if((*FT[scope])[node->child[0]->child[0]->data] != 0  && (*ISA[scope])[node->child[0]->child[0]->data] == 1)
					{
						cout << "add $t0, $t0, " << 4 + (*FT[scope])["#"] - (*FT[scope])[node->child[0]->child[0]->data] << endl;
						cout << "add $t0, $t0, $s0" << endl; cout << "sw $t1, 0($t0)" << endl;
					}
					else if ((*FT["_G"])[node->child[0]->child[0]->data] != 0 && (*ISA["_G"])[node->child[0]->child[0]->data] == 1)	
					{
						cout << "add $t0, $t0, " << (*FT["_G"])["#"] - (*FT["_G"])[node->child[0]->child[0]->data] << endl;
						cout << "add $t0, $t0, $s2" << endl; cout << "sw $t1, 0($t0)" << endl;
					}
					else
					{
						freopen(outputFile.c_str(), "w", stdout);
						cout << "Error.";
						fprintf(stderr, "\nCompile fail!\n");
						fprintf(stderr, "error occurs, %s is undefined\n", (node->child[0]->child[0]->data).c_str() );
						exit(0);
					}
				}
			}
			else if(node->child[0]->type == 36)
			{
				string stname = STAC[node->child[0]->child[0]->child[0]->data];
				
				if(stname != "")
				{
				if((*FT[scope])[node->child[0]->child[0]->child[0]->data] != 0)
					cout << "sw $t0, " << 4 + (*FT[scope])["#"] - (*FT[scope])[node->child[0]->child[0]->child[0]->data]
							+(*ST[stname])["#"] - (*ST[stname])[node->child[0]->child[2]->data]
						<< "($s0)" << endl;
				else if ((*FT["_G"])[node->child[0]->child[0]->child[0]->data] != 0)	
					cout << "sw $t0, " << (*FT["_G"])["#"] - (*FT["_G"])[node->child[0]->child[0]->child[0]->data] 
					+(*ST[stname])["#"] - (*ST[stname])[node->child[0]->child[2]->data]
					<< "($s2)" << endl;
				}
				else
				{
					freopen(outputFile.c_str(), "w", stdout);
					cout << "Error.";
					fprintf(stderr, "\nCompile fail!\n");
					fprintf(stderr, "struct %s is not defined\n",(node->child[0]->child[0]->child[0]->data).c_str() );
					exit(0);
				}
			}
			else
			{
				freopen(outputFile.c_str(), "w", stdout);
				cout << "Error.";
				fprintf(stderr, "\nCompile fail!\n");
				fprintf(stderr, "error occurs, can't assign a value to a left value.\n");
				exit(0);
			}
			break;
		}	
		
		case 26:
		{
			genExp(node->child[0], node->child[0]->type, scope);
			cout << "add $sp, $sp, -4" << endl;
			cout << "sw $t0, 0($sp)" << endl;
			genExp(node->child[2], node->child[2]->type, scope);
			cout << "lw $t1, 0($sp)" << endl;
			cout << "add $sp, $sp, 4" << endl;
			cout << "mul $t0, $t1, $t0" << endl;
			if(node->child[0]->type == 35)	//int int[]
			{
				if(node->child[0]->child[1]->type == 2) //int
				{
					if((*FT[scope])[node->child[0]->child[0]->data] != 0)
						cout << "sw $t0, " << 4 + (*FT[scope])["#"] - (*FT[scope])[node->child[0]->child[0]->data] << "($s0)" << endl;
					else if ((*FT["_G"])[node->child[0]->child[0]->data] != 0)	
						cout << "sw $t0, " << (*FT["_G"])["#"] - (*FT["_G"])[node->child[0]->child[0]->data] << "($s2)" << endl;
					else
					{
						freopen(outputFile.c_str(), "w", stdout);
						cout << "Error.";
						fprintf(stderr, "\nCompile fail!\n");
						fprintf(stderr, "error occurs, %s is undefined\n" ,
								(node->child[0]->child[0]->data).c_str() );
						exit(0);
					}
				}
				else	//int[]
				{
					cout << "add $sp, $sp, -4" << endl;
					cout << "sw $t0, 0($sp)" << endl;
					genExp(node->child[0]->child[1]->child[1], node->child[0]->child[1]->child[1]->type, scope);
					cout << "lw $t1, 0($sp)" << endl;
					cout << "add $sp, $sp, 4" << endl;
					cout << "mul $t0, $t0, 4" << endl;
					if((*FT[scope])[node->child[0]->child[0]->data] != 0 && (*ISA[scope])[node->child[0]->child[0]->data] == 1)
					{
						cout << "add $t0, $t0, " << 4 + (*FT[scope])["#"] - (*FT[scope])[node->child[0]->child[0]->data] << endl;
						cout << "add $t0, $t0, $s0" << endl; cout << "sw $t1, 0($t0)" << endl;
					}
					else if ((*FT["_G"])[node->child[0]->child[0]->data] != 0  && (*ISA["_G"])[node->child[0]->child[0]->data] == 1)	
					{
						cout << "add $t0, $t0, " << (*FT["_G"])["#"] - (*FT["_G"])[node->child[0]->child[0]->data] << endl;
						cout << "add $t0, $t0, $s2" << endl; cout << "sw $t1, 0($t0)" << endl;
					}
					else
					{
						freopen(outputFile.c_str(), "w", stdout);
						cout << "Error.";
						fprintf(stderr, "\nCompile fail!\n");
						fprintf(stderr, "error occurs, %s is undefined\n", (node->child[0]->child[0]->data).c_str() );
						exit(0);
					}
				}
			}
			else if(node->child[0]->type == 36)
			{
				string stname = STAC[node->child[0]->child[0]->child[0]->data];
				if(stname != "")
				{
				if((*FT[scope])[node->child[0]->child[0]->child[0]->data] != 0)
					cout << "sw $t0, " << 4 + (*FT[scope])["#"] - (*FT[scope])[node->child[0]->child[0]->child[0]->data]
							+(*ST[stname])["#"] - (*ST[stname])[node->child[0]->child[2]->data]
						<< "($s0)" << endl;
				else if ((*FT["_G"])[node->child[0]->child[0]->child[0]->data] != 0)	
					cout << "sw $t0, " << (*FT["_G"])["#"] - (*FT["_G"])[node->child[0]->child[0]->child[0]->data] 
					+(*ST[stname])["#"] - (*ST[stname])[node->child[0]->child[2]->data]
					<< "($s2)" << endl;
				}
				else
				{
					freopen(outputFile.c_str(), "w", stdout);
					cout << "Error.";
					fprintf(stderr, "\nCompile fail!\n");
					fprintf(stderr, "struct %s is not defined\n",(node->child[0]->child[0]->child[0]->data).c_str() );
					exit(0);
				}

			}
			else
			{
				freopen(outputFile.c_str(), "w", stdout);
				cout << "Error.";
				fprintf(stderr, "\nCompile fail!\n");
				fprintf(stderr, "error occurs, can't assign a value to a left value.\n");
				exit(0);
			}
			break;
		}
		
		case 27:
		{
			genExp(node->child[0], node->child[0]->type, scope);
			cout << "add $sp, $sp, -4" << endl;
			cout << "sw $t0, 0($sp)" << endl;
			genExp(node->child[2], node->child[2]->type, scope);
			cout << "lw $t1, 0($sp)" << endl;
			cout << "add $sp, $sp, 4" << endl;
			cout << "div $t0, $t1, $t0" << endl;
			if(node->child[0]->type == 35)	//int int[]
			{
				if(node->child[0]->child[1]->type == 2) //int
				{
					if((*FT[scope])[node->child[0]->child[0]->data] != 0)
						cout << "sw $t0, " << 4 + (*FT[scope])["#"] - (*FT[scope])[node->child[0]->child[0]->data] << "($s0)" << endl;
					else if ((*FT["_G"])[node->child[0]->child[0]->data] != 0)	
						cout << "sw $t0, " << (*FT["_G"])["#"] - (*FT["_G"])[node->child[0]->child[0]->data] << "($s2)" << endl;
					else
					{
						freopen(outputFile.c_str(), "w", stdout);
						cout << "Error.";
						fprintf(stderr, "\nCompile fail!\n");
						fprintf(stderr, "error occurs, %s is undefined\n" ,
								(node->child[0]->child[0]->data).c_str() );
						exit(0);
					}
				}
				else	//int[]
				{
					cout << "add $sp, $sp, -4" << endl;
					cout << "sw $t0, 0($sp)" << endl;
					genExp(node->child[0]->child[1]->child[1], node->child[0]->child[1]->child[1]->type, scope);
					cout << "lw $t1, 0($sp)" << endl;
					cout << "add $sp, $sp, 4" << endl;
					cout << "mul $t0, $t0, 4" << endl;
					if((*FT[scope])[node->child[0]->child[0]->data] != 0  && (*ISA[scope])[node->child[0]->child[0]->data] == 1)
					{
						cout << "add $t0, $t0, " << 4 + (*FT[scope])["#"] - (*FT[scope])[node->child[0]->child[0]->data] << endl;
						cout << "add $t0, $t0, $s0" << endl; cout << "sw $t1, 0($t0)" << endl;
					}
					else if ((*FT["_G"])[node->child[0]->child[0]->data] != 0 && (*ISA["_G"])[node->child[0]->child[0]->data] == 1)	
					{
						cout << "add $t0, $t0, " << (*FT["_G"])["#"] - (*FT["_G"])[node->child[0]->child[0]->data] << endl;
						cout << "add $t0, $t0, $s2" << endl; cout << "sw $t1, 0($t0)" << endl;
					}
					else
					{
						freopen(outputFile.c_str(), "w", stdout);
						cout << "Error.";
						fprintf(stderr, "\nCompile fail!\n");
						fprintf(stderr, "error occurs, %s is undefined\n" , (node->child[0]->child[0]->data).c_str() );
						exit(0);
					}
				}
			}
			else if(node->child[0]->type == 36)
			{
				string stname = STAC[node->child[0]->child[0]->child[0]->data];
				
				if(stname != "")
				{
				if((*FT[scope])[node->child[0]->child[0]->child[0]->data] != 0)
					cout << "sw $t0, " << 4 + (*FT[scope])["#"] - (*FT[scope])[node->child[0]->child[0]->child[0]->data]
							+(*ST[stname])["#"] - (*ST[stname])[node->child[0]->child[2]->data]
						<< "($s0)" << endl;
				else if ((*FT["_G"])[node->child[0]->child[0]->child[0]->data] != 0)	
					cout << "sw $t0, " << (*FT["_G"])["#"] - (*FT["_G"])[node->child[0]->child[0]->child[0]->data] 
					+(*ST[stname])["#"] - (*ST[stname])[node->child[0]->child[2]->data]
					<< "($s2)" << endl;
				}
				else
				{
					freopen(outputFile.c_str(), "w", stdout);
					cout << "Error.";
					fprintf(stderr, "\nCompile fail!\n");
					fprintf(stderr, "struct %s is not defined\n",(node->child[0]->child[0]->child[0]->data).c_str() );
					exit(0);
				}
			}
			else
			{
				freopen(outputFile.c_str(), "w", stdout);
				cout << "Error.";
				fprintf(stderr, "\nCompile fail!\n");
				fprintf(stderr, "error occurs, can't assign a value to a left value.\n" );
				exit(0);
			}
			break;
		}
		case 28:
		{
			genExp(node->child[0], node->child[0]->type, scope);
			cout << "add $sp, $sp, -4" << endl;
			cout << "sw $t0, 0($sp)" << endl;
			genExp(node->child[2], node->child[2]->type, scope);
			cout << "lw $t1, 0($sp)" << endl;
			cout << "add $sp, $sp, 4" << endl;
			cout << "and $t0, $t1, $t0" << endl;
			if(node->child[0]->type == 35)	//int int[]
			{
				if(node->child[0]->child[1]->type == 2) //int
				{
					if((*FT[scope])[node->child[0]->child[0]->data] != 0)
						cout << "sw $t0, " << 4 + (*FT[scope])["#"] - (*FT[scope])[node->child[0]->child[0]->data] << "($s0)" << endl;
					else if ((*FT["_G"])[node->child[0]->child[0]->data] != 0)	
						cout << "sw $t0, " << (*FT["_G"])["#"] - (*FT["_G"])[node->child[0]->child[0]->data] << "($s2)" << endl;
					else
					{
						freopen(outputFile.c_str(), "w", stdout);
						cout << "Error.";
						fprintf(stderr, "\nCompile fail!\n");
						fprintf(stderr, "error occurs, %s is undefined\n" ,
								(node->child[0]->child[0]->data).c_str() );
						exit(0);
					}
				}
				else	//int[]
				{
					cout << "add $sp, $sp, -4" << endl;
					cout << "sw $t0, 0($sp)" << endl;
					genExp(node->child[0]->child[1]->child[1], node->child[0]->child[1]->child[1]->type, scope);
					cout << "lw $t1, 0($sp)" << endl;
					cout << "add $sp, $sp, 4" << endl;
					cout << "mul $t0, $t0, 4" << endl;
					if((*FT[scope])[node->child[0]->child[0]->data] != 0 && (*ISA[scope])[node->child[0]->child[0]->data] == 1)
					{
						cout << "add $t0, $t0, " << 4 + (*FT[scope])["#"] - (*FT[scope])[node->child[0]->child[0]->data] << endl;
						cout << "add $t0, $t0, $s0" << endl; cout << "sw $t1, 0($t0)" << endl;
					}
					else if ((*FT["_G"])[node->child[0]->child[0]->data] != 0  && (*ISA["_G"])[node->child[0]->child[0]->data] == 1)	
					{
						cout << "add $t0, $t0, " << (*FT["_G"])["#"] - (*FT["_G"])[node->child[0]->child[0]->data] << endl;
						cout << "add $t0, $t0, $s2" << endl; cout << "sw $t1, 0($t0)" << endl;
					}
					else
					{
						freopen(outputFile.c_str(), "w", stdout);
						cout << "Error.";
						fprintf(stderr, "\nCompile fail!\n");
						fprintf(stderr, "error occurs, %s is undefined\n" , (node->child[0]->child[0]->data).c_str() );
						exit(0);
					}
				}
			}
			else if(node->child[0]->type == 36)
			{
				string stname = STAC[node->child[0]->child[0]->child[0]->data];
				
				if(stname != "")
				{
				if((*FT[scope])[node->child[0]->child[0]->child[0]->data] != 0)
					cout << "sw $t0, " << 4 + (*FT[scope])["#"] - (*FT[scope])[node->child[0]->child[0]->child[0]->data]
							+(*ST[stname])["#"] - (*ST[stname])[node->child[0]->child[2]->data]
						<< "($s0)" << endl;
				else if ((*FT["_G"])[node->child[0]->child[0]->child[0]->data] != 0)	
					cout << "sw $t0, " << (*FT["_G"])["#"] - (*FT["_G"])[node->child[0]->child[0]->child[0]->data] 
					+(*ST[stname])["#"] - (*ST[stname])[node->child[0]->child[2]->data]
					<< "($s2)" << endl;
				}
				else
				{
					freopen(outputFile.c_str(), "w", stdout);
					cout << "Error.";
					fprintf(stderr, "\nCompile fail!\n");
					fprintf(stderr, "struct %s is not defined\n",(node->child[0]->child[0]->child[0]->data).c_str() );
					exit(0);
				}

			}
			else
			{
				freopen(outputFile.c_str(), "w", stdout);
				cout << "Error.";
				fprintf(stderr, "\nCompile fail!\n");
				fprintf(stderr, "error occurs, can't assign a value to a left value.\n" );
				exit(0);
			}
			break;
		}
		
		case 29:
		{
			genExp(node->child[0], node->child[0]->type, scope);
			cout << "add $sp, $sp, -4" << endl;
			cout << "sw $t0, 0($sp)" << endl;
			genExp(node->child[2], node->child[2]->type, scope);
			cout << "lw $t1, 0($sp)" << endl;
			cout << "add $sp, $sp, 4" << endl;
			cout << "xor $t0, $t1, $t0" << endl;
			if(node->child[0]->type == 35)	//int int[]
			{
				if(node->child[0]->child[1]->type == 2) //int
				{
					if((*FT[scope])[node->child[0]->child[0]->data] != 0)
						cout << "sw $t0, " << 4 + (*FT[scope])["#"] - (*FT[scope])[node->child[0]->child[0]->data] << "($s0)" << endl;
					else if ((*FT["_G"])[node->child[0]->child[0]->data] != 0)	
						cout << "sw $t0, " << (*FT["_G"])["#"] - (*FT["_G"])[node->child[0]->child[0]->data] << "($s2)" << endl;
					else
					{
						freopen(outputFile.c_str(), "w", stdout);
						cout << "Error.";
						fprintf(stderr, "\nCompile fail!\n");
						fprintf(stderr, "error occurs, %s is undefined\n" ,
								(node->child[0]->child[0]->data).c_str() );
						exit(0);
					}
				}
				else	//int[]
				{
					cout << "add $sp, $sp, -4" << endl;
					cout << "sw $t0, 0($sp)" << endl;
					genExp(node->child[0]->child[1]->child[1], node->child[0]->child[1]->child[1]->type, scope);
					cout << "lw $t1, 0($sp)" << endl;
					cout << "add $sp, $sp, 4" << endl;
					cout << "mul $t0, $t0, 4" << endl;
					if((*FT[scope])[node->child[0]->child[0]->data] != 0 && (*ISA[scope])[node->child[0]->child[0]->data] == 1)
					{
						cout << "add $t0, $t0, " << 4 + (*FT[scope])["#"] - (*FT[scope])[node->child[0]->child[0]->data] << endl;
						cout << "add $t0, $t0, $s0" << endl; cout << "sw $t1, 0($t0)" << endl;
					}
					else if ((*FT["_G"])[node->child[0]->child[0]->data] != 0 && (*ISA["_G"])[node->child[0]->child[0]->data] == 1)	
					{
						cout << "add $t0, $t0, " << (*FT["_G"])["#"] - (*FT["_G"])[node->child[0]->child[0]->data] << endl;
						cout << "add $t0, $t0, $s2" << endl; cout << "sw $t1, 0($t0)" << endl;
					}
					else
					{
						freopen(outputFile.c_str(), "w", stdout);
						cout << "Error.";
						fprintf(stderr, "\nCompile fail!\n");
						fprintf(stderr, "error occurs, %s is undefined\n" , (node->child[0]->child[0]->data).c_str() );
						exit(0);
					}
				}
			}
			else if(node->child[0]->type == 36)
			{
				string stname = STAC[node->child[0]->child[0]->child[0]->data];
				if(stname != "")
				{
				if((*FT[scope])[node->child[0]->child[0]->child[0]->data] != 0)
					cout << "sw $t0, " << 4 + (*FT[scope])["#"] - (*FT[scope])[node->child[0]->child[0]->child[0]->data]
							+(*ST[stname])["#"] - (*ST[stname])[node->child[0]->child[2]->data]
						<< "($s0)" << endl;
				else if ((*FT["_G"])[node->child[0]->child[0]->child[0]->data] != 0)	
					cout << "sw $t0, " << (*FT["_G"])["#"] - (*FT["_G"])[node->child[0]->child[0]->child[0]->data] 
					+(*ST[stname])["#"] - (*ST[stname])[node->child[0]->child[2]->data]
					<< "($s2)" << endl;
				}
				else
				{
					freopen(outputFile.c_str(), "w", stdout);
					cout << "Error.";
					fprintf(stderr, "\nCompile fail!\n");
					fprintf(stderr, "struct %s is not defined\n",(node->child[0]->child[0]->child[0]->data).c_str() );
					exit(0);
				}

			}
			else
			{
				freopen(outputFile.c_str(), "w", stdout);
				cout << "Error.";
				fprintf(stderr, "\nCompile fail!\n");
				fprintf(stderr, "error occurs, can't assign a value to a left value.\n" );
				exit(0);
			}
			break;
		}
		
		case 30:
		{
			genExp(node->child[0], node->child[0]->type, scope);
			cout << "add $sp, $sp, -4" << endl;
			cout << "sw $t0, 0($sp)" << endl;
			genExp(node->child[2], node->child[2]->type, scope);
			cout << "lw $t1, 0($sp)" << endl;
			cout << "add $sp, $sp, 4" << endl;
			cout << "or $t0, $t1, $t0" << endl;
			if(node->child[0]->type == 35)	//int int[]
			{
				if(node->child[0]->child[1]->type == 2) //int
				{
					if((*FT[scope])[node->child[0]->child[0]->data] != 0)
						cout << "sw $t0, " << 4 + (*FT[scope])["#"] - (*FT[scope])[node->child[0]->child[0]->data] << "($s0)" << endl;
					else if ((*FT["_G"])[node->child[0]->child[0]->data] != 0)	
						cout << "sw $t0, " << (*FT["_G"])["#"] - (*FT["_G"])[node->child[0]->child[0]->data] << "($s2)" << endl;
					else
					{
						freopen(outputFile.c_str(), "w", stdout);
						cout << "Error.";
						fprintf(stderr, "\nCompile fail!\n");
						fprintf(stderr, "error occurs, %s is undefined\n" ,
								(node->child[0]->child[0]->data).c_str() );
						exit(0);
					}
				}
				else	//int[]
				{
					cout << "add $sp, $sp, -4" << endl;
					cout << "sw $t0, 0($sp)" << endl;
					genExp(node->child[0]->child[1]->child[1], node->child[0]->child[1]->child[1]->type, scope);
					cout << "lw $t1, 0($sp)" << endl;
					cout << "add $sp, $sp, 4" << endl;
					cout << "mul $t0, $t0, 4" << endl;
					if((*FT[scope])[node->child[0]->child[0]->data] != 0 && (*ISA[scope])[node->child[0]->child[0]->data] == 1)
					{
						cout << "add $t0, $t0, " << 4 + (*FT[scope])["#"] - (*FT[scope])[node->child[0]->child[0]->data] << endl;
						cout << "add $t0, $t0, $s0" << endl; cout << "sw $t1, 0($t0)" << endl;
					}
					else if ((*FT["_G"])[node->child[0]->child[0]->data] != 0 && (*ISA["_G"])[node->child[0]->child[0]->data] == 1)	
					{
						cout << "add $t0, $t0, " << (*FT["_G"])["#"] - (*FT["_G"])[node->child[0]->child[0]->data] << endl;
						cout << "add $t0, $t0, $s2" << endl; cout << "sw $t1, 0($t0)" << endl;
					}
					else
					{
						freopen(outputFile.c_str(), "w", stdout);
						cout << "Error.";
						fprintf(stderr, "\nCompile fail!\n");
						fprintf(stderr, "error occurs, %s is undefined\n" , (node->child[0]->child[0]->data).c_str() );
						exit(0);
					}
				}
			}
			else if(node->child[0]->type == 36)
			{
				string stname = STAC[node->child[0]->child[0]->child[0]->data];
				if(stname!="")
				{
				if((*FT[scope])[node->child[0]->child[0]->child[0]->data] != 0)
					cout << "sw $t0, " << 4 + (*FT[scope])["#"] - (*FT[scope])[node->child[0]->child[0]->child[0]->data]
							+(*ST[stname])["#"] - (*ST[stname])[node->child[0]->child[2]->data]
						<< "($s0)" << endl;
				else if ((*FT["_G"])[node->child[0]->child[0]->child[0]->data] != 0)	
					cout << "sw $t0, " << (*FT["_G"])["#"] - (*FT["_G"])[node->child[0]->child[0]->child[0]->data] 
					+(*ST[stname])["#"] - (*ST[stname])[node->child[0]->child[2]->data]
					<< "($s2)" << endl;
				}
				else
				{
					freopen(outputFile.c_str(), "w", stdout);
					cout << "Error.";
					fprintf(stderr, "\nCompile fail!\n");
					fprintf(stderr, "struct %s is not defined\n",(node->child[0]->child[0]->child[0]->data).c_str() );
					exit(0);
				}
			}
			else
			{
				freopen(outputFile.c_str(), "w", stdout);
				cout << "Error.";
				fprintf(stderr, "\nCompile fail!\n");
				fprintf(stderr, "error occurs,can't assign a value to a left value.\n" );
				exit(0);
			}
			break;
		}
		
		case 31:
		{
			genExp(node->child[0], node->child[0]->type, scope);
			cout << "add $sp, $sp, -4" << endl;
			cout << "sw $t0, 0($sp)" << endl;
			genExp(node->child[2], node->child[2]->type, scope);
			cout << "lw $t1, 0($sp)" << endl;
			cout << "add $sp, $sp, 4" << endl;
			cout << "sll $t0, $t1, $t0" << endl;
			if(node->child[0]->type == 35)	//int int[]
			{
				if(node->child[0]->child[1]->type == 2) //int
				{
					if((*FT[scope])[node->child[0]->child[0]->data] != 0)
						cout << "sw $t0, " << 4 + (*FT[scope])["#"] - (*FT[scope])[node->child[0]->child[0]->data] << "($s0)" << endl;
					else if ((*FT["_G"])[node->child[0]->child[0]->data] != 0)	
						cout << "sw $t0, " << (*FT["_G"])["#"] - (*FT["_G"])[node->child[0]->child[0]->data] << "($s2)" << endl;
					else
					{
						freopen(outputFile.c_str(), "w", stdout);
						cout << "Error.";
						fprintf(stderr, "\nCompile fail!\n");
						fprintf(stderr, "error occurs, %s is undefined\n" ,
								(node->child[0]->child[0]->data).c_str() );
						exit(0);
					}
				}
				else	//int[]
				{
					cout << "add $sp, $sp, -4" << endl;
					cout << "sw $t0, 0($sp)" << endl;
					genExp(node->child[0]->child[1]->child[1], node->child[0]->child[1]->child[1]->type, scope);
					cout << "lw $t1, 0($sp)" << endl;
					cout << "add $sp, $sp, 4" << endl;
					cout << "mul $t0, $t0, 4" << endl;
					if((*FT[scope])[node->child[0]->child[0]->data] != 0  && (*ISA[scope])[node->child[0]->child[0]->data] == 1)
					{
						cout << "add $t0, $t0, " << 4 + (*FT[scope])["#"] - (*FT[scope])[node->child[0]->child[0]->data] << endl;
						cout << "add $t0, $t0, $s0" << endl; cout << "sw $t1, 0($t0)" << endl;
					}
					else if ((*FT["_G"])[node->child[0]->child[0]->data] != 0 && (*ISA["_G"])[node->child[0]->child[0]->data] == 1)	
					{
						cout << "add $t0, $t0, " << (*FT["_G"])["#"] - (*FT["_G"])[node->child[0]->child[0]->data] << endl;
						cout << "add $t0, $t0, $s2" << endl; cout << "sw $t1, 0($t0)" << endl;
					}
					else
					{
						freopen(outputFile.c_str(), "w", stdout);
						cout << "Error.";
						fprintf(stderr, "\nCompile fail!\n");
						fprintf(stderr, "error occurs, %s is undefined\n" , (node->child[0]->child[0]->data).c_str() );
						exit(0);
					}
				}
			}
			else if(node->child[0]->type == 36)
			{
				string stname = STAC[node->child[0]->child[0]->child[0]->data];
				if(stname != "")
				{
				if((*FT[scope])[node->child[0]->child[0]->child[0]->data] != 0)
					cout << "sw $t0, " << 4 + (*FT[scope])["#"] - (*FT[scope])[node->child[0]->child[0]->child[0]->data]
							+(*ST[stname])["#"] - (*ST[stname])[node->child[0]->child[2]->data]
						<< "($s0)" << endl;
				else if ((*FT["_G"])[node->child[0]->child[0]->child[0]->data] != 0)	
					cout << "sw $t0, " << (*FT["_G"])["#"] - (*FT["_G"])[node->child[0]->child[0]->child[0]->data] 
					+(*ST[stname])["#"] - (*ST[stname])[node->child[0]->child[2]->data]
					<< "($s2)" << endl;
				}
				else
				{
					freopen(outputFile.c_str(), "w", stdout);
					cout << "Error.";
					fprintf(stderr, "\nCompile fail!\n");
					fprintf(stderr, "struct %s is not defined\n",(node->child[0]->child[0]->child[0]->data).c_str() );
					exit(0);
				}
			}
			else
			{
				freopen(outputFile.c_str(), "w", stdout);
				cout << "Error.";
				fprintf(stderr, "\nCompile fail!\n");
				fprintf(stderr, "error occurs,can't assign a value to a left value.\n" );
				exit(0);
			}
			break;
		}
		
		case 32:
		{
			genExp(node->child[0], node->child[0]->type, scope);
			cout << "add $sp, $sp, -4" << endl;
			cout << "sw $t0, 0($sp)" << endl;
			genExp(node->child[2], node->child[2]->type, scope);
			cout << "lw $t1, 0($sp)" << endl;
			cout << "add $sp, $sp, 4" << endl;
			cout << "srl $t0, $t1, $t0" << endl;
			if(node->child[0]->type == 35)	//int int[]
			{
				if(node->child[0]->child[1]->type == 2) //int
				{
					if((*FT[scope])[node->child[0]->child[0]->data] != 0)
						cout << "sw $t0, " << 4 + (*FT[scope])["#"] - (*FT[scope])[node->child[0]->child[0]->data] << "($s0)" << endl;
					else if ((*FT["_G"])[node->child[0]->child[0]->data] != 0)	
						cout << "sw $t0, " << (*FT["_G"])["#"] - (*FT["_G"])[node->child[0]->child[0]->data] << "($s2)" << endl;
					else
					{
						freopen(outputFile.c_str(), "w", stdout);
						cout << "Error.";
						fprintf(stderr, "\nCompile fail!\n");
						fprintf(stderr, "error occurs, %s is undefined\n" ,
								(node->child[0]->child[0]->data).c_str() );
						exit(0);
					}
				}
				else	//int[]
				{
					cout << "add $sp, $sp, -4" << endl;
					cout << "sw $t0, 0($sp)" << endl;
					genExp(node->child[0]->child[1]->child[1], node->child[0]->child[1]->child[1]->type, scope);
					cout << "lw $t1, 0($sp)" << endl;
					cout << "add $sp, $sp, 4" << endl;
					cout << "mul $t0, $t0, 4" << endl;
					if((*FT[scope])[node->child[0]->child[0]->data] != 0 && (*ISA[scope])[node->child[0]->child[0]->data] == 1)
					{
						cout << "add $t0, $t0, " << 4 + (*FT[scope])["#"] - (*FT[scope])[node->child[0]->child[0]->data] << endl;
						cout << "add $t0, $t0, $s0" << endl; 
						cout << "sw $t1, 0($t0)" << endl;
					}
					else if ((*FT["_G"])[node->child[0]->child[0]->data] != 0 && (*ISA["_G"])[node->child[0]->child[0]->data] == 1)	
					{
						cout << "add $t0, $t0, " << (*FT["_G"])["#"] - (*FT["_G"])[node->child[0]->child[0]->data] << endl;
						cout << "add $t0, $t0, $s2" << endl; cout << "sw $t1, 0($t0)" << endl;
					}
					else
					{
						freopen(outputFile.c_str(), "w", stdout);
						cout << "Error.";
						fprintf(stderr, "\nCompile fail!\n");
						fprintf(stderr, "error occurs, %s is undefined\n" , (node->child[0]->child[0]->data).c_str() );
						exit(0);
					}
				}
			}
			else if(node->child[0]->type == 36)
			{
				string stname = STAC[node->child[0]->child[0]->child[0]->data];
				if(stname != "")
				{
				if((*FT[scope])[node->child[0]->child[0]->child[0]->data] != 0)
					cout << "sw $t0, " << 4 + (*FT[scope])["#"] - (*FT[scope])[node->child[0]->child[0]->child[0]->data]
							+(*ST[stname])["#"] - (*ST[stname])[node->child[0]->child[2]->data]
						<< "($s0)" << endl;
				else if ((*FT["_G"])[node->child[0]->child[0]->child[0]->data] != 0)	
					cout << "sw $t0, " << (*FT["_G"])["#"] - (*FT["_G"])[node->child[0]->child[0]->child[0]->data] 
					+(*ST[stname])["#"] - (*ST[stname])[node->child[0]->child[2]->data]
					<< "($s2)" << endl;
				}
				else
				{
					freopen(outputFile.c_str(), "w", stdout);
					cout << "Error.";
					fprintf(stderr, "\nCompile fail!\n");
					fprintf(stderr, "struct %s is not defined\n",(node->child[0]->child[0]->child[0]->data).c_str() );
					exit(0);
				}

			}
			else
			{
				freopen(outputFile.c_str(), "w", stdout);
				cout << "Error.";
				fprintf(stderr, "\nCompile fail!\n");
				fprintf(stderr, "error occurs,can't assign a value to a left value.\n" );
				exit(0);
			}
			break;
		}
		
		case 33:
		genExp(node->child[1], node->child[1]->type, scope);
		break;
		
		case 34:	//ID LP ARGS RP , function call
		{
		if (FT[node->child[0]->data]==0)
		{
			freopen(outputFile.c_str(), "w", stdout);
			cout << "Error.";
			fprintf(stderr, "\nCompile fail!\n");
			fprintf(stderr, "error occurs, function %s is undefined\n" , (node->child[0]->data).c_str() );
			exit(0);
		}

		int t = genArgs(node->child[2], node->child[2]->type, scope); //²ÎÊýÑ¹ÈëÕ»		
		//ÒÔÏÂ½øÐÐ²ÎÊý¼ì²é
		int real = (*FT[node->child[0]->data])["#"]/4 - (*FT[node->child[0]->data])["##"];
  		//int real = ((*FT[node->child[0]->data])["#"])/4-1; 

		if (t!=real) 
		{
			freopen(outputFile.c_str(), "w", stdout);
			cout << "Error.";
			fprintf(stderr, "\nCompile fail!\n");
		    fprintf(stderr, "error occurs, function %s should take %d parameters\n",( node->child[0]->data).c_str(), real); 
			exit(0);
		}
		
		cout << "add $sp, $sp, -" << (*FT[node->child[0]->data])["##"] * 4 << endl;		//(*FT[node->child[0]->data])["##"]Îª¾Ö²¿±äÁ¿µÄ¸öÊý
		cout << "add $sp, $sp, -4" << endl;
		cout << "sw $s0, 0($sp)" << endl; 
		cout << "move $s0, $sp" << endl; 
		cout << "jal " << "__" << node->child[0]->data << endl; //Ìø×ª
		cout << "add $sp, $sp, " << 4+(*FT[node->child[0]->data])["#"] << endl; 
		cout << "lw $s0, 0($s0)" << endl; 
		break;
		}
		
		case 35:
		{
			if(node->child[1]->type ==1)	//int []
			{
			//	cout << "\n!\n\n";
				genExp(node->child[1]->child[1], node->child[1]->child[1]->type, scope);
				cout << "mul $t0, $t0, 4" << endl;
			//	cout << "\n\nname = " << node->child[0]->data << endl;
			//	cout <<  (*FT[scope])[node->child[0]->data] << endl;
				if( (*FT[scope])[node->child[0]->data] != 0  && (*ISA[scope])[node->child[0]->data] == 1)
				{
			//		cout << "enter if\n.";
					cout << "add $t0, $t0, " << 4 + (*FT[scope])["#"] - (*FT[scope])[node->child[0]->data] << endl;
					cout << "add $t0, $t0, $s0" << endl; 
					if(pre == 1)	// ++
					{
						cout << "lw $t1, 0($t0)" << endl;
						cout << "add $t1, $t1, 1" << endl;
						cout << "sw $t1, 0($t0)" << endl;
						cout << "move $t0, $t1" << endl;
					}
					else if(pre == 2)	// --
					{
						cout << "lw $t1, 0($t0)" << endl;
						cout << "add $t1, $t1, -1" << endl;
						cout << "sw $t1, 0($t0)" << endl;
						cout << "move $t0, $t1" << endl;
					}
					else
						cout << "lw $t0, 0($t0)" << endl;
			//		cout << "leve if\n";
				}
				else if ((*FT["_G"])[node->child[0]->data] != 0 && (*ISA["_G"])[node->child[0]->data] == 1)	
				{
			//		cout << "\n\nenter else\n";
					cout << "add $t0, $t0, " << (*FT["_G"])["#"] - (*FT["_G"])[node->child[0]->data] << endl;
					cout << "add $t0, $t0, $s2" << endl;

					if(pre == 1)	// ++
					{
						cout << "lw $t1, 0($t0)" << endl;
						cout << "add $t1, $t1, 1" << endl;
						cout << "sw $t1, 0($t0)" << endl;
						cout << "move $t0, $t1" << endl;
					}
					else if(pre == 2)	// --
					{
						cout << "lw $t1, 0($t0)" << endl;
						cout << "add $t1, $t1, -1" << endl;
						cout << "sw $t1, 0($t0)" << endl;
						cout << "move $t0, $t1" << endl;
					}
					else
						cout << "lw $t0, 0($t0)" << endl;
			//		cout << "\n\nleave else\n";
				}
				else
				{
					freopen(outputFile.c_str(), "w", stdout);
					cout << "Error.";
					fprintf(stderr, "\nCompile fail!\n");
					fprintf(stderr, "error occurs, %s is undefined\n" , (node->child[0]->data).c_str() );
					exit(0);
				}
			}
			else //int
			{
				if((*FT[scope])[node->child[0]->data] != 0)
				{
					if(pre == 1)
					{
					cout << "lw $t0, " << 4 + (*FT[scope])["#"] - (*FT[scope])[node->child[0]->data] << "($s0)" << endl;
					cout << "add $t0, $t0, 1" << endl;
					cout << "sw $t0, " << 4 + (*FT[scope])["#"] - (*FT[scope])[node->child[0]->data] << "($s0)" << endl;
					}
					else if(pre ==2)
					{
					cout << "lw $t0, " << 4 + (*FT[scope])["#"] - (*FT[scope])[node->child[0]->data] << "($s0)" << endl;
					cout << "add $t0, $t0, -1" << endl;
					cout << "sw $t0, " << 4 + (*FT[scope])["#"] - (*FT[scope])[node->child[0]->data] << "($s0)" << endl;
					}
					else
						cout << "lw $t0, " << 4 + (*FT[scope])["#"] - (*FT[scope])[node->child[0]->data] << "($s0)" << endl;
				}
				else if ((*FT["_G"])[node->child[0]->data] != 0)	
				{
					if(pre == 1)
					{
					cout << "lw $t0, " << (*FT["_G"])["#"] - (*FT["_G"])[node->child[0]->data] << "($s2)" << endl;
					cout << "add $t0, $t0, 1" << endl;
					cout << "sw $t0, " << (*FT["_G"])["#"] - (*FT["_G"])[node->child[0]->data] << "($s2)" << endl;
					}
					else if(pre == 2)
					{
					cout << "lw $t0, " << (*FT["_G"])["#"] - (*FT["_G"])[node->child[0]->data] << "($s2)" << endl;
					cout << "add $t0, $t0, -1" << endl;
					cout << "sw $t0, " << (*FT["_G"])["#"] - (*FT["_G"])[node->child[0]->data] << "($s2)" << endl;
					}
					else
						cout << "lw $t0, " << (*FT["_G"])["#"] - (*FT["_G"])[node->child[0]->data] << "($s2)" << endl;
				}
			}
			break;
		}
		case 36:
		{
			//ÕâÀïÐèÒª´íÎó¼ì²é £¬Èô²»´æÔÚ...
			string stname = STAC[node->child[0]->child[0]->data];
			if(stname != "")
			{
			if((*FT[scope])[node->child[0]->child[0]->data] != 0)
			{
				if(pre == 1)	// ++i.a
				{
				cout << "lw $t0, " << 4 + (*FT[scope])["#"] - (*FT[scope])[node->child[0]->child[0]->data]
						+(*ST[stname])["#"] - (*ST[stname])[node->child[2]->data]
					<< "($s0)" << endl;
				cout << "add $t0, $t0, 1";			
				cout << "sw $t0, " << 4 + (*FT[scope])["#"] - (*FT[scope])[node->child[0]->child[0]->data]
						+(*ST[stname])["#"] - (*ST[stname])[node->child[2]->data]
					<< "($s0)" << endl;	
				}
				else if(pre == 2)
				{
				cout << "lw $t0, " << 4 + (*FT[scope])["#"] - (*FT[scope])[node->child[0]->child[0]->data]
						+(*ST[stname])["#"] - (*ST[stname])[node->child[2]->data]
					<< "($s0)" << endl;
				cout << "add $t0, $t0, -1";			
				cout << "sw $t0, " << 4 + (*FT[scope])["#"] - (*FT[scope])[node->child[0]->child[0]->data]
						+(*ST[stname])["#"] - (*ST[stname])[node->child[2]->data]
					<< "($s0)" << endl;	
				}
				else
					cout << "lw $t0, " << 4 + (*FT[scope])["#"] - (*FT[scope])[node->child[0]->child[0]->data]
						+(*ST[stname])["#"] - (*ST[stname])[node->child[2]->data]
					<< "($s0)" << endl;
			}
			else if ((*FT["_G"])[node->child[0]->child[0]->data] != 0)	//--i.a
			{
				if(pre == 1)
				{
				cout << "lw $t0, " << (*FT["_G"])["#"] - (*FT["_G"])[node->child[0]->child[0]->data] 
				+(*ST[stname])["#"] - (*ST[stname])[node->child[2]->data]
				<< "($s2)" << endl;
				cout << "add $t0, $t0, 1" << endl;
				cout << "sw $t0, " << (*FT["_G"])["#"] - (*FT["_G"])[node->child[0]->child[0]->data] 
				+(*ST[stname])["#"] - (*ST[stname])[node->child[2]->data]
				<< "($s2)" << endl;
				}
				else if(pre == 2)
				{
				cout << "lw $t0, " << (*FT["_G"])["#"] - (*FT["_G"])[node->child[0]->child[0]->data] 
				+(*ST[stname])["#"] - (*ST[stname])[node->child[2]->data]
				<< "($s2)" << endl;
				cout << "add $t0, $t0, -1" << endl;
				cout << "sw $t0, " << (*FT["_G"])["#"] - (*FT["_G"])[node->child[0]->child[0]->data] 
				+(*ST[stname])["#"] - (*ST[stname])[node->child[2]->data]
				<< "($s2)" << endl;
				}
				else
				cout << "lw $t0, " << (*FT["_G"])["#"] - (*FT["_G"])[node->child[0]->child[0]->data] 
				+(*ST[stname])["#"] - (*ST[stname])[node->child[2]->data]
				<< "($s2)" << endl;
			}
			}
			else
			{
				freopen(outputFile.c_str(), "w", stdout);
				cout << "Error.";
				fprintf(stderr, "\nCompile fail!\n");
				fprintf(stderr, "error occurs, %s is undefined\n" , (node->child[0]->child[0]->data).c_str() );
				exit(0);
			}
			break;
		}
	
		case 37:
		cout << "li $t0, " << node->child[0]->data << endl;
		break;

		case 38:
		cout << "li $t0, 0" << endl;
		break;
	}
}

int genArgs(treeNode* node, int type, string scope)
{
	switch(type)
	{
		case 1:
		{
			genExp(node->child[0], node->child[0]->type, scope);
			cout << "add $sp, $sp, -4" << endl;
			cout << "sw $t0, 0($sp)" << endl;
			int i = genArgs(node->child[2], node->child[2]->type, scope);
			return 1+i;
			break;
		}
		case 2:
		{
			genExp(node->child[0], node->child[0]->type, scope);
			cout << "add $sp, $sp, -4" << endl;
			cout << "sw $t0, 0($sp)" << endl;
			return 1;
			break;
		}
	}
}



