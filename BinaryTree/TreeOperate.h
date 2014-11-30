/************************************************************************/
/* by:lijianqiang
/* date:2014/11/23
/* ver:1.0
/************************************************************************/
//Tree Operate define
#ifndef _TREEOPERATE_H_
#define _TREEOPERATE_H_
#include "TreeNode.h"
using namespace std;

class CTreeOperate
{
public:
	CTreeOperate();
	~CTreeOperate();
	//void CreateTree(char* s,NODE *root);
	void CreateTree(char filepath[]);
	void DeleteTree(NODE *root);
	void PreOrder();                  //normal
	void PreOrder(NODE *root);        //circal
	void InOrder();
	void InOrder(NODE *root);
	void PostOrder();
	void PostOrder(NODE *root);
	void OutputTree(NODE *root);
	void GetRoot(NODE **root);
	void CopyTree(NODE *in_root,NODE **out_tree);
	//以下是只针对中序线索二叉树的部分
	void InThreadTree(NODE *root , NODE **rHead);
	void InOrderThread(NODE *rootHead);
	void InROrderThread(NODE *rootHead);
	void InFirstNode(NODE *root,NODE **out_node);
	void InLastNode(NODE *root,NODE **out_node);
	void InPreNode(NODE *node,NODE **preNode);
	void InNextNode(NODE *node,NODE **postNode);
private:
	NODE *m_pRoot;
};

class CTree
{
public:
	CTree();
	~CTree();
	void CreateTree(char filepath[]);
	void DeleteTree(NODE *root);
	void PreOrder(NODE *root);        //由儿子由大到小的序列进行遍历（递归遍历）
	void ListOrder(NODE *root);
	void GetRoot(NODE **pRoot);
private:
	NODE *m_pRoot;
};

#endif /*_TREEOPERATE_H_*/