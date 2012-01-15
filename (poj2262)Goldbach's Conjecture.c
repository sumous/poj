#include<stdio.h>

int main()
{
  long i,j,n,a[100],b[100],d[1000000]={0};
for(i=2;i<=10000;i++)
{
	for(j=2*i;j<10000;j+=i) d[j]=1;
}                                 //用筛法把1000000以内的素数找出来 
  for(n=0;;n++)
  {
  	scanf("%ld",&a[n]);
  	if(!a[n]) break;//结束的标志 
  	else 
  	{
  		for(j=3;;j++)
  		{
  	      if(!d[j]&&!d[a[n]-j]) {b[n]=j;break;} 
	    }//找出满足条件的数，然后跳出循环 
   }
  }

  for(i=0;i<n;i++) 
     printf("%ld=%ld+%ld\n",a[i],b[i],a[i]-b[i]);
  return 0;	
}