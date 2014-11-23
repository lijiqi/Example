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
		cout<<"\n";
		cout<<"InOrder  : ";
		pTreeOp->InOrder(root);
		cout<<"\n";
		cout<<"         : ";
		pTreeOp->InOrder();
		cout<<"\n";
		cout<<"PostOrder: ";
		pTreeOp->PostOrder(root);
		cout<<"\n";
		cout<<"         : ";
		pTreeOp->PreOrder();
		cout<<"\n";
	}
	return 0;
}