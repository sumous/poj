/**
 * the longest common substring
 * 最长相同序列
 * 动态规划,c[i][j]表示X[1..i],Y[1..j]的最长相同序列
 * c[i][j] = max(c[i-1][j-1]+1, c[i-1][j], c[i][j-1]);
 */
# include <iostream>
# include <cstring>
# include <cstdio>
# define LEN 105
using namespace std;
const int dx[] = {-1, -1, 0}, dy[] = {-1, 0, -1};
int  XL, YL;
char X[LEN][35], Y[LEN][35];
int c[LEN][LEN], b[LEN][LEN];

bool same(char* a, char* b)
{
    if (strcmp(a, b) == 0) return true;
    else return false;
}
void LCS_length()
{
    memset(c, 0 ,sizeof(c));
    for (int i = 1; i <= XL; i++)
        for (int j = 1; j <= YL; j++)
        {
            if (same(X[i], Y[j]))
            {
                
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 0;
            }
            else
            {
                if (c[i-1][j] >= c[i][j-1])
                {
                    c[i][j] = c[i-1][j];
                    b[i][j] = 1;
                }
                else
                {
                    c[i][j] = c[i][j-1];
                    b[i][j] = 2;
                }
            }
            
        }
}
void print_lcs(int i, int j)
{
    if (i == 0 || j == 0)
        return; 
    if (b[i][j] == 0)
    {
        print_lcs(i-1, j-1);
        cout<<X[i];
        if (i == XL || j == YL)
            cout<<endl;
        else cout<<" ";
    }
    else print_lcs(i+dx[ b[i][j] ], j+dy[ b[i][j] ]);
}

int main()
{
    freopen("data", "r", stdin);
    char word[35];
    while(cin >> word)
    {
        XL = YL = 1;
        while(word[0] != '#')
        {
            strcpy(X[XL], word);
            X[XL][strlen(word)] = '\0';
            XL++;
            cin >> word;
        }
       
        while(cin >> word && word[0] != '#')
        {
            strcpy(Y[YL], word);
            Y[YL][strlen(word)] = '\0';
            YL++;
        }

        LCS_length();

        print_lcs(XL, YL);
    }
    return 0;
}
