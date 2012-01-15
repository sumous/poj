#include <iostream>
#include <string.h>
using namespace std;
long d[1501];
const int factor[] = {2, 3, 5};
int main()
{
    memset(d, -1, sizeof(d));
    d[1] = 1;
    int n;
    for(int i = 2;i <= 1500;i ++)
    {
        int next = 2139062143;
        for(int j = i-1;j >= 1;j --)
        {
            //if(d[j]*5<d[i-1]) break;
            for(int k = 0;k < 3;k ++)
            {
                int f = factor[k]*d[j];
                if(f > d[i-1] && f < next) next = f;
            }
        }
        d[i] = next;
    }
    while(cin>>n && n)
    {
        cout<<d[n]<<endl;
    }
}
