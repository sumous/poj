#include<stdio.h>
int main()
{
	float x,y,xy;
	int s=0,n,year[100],i;
	scanf("%d",&n);
	while(s<n)
	{
		scanf("%f%f",&x,&y);
	xy = 3.1415926*(x*x+y*y)*0.5;
    year[s] = (int)(xy/50)+1; 
    s++;
	}
	for( i=0;i<s;i++)
	 printf("Property %d: This property will begin eroding in year %d.\n",i+1,year[i]);
    printf("END OF OUTPUT.");
	return 0;
}