#include<stdio.h>
int main()
{

   int p , i , e , d , count = 1,result;
    /*计算出每个数被其余两个数乘积整除余1的数*/
    /*for( p1 = 33*28;p1 % 23 != 1;p1 += 33*28 );
    for( e1 = 33*23;e1 % 28 != 1;e1 += 33*23 );
    for( i1 = 23*28;i1 % 33 != 1;i1 += 28*23 );  */

    scanf( "%d%d%d%d" , &p , &e , &i , &d );
    while(!(p == -1&&e == -1&&i == -1&& d == -1)){//判断是否为退出条件
         p %= 23;e %= 28;i %= 33;
         /*用中国剩余定理计算需要的结果*/
         /*其中5544除23余1,14421除28余1,1288除33余1*/
         result = (5544 * p + 14421 * e + 1288 * i - d + 21252) % 21252;
         if( result == 0 ) result = 21252;
         printf( "Case %d: the next triple peak occurs in %d days.\n" , count , result  );
         count ++;
         scanf( "%d%d%d%d" , &p , &e , &i , &d );
    }
    return 0;
}
