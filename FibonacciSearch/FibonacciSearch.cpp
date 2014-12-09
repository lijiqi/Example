//http://blog.csdn.net/zpluw/article/details/7757331
/*쳲��������ҷ���ǰ�������Ա��������,ʱ�临�Ӷ���O(logn)*/
#include<iostream>

const int MAXSIZE = 20;

int Fibonacci_Search(int *a, int n, int key);

/*�÷ǵݹ鷨����һ��쳲���������*/
void Fibonacci(int *f)
{
    f[0] = 1;
    f[1] = 1;
	
    for(int i=2; i<MAXSIZE; i++)
    {
        f[i] = f[i-1] + f[i-2];
    }
}

int main()
{	
	int array[] = {0,16,24,35,47,59,62,73,88,99};
	
	int number = Fibonacci_Search(array, sizeof(array)/sizeof(int), 73);
	std::cout<<"λ���ǣ�array["<<number<<"]\n";
    return 0;
}

/*����쳲��������ҷ�*/
int Fibonacci_Search(int *a, int n, int key)
{
	int low, high, mid, i, k;
	int F[MAXSIZE];

    Fibonacci(F); //����һ��쳲���������F
	low = 1;   //����±��¼Ϊ��λ
	high = n;  //����±��¼Ϊĩλ
	k = 0;

	while(n > F[k]-1)  //����nλ��쳲��������е�λ��
	{
		k++;
	}

	for(i=n; i<F[k]-1; i++)  //��a��Ԫ����չ��(ĳ쳲������� - 1)����F[k]-1
	{
		a[i] = a[n];
	}

	while(low <= high)
	{
		mid = low + F[k-1] - 1;   //���㵱ǰ�ָ���±�
		if(key < a[mid])
		{
			high = mid - 1;
			k -= 1;
		}
		else if(key > a[mid])
		{
			low = mid + 1;
			k -= 2;
		}
		else
		{
			if(mid <= n)
				return mid;   //���൱��˵��mid��Ϊ���ҵ���λ��
			else
				return n;     //��mid>n��˵������չ����ֵ������n
		}
	}
	return -1;
}
