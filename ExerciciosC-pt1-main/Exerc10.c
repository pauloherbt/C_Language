#include<stdio.h>
#include<stdlib.h>
#include<math.h>
main()
{
	int n,c,pot;
	printf("Quantas potencias de 2 calcular? ");
	scanf("%d", &n);
	for(c=0;c<n;c++)
	{
		pot=pow(2,c);
		printf("%d ", pot);
	}
		
}
