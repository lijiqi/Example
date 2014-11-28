
#include "HuffmanTree.h"
#include <fstream>
#include <iostream>
using namespace std;

CHuffmanTree::CHuffmanTree(int arrySize/*=256*/)
{
	charArrySize = arrySize;
	charIndex = new unsigned long[charArrySize];
	for(size_t i=0;i<charArrySize;++i)
	{
		charIndex[i]=0;
	}
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
		char ch;//='\0';
		if (infile.read(&ch,1))
			++charIndex[char(ch)];
	}
	for (size_t i=0;i<charArrySize;++i)
	{
		if (charIndex[i] != 0)
		{
			cout<<char(i)<<" : "<<charIndex[i]<<endl;
		}
	}
	infile.close();
}