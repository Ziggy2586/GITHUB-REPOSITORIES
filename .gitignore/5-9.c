#include <stdio.h>
int main(int argc, char const *argv[])
{
	float score;
	printf("请输入成绩：\n");
	scanf("%f", &score);
	if (score < 60)
	{
		printf("不及格");
	}
	else if (score < 70)
	{
		printf("及格");
	}
	else if(score < 80)
	{
		printf("中等");
	}
	else if(score < 90)
	{
		printf("良好");
	}
	else
	{
		printf("优秀");
	}
	return 0;
}