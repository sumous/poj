#include<stdio.h>
#include<string.h>
main()
{
    int i , flag[105] = {0} , yes_no = 1;
    char a[105] , ch;
    //memset(flag , 0 , 105);
    gets(a);
    //getchar();
    ch = getchar();
    while(ch != '\n'){
        if(ch == 'Z' ) ch = 'A';
        else ch ++;
        //putchar(ch);
         for( i = 0;i < strlen(a);i ++ ){
            if(ch == a[i]&&flag[i] == 0){
                flag[i] = 1; break;
            }
         }

         ch = getchar();
    }
    for( i = 0;i < strlen(a);i ++ ) {
            if(flag[i] == 0) {yes_no = 0;break;}
         }
    if(yes_no) printf( "YES\n" );
    else printf( "NO\n" );
}
