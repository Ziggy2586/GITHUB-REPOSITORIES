#include <stdio.h>
int main(int argc, char const *argv[])
{
	//执行1次
	int a = 0;
	//执行1次
	int n;
	//执行1次
	scanf("%d", &n);
	//执行n次
	for (int i = 1; i <= n; i++)
	{
		//执行(1+2+3+...+n)=n(n+1)/2次（等差数列求和公式）
		for(int j = 1; j <= i; j++)
		{
			/*
				执行
				1+(1+2)+(1+2+3)+...+(1+2+3+...+n)
			   =n(n+1)(n+2)/6
			   次（三角数累加和数列计算）
			*/
			for(int k = 1; k <= j; k++)
			{
				a++;
			}
		}
	}
	return 0;
}