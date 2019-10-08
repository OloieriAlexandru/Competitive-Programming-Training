#include <bits/stdc++.h>
#define nmax 200005
using namespace std;
int t, ln;
string s[2];
bool can[2][nmax];
bool dfs(int k, int v)
{
    if (k == ln && v == 1) return true;
    if (k == ln) return false;
    if (!can[v][k]) return false;
    bool res = false;
    if (s[!v][k]>'2' && s[v][k]>'2') res |= dfs(k+1, !v);
    else res |= dfs(k+1,v);
    return res;
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>ln;
        cin>>s[0]>>s[1];
        for (int i=0;i<ln;++i)
        {
            if (s[0][i] <= '2')
                can[0][i] = true;
            if (s[1][i] <= '2')
                can[1][i] = true;
            if (s[0][i] > '2' && s[1][i] > '2')
                can[0][i] = can[1][i] = true;
        }
        if (dfs(0,0))
            printf("YES\n");
        else
            printf("NO\n");
        for (int i=0;i<ln;++i)
            can[0][i] = can[1][i] = false;
    }
    return 0;
}
