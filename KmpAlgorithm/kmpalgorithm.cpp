//����ģʽƥ���㷨KMP�㷨
//���ݽṹ�������еڶ��棩���������
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