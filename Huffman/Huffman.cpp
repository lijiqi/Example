#include "HuffmanTree.h"
using namespace std;

int main()
{
	CHuffmanTree *pHuffTre=new CHuffmanTree();
	//目前只支持英文文件，文件中不能带中文
	pHuffTre->CreateFileInfo("..\\huffman.xml");
	NODE *pRoot;
	pHuffTre->CreateTree(&pRoot);
	//pHuffTre->OutputHuffTree(pRoot);
	pHuffTre->OutputHuffCode(pRoot);
	delete pHuffTre;
	return 0;
}