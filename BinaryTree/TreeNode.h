/************************************************************************/
/* by:lijianqiang
/* date:2014/11/23
/* ver:1.0
/************************************************************************/
//trees node define

#ifndef _TREENODE_H_
#define _TREENODE_H_
#include <stdlib.h>
#include <string>
using namespace std;
struct NODE
{
	NODE(string value="",NODE *left=nullptr,NODE *right=nullptr):nodeValue(value),leftChild(left),rightChild(right){lThread=rThread=false;}
	~NODE(){delete leftChild;leftChild=nullptr;delete rightChild;rightChild=nullptr;}
	string nodeValue;
	NODE *leftChild;
	NODE *rightChild;
	bool lThread;              //为了线索化二叉树而添加
	bool rThread;
};

#endif /*_TREENODE_H_*/