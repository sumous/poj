/**
 * 总体来说，是水题，只要懂得使用map就可以了
 */
# include <iostream>
# include <map>
# include <string>
# include <cstring>
# include <cstdio>
using namespace std;
map<string, string > M;
void load()
{
    string s1, s2;
    char ch[25];
    while(gets(ch) != NULL)
    {//cout <<ch <<endl;
        if (ch[0] == '\0') break;
        int len = strlen(ch);
        bool flag = false;
        s1 = s2 = "";
        for (int i = 0; i < len; i++)
        {
            if (ch[i] == ' ')
            {
                flag = true;
                continue;
            }
            if (!flag)
                s1 += ch[i];
            else
                s2 += ch[i];
        }
      
        M[s2] = s1;
    }
}
void out()
{
    char ch[25];
    while(gets(ch) != NULL)
    {
        if (ch[0] == '\0') break;
        if (M[ch] != "")
            cout << M[ch] <<endl;
        else
            cout << "eh" << endl;
    }
}
int main()
{
    freopen("data", "r", stdin);
    load();
    out();
    return 0;
}
