#include "HuffmanTree.h"
using namespace std;

int main()
{
	CHuffmanTree *pHuffTre=new CHuffmanTree();
	//Ŀǰֻ֧��Ӣ���ļ����ļ��в��ܴ�����
	pHuffTre->CreateFileInfo("..\\huffman.xml");
	delete pHuffTre;
	return 0;
}