#include<stdio.h>
main()
{
	int c1,c2;
	for(c1=1;c1<=10;c1++)
	{
		printf("\nTabuada do %d\n",c1);
		for(c2=1;c2<=10;c2++)
		{
			printf("%d x %d = %d\n",c1,c2,c1*c2);
		}
	}
}
