/************************************************************************/
/* BY:lijianqiang
/* TIME:2014/11/27
/* VER:1.0
/************************************************************************/
#ifndef _TREENODE_H_
#define _TREENDOE_H_
#include <string>
using namespace std;

struct NODE
{
	string info;
	unsigned long weight;
	NODE *lLink;
	NODE *rLink;
};

#endif /*_TREENODE_H_*/