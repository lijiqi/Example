//Huffman 编码树及其相关操作
#include "HuffmanTree.h"
#include <fstream>
using namespace std;

int main()
{
	int hcode[32] = {0};
	CHuffmanTree *pHuffTre=new CHuffmanTree();
	//目前只支持英文文件，文件中不能带中文
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