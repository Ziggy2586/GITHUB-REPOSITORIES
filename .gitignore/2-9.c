#include <stdio.h>
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	int x = 2;
	while(x < n / 2)
	{
		x = 2 * x;
	}
	return 0;
}