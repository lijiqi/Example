
#include "HuffmanTree.h"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

CHuffmanTree::CHuffmanTree(size_t arrySize/*=256*/)
{
	charArrySize = arrySize;
	charNum = 0;
	charIndex = new unsigned long[charArrySize];
	for(size_t i=0;i<charArrySize;++i)
	{
		charIndex[i]=0;
	}
	pHuffRoot = nullptr;
}

CHuffmanTree::~CHuffmanTree()
{
	delete []charIndex;
}

void CHuffmanTree::CreateFileInfo(char filepath[])
{
	ifstream infile;
	infile.open(filepath);
	if (!infile)
	{
		cerr<<"Can't open the file :"<<filepath<<endl;
	}
	while(!infile.eof())
	{
		char ch;
		if (infile.read(&ch,1))
			++charIndex[char(ch)];
	}
	for (size_t i=0;i<charArrySize;++i)
	{
		if (charIndex[i] != 0)
		{
			++charNum;
			//cout<<char(i)<<" : "<<charIndex[i]<<endl;
		}
	}
	infile.close();
}

void CHuffmanTree::CreateTree(NODE **root)
{
	size_t arraySize = 2*charNum-1;
	NODE* pRoot = new NODE[arraySize];
	int k = 0;

	for (size_t i=0;i<charArrySize;++i)
	{
		if (charIndex[i] != 0)
		{
			pRoot[k].info = char(i);
			pRoot[k].weight = charIndex[i];
			++k;
		}
	}
	
	for (size_t i=0;i<charNum;++i)
	{
		if (pRoot[i].weight)
		{
			cout<<pRoot[i].info<<" : "<<pRoot[i].weight<<"  \n";
		}
	} 
	SortNodeArray(pRoot,charNum);
	k=0;
	for (size_t i=charNum;i<arraySize;++i)
	{
		pRoot[i].info = '#';
		pRoot[i].weight = pRoot[k].weight + pRoot[k+1].weight;
		pRoot[i].lLink = &pRoot[k];
		pRoot[i].rLink = &pRoot[k+1];
		k+=2;
		SortNodeArray(pRoot+k,i+1-k);
	}
	pHuffRoot = &pRoot[arraySize-1];
	*root = &pRoot[arraySize-1];
}

void CHuffmanTree::OutputHuffTree(NODE *root)
{
	if (!root)
	{
		return;
	}
	cout<<root->info<<" : "<<root->weight<<endl;
	OutputHuffTree(root->lLink);
	OutputHuffTree(root->rLink);
}

void CHuffmanTree::SortNodeArray(NODE* nodeArray , size_t num)
{
	//sort the Node Array
	for (size_t i=0;i<num-1;++i)
	{
		for (size_t j=0;j<num-1;++j)
		{
			if (nodeArray[j].weight > nodeArray[j+1].weight)
			{
				SwapNode(nodeArray[j],nodeArray[j+1]);
			}
		}
	}
}

void CHuffmanTree::SwapNode(NODE& desNode , NODE& srcNode)
{
	NODE* pNode = new NODE();

	//pNode->info = desNode.info;
	//pNode->weight = desNode.weight;
	//pNode->lLink = desNode.lLink;
	//pNode->rLink = desNode.rLink;

	//desNode.weight = srcNode.weight;
	//desNode.info = srcNode.info;
	//desNode.lLink = srcNode.lLink;
	//desNode.rLink = srcNode.rLink;

	//srcNode.weight = pNode->weight;
	//srcNode.info = pNode->info;
	//srcNode.lLink = pNode->lLink;
	//srcNode.rLink = pNode->rLink;
	CopyNode(*pNode,srcNode);
	CopyNode(srcNode,desNode);
	CopyNode(desNode,*pNode);
	delete pNode;
}

void CHuffmanTree::CopyNode(NODE& desNode , NODE& srcNode)
{
	desNode.weight = srcNode.weight;
	desNode.info = srcNode.info;
	desNode.lLink = srcNode.lLink;
	desNode.rLink = srcNode.rLink;
}

void CHuffmanTree::GetHuffRoot(NODE **root)
{
	*root = pHuffRoot;
}

//void CHuffmanTree::OutputHuffCode(NODE *root)
//{
//	if (!root)
//	{
//		return;
//	}
//	int hcode[32] = {0};
//	int font,tail;
//	font = tail = 0;
//	cout<<"+++++++++++++++++++++++++++++++++++++++++++++++\n";
//	NODE *pNode = root;
//	vector<int>vBranchStack;
//	vector<NODE *>vNodeStack;
//	do 
//	{
//		while (pNode)
//		{
//			cout<<pNode->info<<" : "<<pNode->weight<<"\n";
//			vNodeStack.push_back(pNode);
//			pNode = pNode->lLink;
//		}
//		pNode = vNodeStack.back();
//		vNodeStack.pop_back();
//		
//		if (pNode->lLink == nullptr && pNode->rLink == nullptr)
//		{
//			//cout<<pNode->info<<" : "<<pNode->weight<<"\n";
//		}
//		pNode = pNode->rLink;
//	} while (!vNodeStack.empty() || pNode);
//}


void CHuffmanTree::OutputHuffCode(NODE *root , int hcode[] , int tail , ofstream& outfile)
{
	if (!root)
	{
		return;
	}
	if (!outfile)
	{
		cerr<<"Cant't Create file : huffcode.xml \n";
		return;
	}

	if (root->lLink == nullptr && root->rLink == nullptr)
	{
		cout<<root->info<<" : ";
		outfile<<root->info<<" : ";
		for (int i=0;i<tail;++i)
		{
			cout<<hcode[i];
			outfile<<hcode[i];
		}
		cout<<"\n";
		outfile<<"\n";
		--tail;
	}
	else
	{
		hcode[tail] = 0;
		++tail;
		OutputHuffCode(root->lLink,hcode,tail,outfile);
		--tail;  //还原（回溯）

		hcode[tail] = 1;
		++tail;
		OutputHuffCode(root->rLink,hcode,tail,outfile);
		--tail;  //还原（回溯）
	}
}
