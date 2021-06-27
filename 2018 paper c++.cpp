
#include<iostream>
//void main()
//{
//	int value;
//	value=test(5);
//	cout<<value;
//}
using namespace std;
int test(int n)
{
	int array[n];
	array[0]=0;
	array[1]=1;
	int i;
	
	for(i=2;i<=n;i++)
	{
		array[i]=array[i-1]+array[i-2];
	}
	return array[n];
}
int main()
{
	int value;
	value=test(5);
	cout<<value;
}
