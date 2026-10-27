#include <stdio.h>

//实现计算1+2+3+...+n的值，并返回计算结果
int fun(int n)
{
	int sum = 0; //用于累加计算结果
	//循环n次，计算1~n的值
	for (int i = 1; i <= n; i++)
	{
		sum += i; //累加计算结果
	}
	return sum; //返回计算结果
}

int main(int argc, char const *argv[])
{
	printf("%d\n", fun(5));
	return 0;
}