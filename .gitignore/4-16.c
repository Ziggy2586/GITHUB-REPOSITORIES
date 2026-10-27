#include <stdio.h>
int fibonacci(int n)
{
	int last1 = 1; //数列的倒数第1项
	int last2 = 1; //数列的倒数第2项
	int result = 0; //第n项的值

	//从第3项开始，循环计算后面每一项的值，一直计算到第n项
	for (int i = 3; i <= n; i++)
	{
		result = last1 + last2; //从第3项开始，每一项的值等于前两项的和
		last2 = last1; //计算出新的值后，原来的倒数第1项变成倒数第2项
		last1 = result; ////计算出的新值，成为新的倒数第1项
	}
	return result;
}

int main(int argc, char const *argv[])
{
	printf("%d\n", fibonacci(6)); //计算斐波纳契数列第6项并输出
	return 0;
}