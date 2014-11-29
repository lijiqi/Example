#include "TreeNode.h"
class CHuffmanTree
{
public:
	CHuffmanTree(size_t arrySize = 256);
	~CHuffmanTree();
	void CreateFileInfo(char filepath[]);
	void CreateTree(NODE **root);
	void OutputHuffTree(NODE *root);
	//void OutputHuffCode(NODE *root);
	void OutputHuffCode(NODE *root , int hcode[] , int tail , ofstream& outfile);
	void GetHuffRoot(NODE **root);
private:
	void SortNodeArray(NODE* nodeArray , size_t num);
	void SwapNode(NODE& desNode , NODE& srcNode);
	void CopyNode(NODE& desNode , NODE& srcNode);
	size_t charArrySize;
	size_t charNum;
	unsigned long* charIndex;
	NODE* pHuffRoot;
};