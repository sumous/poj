#include<stdio.h>

int main()
{   
	int dic[26]={0};
	int M , N , P , i , j;
	char ch;
	scanf( "%d%d%d" , &N , &M , &P);
	getchar(); 
	for( i = 0;i < N;i ++){//���뷽�����ݲ���static��Ӧ��ĸ��1 
		for(  j=0;j < M;j ++){
			ch = getchar();
			dic[ch - 'A'] ++;
		} 
		getchar();
	}
	for( i = 0;i < P;i ++ ){//������������ݲ���static��Ӧ��ĸ��1 
		ch = getchar();
		while(ch != '\n'){
			dic[ch - 'A'] --;
			ch = getchar();
		}
	}
    for( i = 0;i < 26;i ++){//���δ�����ʹ������� 
		for( j = 0;j < dic[i];j ++ ){
			printf( "%c" , i+'A');
		} 
	}
	return 0;
}