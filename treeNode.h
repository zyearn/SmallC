#ifndef _TREENODE_H
#define _TREENODE_H

#include <iostream>
#include <string>
using namespace std;

class treeNode
{
public:
    string data;
    int childnum;
    int type;
    treeNode** child;

    treeNode(string str, int n, int t=0)
    {
        childnum = n;
        type = t;
        data = str;

        child = new treeNode*[childnum];
        for(int i=0; i<childnum; i++)
            child[i] = NULL;
    }

    void Clear(treeNode *t)
    {
        if(t == NULL) return ;
        int i;
        for(i=0; i<t->childnum; i++)
            Clear(t->child[i]);
        for(i=0; i<t->childnum; i++)
            delete t->child[i];
    }
};

#endif
