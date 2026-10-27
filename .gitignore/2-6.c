#include <stdio.h>
int main(int argc, char const *argv[])
{
	int n; //执行 1 次
	scanf("%d", &n); //执行 1 次
	int x = 1;//执行 1 次
	int y = 1;//执行 1 次
	for(int k = 0; k < n; k++) //执行 n + 1 次
	{
		x++; //执行 n 次
	}
	for (int i = 0; i < n; i++) //执行 n + 1次
	{
		for(int j = 1; j <= n; j++) //执行 n * (n +1) 次
		{
			y++; //执行 n ^ 2 次
		}
	}
	return 0;
}