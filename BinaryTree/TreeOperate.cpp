#include "TreeOperate.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

CTreeOperate::CTreeOperate()
{
	m_pRoot = nullptr;
	CreateTree("..\\binary_tree.xml");
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
	//cout<<"\n";
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

//void CTreeOperate::CreateTree( char* s,NODE *root )
//{
//	int slen = strlen(s);
//	if (0==slen)
//	{
//		root = nullptr;
//		return;
//	}
//	vector<NODE *>vNodeStack;
//	vector<char>vCharStack;
//	int eq = -1;                 //equal symbol index
//	for (int i=0;i<slen;++i)
//	{
//		if (s[i] == '(')
//		{
//			vCharStack.push_back(s[i]);
//		}
//		else if (s[i] == ')')
//		{
//			vCharStack.pop_back();
//		}
//		else if (s[i] == '=')
//		{
//			eq = i;
//		}
//	}
//	if (!vCharStack.empty())
//	{
//		cerr<<"The bracket is not match !\n";
//		return;
//	} 
//	if (eq != -1)
//	{
//		slen = eq - 1;
//	}
//}

void CTreeOperate::DeleteTree(NODE *root)
{
	 NODE *pNode = root;
	if (pNode == nullptr)
	{
		return;
	}
	else
	{
		DeleteTree(pNode->leftChild);
		DeleteTree(pNode->rightChild);
		delete pNode;
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

//void CTreeOperate::InThreadTree( NODE *root , NODE **rHead)
//{
//	vector<NODE *>vNodeStack;
//	
//	NODE *rootHead = new NODE("rootHead");  //////////线索话二叉树，引进一个头节点
//	rootHead->lThread = false;
//	rootHead->rThread = true;
//	rootHead->leftChild = root;
//
//	NODE *pNode = root;
//	NODE *preNode = rootHead;
//	
//	do 
//	{
//		while (pNode)
//		{
//			if (!pNode->leftChild)
//			{
//				pNode->lThread = true;
//			}
//			if (!pNode->rightChild)
//			{
//				pNode->rThread = true;
//			}
//			vNodeStack.push_back(pNode);
//			pNode = pNode->leftChild;
//		}
//		pNode = vNodeStack.back();
//		vNodeStack.pop_back();
//
//		if (pNode->lThread)
//		{
//			pNode->leftChild = preNode;
//		}
//		if (preNode->rThread)
//		{
//			preNode->rightChild = pNode;
//		}
//		preNode = pNode;
//		pNode = pNode->rightChild;
//	} while (!vNodeStack.empty() || pNode);
//	preNode->rightChild = rootHead;
//	rootHead->rightChild = preNode;
//	*rHead = rootHead;
//}

void CTreeOperate::InThreadTree( NODE *root , NODE **rHead)
{
	if (!root)
	{
		*rHead = nullptr;
		return;
	}
	vector<NODE *>vNodeStack;
	NODE *rootHead = new NODE("rootHead");
	rootHead->lThread = false;
	rootHead->rThread = true;
	rootHead->leftChild = root;

	NODE *pNode = root;
	NODE *preNode = rootHead;
	
	do 
	{
		while (pNode)
		{
			if (!pNode->leftChild)
			{
				pNode->lThread = true;
			}
			if (!pNode->rightChild)
			{
				pNode->rThread = true;
			}
			vNodeStack.push_back(pNode);
			pNode = pNode->leftChild;
		}
		pNode = vNodeStack.back();
		vNodeStack.pop_back();
		if (pNode->lThread)
		{
			pNode->leftChild = preNode;
		}
		if (preNode->rThread)
		{
			preNode->rightChild = pNode;
		}
		preNode = pNode;
		pNode = pNode->rightChild;
	} while (!vNodeStack.empty() || pNode);
	preNode->rightChild = rootHead;
	rootHead->rightChild = preNode;
	*rHead = rootHead;
}

void CTreeOperate::InOrderThread( NODE *rootHead )
{
	if (!rootHead)
	{
		rootHead = nullptr;
		return;
	}
	NODE *pNode;
	if (rootHead->nodeValue == "rootHead")  
	{
		pNode = rootHead->leftChild;
	}
	else
	{
		pNode = rootHead;
	}

	if (pNode)
	{
		NODE *ouNode;
		InFirstNode(pNode,&ouNode);
		while (ouNode != rootHead)
		{
			cout<<ouNode->nodeValue<<"  ";
			pNode = ouNode;
			InNextNode(pNode,&ouNode);
		}
	}
}

void CTreeOperate::InROrderThread(NODE *rootHead)
{
	if (!rootHead)
	{
		rootHead = nullptr;
		return;
	}
	NODE *pNode;
	if (rootHead->nodeValue == "rootHead")  
	{
		pNode = rootHead->leftChild;
	}
	else
	{
		pNode = rootHead;
	}

	if (pNode)
	{
		NODE *ouNode;
		InLastNode(pNode,&ouNode);
		while (ouNode != rootHead)
		{
			cout<<ouNode->nodeValue<<"  ";
			pNode = ouNode;
			InPreNode(pNode,&ouNode);
		}
	}
}

void CTreeOperate::InFirstNode(NODE *root,NODE **out_node)
{
	if (!root)
	{
		*out_node=nullptr;
		return;
	}
	NODE *pNode;
	if (root->nodeValue == "rootHead")      //常规方法
	{
		pNode = root->leftChild;
	}
	else
	{
		pNode = root;
	}

	while (!pNode->lThread)
	{
		pNode = pNode->leftChild;
	}
	*out_node = pNode;
}

void CTreeOperate::InLastNode(NODE *root,NODE **out_node)
{
	if (!root)
	{
		*out_node=nullptr;
		return;
	}
	//*out_node =  root->rightChild;        //方法一，在有引进根节点的情况下
	NODE *pNode;
	if (root->nodeValue == "rootHead")      //常规方法
	{
		pNode = root->leftChild;
	}
	else
	{
		pNode = root;
	}

	while (!pNode->rThread)
	{
		pNode = pNode->rightChild;
	}
	*out_node = pNode;
}

void CTreeOperate::InPreNode(NODE *node,NODE **preNode)
{
	if (!node)
	{
		*preNode = nullptr;
		return;
	}
	if (node->lThread)
	{
		*preNode = node->leftChild;
	}
	else
	{
		InLastNode(node->leftChild,preNode);
	}
}

void CTreeOperate::InNextNode(NODE *node,NODE **postNode)
{
	if (!node)
	{
		*postNode = nullptr;
		return;
	}
	if (node->rThread)
	{
		*postNode = node->rightChild;
	}
	else
	{
		InFirstNode(node->rightChild,postNode);
	}
}

CTree::CTree()
{
	m_pRoot = nullptr;
	CreateTree("..\\tree.xml");
}

CTree::~CTree()
{
	DeleteTree(m_pRoot);
}

void CTree::CreateTree(char filepath[])
{
	ifstream infile;
	infile.open(filepath,ios::in);
	if (!infile)
	{
		cerr<<"Can't open file :"<<filepath<<endl;
		return;
	}

	vector<NODE *>vNodeStack;
	NODE *pNode;
	NODE *preNode;
	char nodeDir = 't';
	while (!infile.eof())
	{
		string s="\0";
		infile>>s;
		if (s != "\0")
		{
			if (s == "[")
			{
				nodeDir = 'f';
				vNodeStack.push_back(pNode);
			}
			else if (s == ",")
			{
				nodeDir = 'n';
			}
			else if (s == "]")
			{
				nodeDir = '\0';
				preNode = vNodeStack.back();
				vNodeStack.pop_back();
			}
			else
			{
				if (nodeDir == 't')
				{
					pNode = new NODE(s);
					preNode = pNode;
					m_pRoot = pNode;
				}
				else if (nodeDir == 'f')
				{
					pNode = new NODE(s);
					preNode->leftChild = pNode;
					preNode = pNode;
				}
				else if (nodeDir == 'n')
				{
					pNode = new NODE(s);
					preNode->rightChild = pNode;
					preNode = pNode;
				}
			}
		}
	}
	infile.close();
}

void CTree::PreOrder(NODE *root)
{
	if (root == nullptr)
	{
		return;
	}
	NODE *pNode = root;
	while (pNode)
	{
		cout<<pNode->nodeValue<<"  ";
		pNode = pNode->leftChild;
		while (pNode)
		{
			PreOrder(pNode);
			pNode = pNode->rightChild;
		}
	}
}

void CTree::GetRoot(NODE **pRoot)
{
	*pRoot = m_pRoot;
}

void CTree::DeleteTree(NODE *root)
{

}

void CTree::ListOrder(NODE *root)
{
	if (root == nullptr)
	{
		return;
	}

	NODE *pNode = root;
	queue<NODE *>vNodeQueue;
	do 
	{
		while (pNode)
		{
			if (pNode->leftChild)
			{
				vNodeQueue.push(pNode);
			}
			cout<<pNode->nodeValue<<"  ";
			pNode = pNode->rightChild;
		}
		if (!vNodeQueue.empty())
		{
			pNode = vNodeQueue.front();   //论队列的正确使用方法
			pNode = pNode->leftChild;
			vNodeQueue.pop();
		}
	} while (!vNodeQueue.empty() || pNode);
}
