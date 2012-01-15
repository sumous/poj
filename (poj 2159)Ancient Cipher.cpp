#include<stdio.h>
#include<string.h>
int main()
{
	char a[100],b[100];
	int i,c[100]={1},j,flag=0;
	gets(a);
	gets(b);
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]=='A') a[i]='Z';
		else a[i]-=1;
	}
	for(j=0;j<strlen(a);j++)
	{
		for(i=0;i<strlen(a);i++)
		{
			if(c[i]&&a[i]==b[j]) {c[i]=0;break;}
		}
	}
	for(i=0;i<strlen(a);i++)
	{
		if(c[i]) {flag=1;break;}
	}

	if(flag) printf("NO");
    else printf("YES");
	return 0;

}