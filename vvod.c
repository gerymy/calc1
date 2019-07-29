#include<stdio.h>
void vvodi(float *real, float *compx )
{
	float a;
	float b;
	printf("real:");
	scanf("%f", &a);
	printf("image:");
	scanf("%f", &b);
	*real=a;
	*compx=b;
}
void clear ()
{    
  while ( getchar() != '\n' );
}