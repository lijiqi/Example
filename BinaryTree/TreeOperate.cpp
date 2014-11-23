#include "TreeOperate.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

CTreeOperate::CTreeOperate()
{
	m_pRoot = nullptr;
	CreateTree("..\\treenode.xml");
}

CTreeOperate::~CTreeOperate()
{
	DeleteTree(m_pRoot);
}

void CTreeOperate::CreateTree(char filepath[])
{
	m_pRoot=nullptr;
	ifstream infile;
	infile.open(filepath,ios::in);
	if (!infile)
	{
		cerr<<"Can't open file :"<<filepath<<endl;
		return;
	}
	//check whether the tree is legal
	vector<string>vT;
	while (!infile.eof())
	{
		string bracket="\0";
		infile>>bracket;
		if (bracket != "\0")
		{
			if (bracket == "[")
			{
				vT.push_back(bracket);
				//cout<<bracket<<"  ";
			}
			else if (bracket == "]")
			{
				vT.pop_back();
				//cout<<bracket<<"  ";
			}
		}
	}
	cout<<"\n";
	if (!vT.empty())
	{
		cerr<<"The tree is illegal , please check again !\n";
		return;
	}
	infile.close();

	infile.open(filepath,ios::in);
	infile.seekg(ios::beg);
	NODE *preNode=nullptr;
	vector<NODE *>vpNode;
	char nodeDir = 't';
	while (!infile.eof())
	{
		string s="\0";
		infile>>s;
		if (s != "\0")
		{
			if ( s == "[")
			{
				nodeDir = 'l';
				vpNode.push_back(preNode);
			}
			else if (s == ",")
			{
				nodeDir = 'r';
				preNode = vpNode.back();
				vpNode.pop_back();
			}
			else if (s == "]")
			{
				nodeDir = '\0';
			}
			else
			{
				if (nodeDir == 't')
				{
					m_pRoot = new NODE(s);
					preNode = m_pRoot;
				}
				else if (nodeDir == 'l')
				{
					NODE *left=new NODE(s);
					preNode->leftChild = left;
					preNode = preNode->leftChild;
				}
				else if (nodeDir == 'r')
				{
					NODE *right=new NODE(s);
					preNode->rightChild = right;
					preNode = preNode->rightChild;
				}
			}
		}
	}
	infile.close();
}

void CTreeOperate::CreateTree(string &s,NODE *root)
{

}

void CTreeOperate::DeleteTree(NODE *root)
{
	if (root)
	{
		DeleteTree(root->leftChild);
		DeleteTree(root->rightChild);
		delete root;
	}
}

//void CTreeOperate::PreOrder()
//{
//	vector<NODE *>vNodeStack;
//	NODE *pNode = m_pRoot;
//	do 
//	{
//		while (pNode)
//		{
//			cout<<pNode->nodeValue<<"  ";
//			vNodeStack.push_back(pNode);
//			pNode = pNode->leftChild;
//		}
//		pNode = vNodeStack.back();
//		vNodeStack.pop_back();
//		pNode = pNode->rightChild;
//	} while (!vNodeStack.empty() || pNode);
//}
void CTreeOperate::PreOrder()
{
	vector<NODE *>vNodeStack;
	NODE *pNode = m_pRoot;
	do 
	{
		while (pNode)
		{
			cout<<pNode->nodeValue<<"  ";
			vNodeStack.push_back(pNode);
			pNode = pNode->leftChild;
		}
		pNode = vNodeStack.back();
		vNodeStack.pop_back();
		pNode = pNode->rightChild;
	} while (!vNodeStack.empty() || pNode);
}

void CTreeOperate::PreOrder(NODE *root)
{
	if (root == nullptr)
	{
		return;
	}
	else
	{
		cout<<root->nodeValue<<"  ";
		PreOrder(root->leftChild);
		PreOrder(root->rightChild);
	}
}

void CTreeOperate::InOrder()
{
	vector<NODE *>vNodeStack;
	NODE *pNode = m_pRoot;
	do 
	{
		while (pNode)
		{
			vNodeStack.push_back(pNode);
			pNode = pNode->leftChild;
		}
		pNode = vNodeStack.back();
		vNodeStack.pop_back();
		cout<<pNode->nodeValue<<"  ";
		pNode = pNode->rightChild;
	} while (!vNodeStack.empty() || pNode);
}

void CTreeOperate::InOrder(NODE *root)
{
	if (root == nullptr)
	{
		return;
	}
	else
	{
		InOrder(root->leftChild);
		cout<<root->nodeValue<<"  ";
		InOrder(root->rightChild);
	}
}


//void CTreeOperate::PostOrder()
//{
//	vector<NODE *>vNodeStack;
//	NODE *pNode = m_pRoot;
//	NODE *preNode = nullptr;
//	do 
//	{
//		while (pNode)
//		{
//			vNodeStack.push_back(pNode);
//			pNode = pNode->leftChild;
//		}
//
//		pNode = vNodeStack.back();
//		if (preNode == pNode->rightChild)
//		{
//			cout<<pNode->nodeValue<<"  ";
//			preNode = pNode;
//			pNode = nullptr;
//			vNodeStack.pop_back();
//		}
//		else
//		{
//			pNode = pNode->rightChild;
//			preNode = nullptr;
//		}
//	} while (!vNodeStack.empty() || pNode);
//}
void CTreeOperate::PostOrder()
{
	vector<NODE *>vNodeStack;
	NODE *pNode = m_pRoot;
	NODE *preNode = nullptr;
	do 
	{
		while (pNode)
		{
			vNodeStack.push_back(pNode);
			pNode = pNode->leftChild;
		}
		pNode = vNodeStack.back();
		if (preNode == pNode->rightChild)
		{
			cout<<pNode->nodeValue<<"  ";
			preNode = pNode;
			pNode = nullptr;
			vNodeStack.pop_back();
		}
		else
		{
			pNode = pNode->rightChild;
			preNode = nullptr;
		}
	} while (!vNodeStack.empty() || pNode);
}

void CTreeOperate::PostOrder(NODE *root)
{
	if (root == nullptr)
	{
		return;
	}
	else
	{
		PostOrder(root->leftChild);
		PostOrder(root->rightChild);
		cout<<root->nodeValue<<"  ";
	}
}

void CTreeOperate::GetRoot(NODE **root)
{
	if (m_pRoot)
	{
		*root = m_pRoot;
	}
	else
	{
		*root = nullptr;
	}
}

void CTreeOperate::OutputTree(NODE *root)
{
	if (root)
	{
		NODE *pNode = root;
		cout<<pNode->nodeValue;
		if (pNode->leftChild || pNode->rightChild)
		{
			cout<<" [ ";
			OutputTree(pNode->leftChild);
			if (pNode->rightChild)
			{
				cout<<" , ";
			}
			OutputTree(pNode->rightChild);
			cout<<" ] ";
		}
	}
}

void CTreeOperate::CopyTree( NODE *in_root,NODE **out_tree )
{
	if (in_root)
	{
		*out_tree = new NODE(in_root->nodeValue);
		if (in_root->leftChild)
		{
			CopyTree(in_root->leftChild,&(*out_tree)->leftChild);
		}
		if (in_root->rightChild)
		{
			CopyTree(in_root->rightChild,&(*out_tree)->rightChild);
		}
	}
}
