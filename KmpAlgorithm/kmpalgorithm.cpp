//快速模式匹配算法KMP算法
//数据结构（六大有第二版）第三章相关
#include "kmpalgorithm.h"
using namespace std;


int main(int argc, char*argv[])
{
	string S = "abaabcacabaabcacabaabcacabaabcacabaabcac";
	string T = "ab";
	string::size_type count = COUNT_KMP(S, T);
	cout << count << endl;
	system("PAUSE");
	return 0;
}