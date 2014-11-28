#include "TreeOperate.h"
#include <iostream>
using namespace std;

int main()
{
	CTreeOperate *pTreeOp = new CTreeOperate();
	NODE *root = nullptr;
	pTreeOp->GetRoot(&root);
	if (root)
	{
		//cout<<"PreOrder : ";
		//pTreeOp->PreOrder(root);
		//cout<<"\n";
		//cout<<"         : ";
		//pTreeOp->PreOrder();
		//cout<<"\n=================================================================\n";
		cout<<"InOrder  : ";
		pTreeOp->InOrder(root);
		cout<<"\n";
		cout<<"         : ";
		pTreeOp->InOrder();
		cout<<"\n=================================================================\n";
		//cout<<"PostOrder: ";
		//pTreeOp->PostOrder(root);
		//cout<<"\n";
		//cout<<"         : ";
		//pTreeOp->PostOrder();
		//cout<<"\n=================================================================\n";
		//cout<<"The Origin Tree is like : \n";
		//pTreeOp->OutputTree(root);
		//cout<<"\n=================================================================\n";
		NODE *broot;
		pTreeOp->CopyTree(root,&broot);
		cout<<"After copy tree :\n";
		cout<<"PreOrder : ";
		pTreeOp->PostOrder(broot);
		cout<<"\n=================================================================\n";
		NODE *rootHead;
		pTreeOp->InThreadTree(broot,&rootHead);
		cout<<"InOrder  : ";
		pTreeOp->InOrderThread(rootHead);
		cout<<"\n";
		cout<<"         : ";
		pTreeOp->InROrderThread(rootHead);
		cout<<"\n";
		//pTreeOp->DeleteTree(broot);				//线索化之后要注意，删除策略要做出改变
		cout<<"\n=================================================================\n";
	}
	//对树的操作处理
	CTree *pTree = new CTree();
	NODE *tRoot;
	pTree->GetRoot(&tRoot);
	cout<<"PreOrder     : ";
	pTree->PreOrder(tRoot);
	cout<<"\n";
	cout<<"ListOrder    : ";
	pTree->ListOrder(tRoot);
	cout<<"\n";
	return 0;
}