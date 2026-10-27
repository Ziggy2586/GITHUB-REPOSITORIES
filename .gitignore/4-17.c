#include <stdio.h>

int fibonacci(int n)
{
	//如果是第1项或第2项，返回1。否则返回前两项的和
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else
	{
		return fibonacci(n - 1) + fibonacci(n - 2); //返回前两项的和
	}
}

int main(int argc, char const *argv[])
{
	printf("%d\n", fibonacci(6)); //计算斐波纳契数列第6项并输出
	return 0;
}