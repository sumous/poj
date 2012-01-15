#include <iostream>
#include <set>
using namespace std;
int main()
{
    long long d[1501];
    set <long long> a;
    a.insert(1);
//    cout<<a.begin();
    for(int i = 1;i <= 1500;i ++)
    {
        d[i] = *a.begin();
        a.erase(a.begin());
        a.insert(d[i]*2);
        a.insert(d[i]*3);
        a.insert(d[i]*5);
    }
    int n;
    while(cin>>n && n)
        cout<<d[n]<<endl;
    return 0;
}
