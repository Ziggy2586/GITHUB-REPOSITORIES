#include <stdio.h>
int main(int argc, char const *argv[])
{
	int n; //执行 1 次
	scanf("%d", &n); //执行 1 次
	for (int i = 0; i < n; i++) //执行 n + 1次
	{
		int a = 5; //执行 n 次
		a++; //执行 n 次
	}
	return 0;
}