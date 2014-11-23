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
		cout<<"PreOrder : ";
		pTreeOp->PreOrder(root);
		cout<<"\n";
		cout<<"         : ";
		pTreeOp->PreOrder();
		cout<<"\n=================================================================\n";
		cout<<"InOrder  : ";
		pTreeOp->InOrder(root);
		cout<<"\n";
		cout<<"         : ";
		pTreeOp->InOrder();
		cout<<"\n=================================================================\n";
		cout<<"PostOrder: ";
		pTreeOp->PostOrder(root);
		cout<<"\n";
		cout<<"         : ";
		pTreeOp->PostOrder();
		cout<<"\n=================================================================\n";
		cout<<"The Origin Tree is like : \n";
		pTreeOp->OutputTree(root);
		cout<<"\n=================================================================\n";
		NODE *broot;
		pTreeOp->CopyTree(root,&broot);
		cout<<"After copy tree :\n";
		cout<<"PreOrder : ";
		pTreeOp->PostOrder(broot);
	}
	return 0;
}