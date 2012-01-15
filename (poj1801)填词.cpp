#include<stdio.h>

int main()
{   
	int dic[26]={0};
	int M , N , P , i , j;
	char ch;
	scanf( "%d%d%d" , &N , &M , &P);
	getchar(); 
	for( i = 0;i < N;i ++){//输入方格数据并令static对应字母加1 
		for(  j=0;j < M;j ++){
			ch = getchar();
			dic[ch - 'A'] ++;
		} 
		getchar();
	}
	for( i = 0;i < P;i ++ ){//输入待查找数据并令static对应字母减1 
		ch = getchar();
		while(ch != '\n'){
			dic[ch - 'A'] --;
			ch = getchar();
		}
	}
    for( i = 0;i < 26;i ++){//输出未被访问过的数据 
		for( j = 0;j < dic[i];j ++ ){
			printf( "%c" , i+'A');
		} 
	}
	return 0;
}