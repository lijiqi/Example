#include "HuffmanTree.h"
using namespace std;

int main()
{
	CHuffmanTree *pHuffTre=new CHuffmanTree();
	//Ŀǰֻ֧��Ӣ���ļ����ļ��в��ܴ�����
	pHuffTre->CreateFileInfo("..\\huffman.xml");
	NODE *pRoot;
	pHuffTre->CreateTree(&pRoot);
	//pHuffTre->OutputHuffTree(pRoot);
	pHuffTre->OutputHuffCode(pRoot);
	delete pHuffTre;
	return 0;
}