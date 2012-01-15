//北大POJ1003题：卡片题目 
#include<stdio.h>
int main()
{
	double i; 	//定义成double类型-->转换成int类型 
	double b;  //待输入的值 
    double sum; //计算总和结果
    int k;
	while(scanf("%lf",&b)!=EOF && b!=0){
       //计算完一次后sum重新设定为0 
       for(sum = 0,i = 2;;i++){
          sum = sum +1/i;
          if(sum>b) break;  //如果判断sum大于输入的b值跳出当前for循环 
       }                      
       //此时卡片数为i-1  
       k = i-1;                
       printf("%d card(s)\n",k);
     }
	return 0;
}
