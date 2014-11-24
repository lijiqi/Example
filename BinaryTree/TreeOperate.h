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
	void CreateTree(string &s,NODE *root);
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
	void InThreadTree(NODE *root , NODE **rHead);
	void InOrderThread(NODE *rootHead);
private:
	NODE *m_pRoot;
};

#endif /*_TREEOPERATE_H_*/