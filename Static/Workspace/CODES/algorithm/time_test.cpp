#include<stdio.h>
#include<time.h>
main()
{	int i, j;
	double a, b, sum = 0;
	int u;
	for (j = 0; j < 20; j++)
	{	//此处添加随机数产生
		a = clock();
		for (i = 0; i < 1000000000; i++)u=1; //此处添加运算
		b = clock();
		printf("%lf\n", b - a);
		sum += b - a;
	}
	printf("ans = %lf", sum / 20.0);
	getchar();
}