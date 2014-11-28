#include "TreeNode.h"

class CHuffmanTree
{
public:
	CHuffmanTree(int arrySize = 256);
	~CHuffmanTree();
	void CreateFileInfo(char filepath[]);
private:
	int charArrySize;
	unsigned long* charIndex;
};