#include<stdio.h>
int main()
{

   int p , i , e , d , count = 1,result;
    /*�����ÿ�����������������˻�������1����*/
    /*for( p1 = 33*28;p1 % 23 != 1;p1 += 33*28 );
    for( e1 = 33*23;e1 % 28 != 1;e1 += 33*23 );
    for( i1 = 23*28;i1 % 33 != 1;i1 += 28*23 );  */

    scanf( "%d%d%d%d" , &p , &e , &i , &d );
    while(!(p == -1&&e == -1&&i == -1&& d == -1)){//�ж��Ƿ�Ϊ�˳�����
         p %= 23;e %= 28;i %= 33;
         /*���й�ʣ�ඨ�������Ҫ�Ľ��*/
         /*����5544��23��1,14421��28��1,1288��33��1*/
         result = (5544 * p + 14421 * e + 1288 * i - d + 21252) % 21252;
         if( result == 0 ) result = 21252;
         printf( "Case %d: the next triple peak occurs in %d days.\n" , count , result  );
         count ++;
         scanf( "%d%d%d%d" , &p , &e , &i , &d );
    }
    return 0;
}
