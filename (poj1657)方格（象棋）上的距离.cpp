#include<stdio.h>
int Abs( int i )//取绝对值 
{
	return i > 0 ? i : (-i);
}

int Min( int x , int y )//取两者中的较小数 
{
	return x > y ? y : x;
}

int Wang( int a1 , int a2 , char b1 , char b2 )//王需要走的步数 
{
	int x , y;
	x = Abs( b1 - b2 );
	y = Abs( a1 - a2 );
    return Min( x , y ) + Abs( x - y );
}

int Hou( int a1 , int a2 , char b1 , char b2 )//后要走的步数 
{
	if( a1 == a2 || b1 == b2 || Abs( a2 - a1 ) == Abs( b2 - b1 ))
	  return 1;
	else return 2;
}

int Che( int a1 , int a2 , char b1 , char b2 )
{
	if( a1 == a2 || b1 == b2 ) return 1;
	else return 2;
}

int Xiang( int a1 , int a2 , char b1 , char b2 )
{
	if(Abs(a2-a1)==Abs(b2-b1)) return 1;
	else return 0;
}

int main()
{
	int a1,a2,n,i,wang,hou,che,xiang;
	char b1,b2;
	scanf( "%d" , &n );
	while( n != 0)
	{
		getchar();
		scanf( "%c%d %c%d" , &b1 , &a1 , &b2 , &a2  );
		wang = Wang( a1 , a2 ,b1 , b2 );
		xiang = Xiang( a1 , a2 , b1 , b2 );
		hou = Hou( a1 , a2 , b1 , b2 );
		che = Che( a1 , a2 , b1 , b2 );
		if( xiang == 0 ) printf( "%d %d %d Inf\n" , wang , hou , che );
		else printf( "%d %d %d %d\n" , wang , hou , che , xiang );
		n --;
	} 
	return 0;
}