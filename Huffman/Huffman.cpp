//Huffman ������������ز���
#include "HuffmanTree.h"
#include <fstream>
using namespace std;

int main()
{
	int hcode[32] = {0};
	CHuffmanTree *pHuffTre=new CHuffmanTree();
	//Ŀǰֻ֧��Ӣ���ļ����ļ��в��ܴ�����
	pHuffTre->CreateFileInfo("..\\huffman.xml");
	NODE *pRoot;
	pHuffTre->CreateTree(&pRoot);
	//pHuffTre->OutputHuffTree(pRoot);
	ofstream outfile;
	outfile.open("..\\huffcode.xml",ios::out);
	pHuffTre->OutputHuffCode(pRoot,hcode,0,outfile);
	outfile.close();
	delete pHuffTre;
	return 0;
}