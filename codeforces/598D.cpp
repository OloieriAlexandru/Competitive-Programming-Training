#include <bits/stdc++.h>
#define nmax 1005
using namespace std;
int n, em, q, act, ans[nmax*nmax];
bool m[nmax][nmax];
int cc[nmax][nmax], x, y;
int dl[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
char ch;
bool interior(int i, int j)
{
    return i>=1&&j>=1&&i<=n&&j<=em;
}
void dfs(int i, int j)
{
    m[i][j] = 1;
    cc[i][j] = act;
    for (int k=0;k<4;++k)
    {
        if (!interior(i+dl[k], j+dc[k])) continue;
        if (m[i+dl[k]][j+dc[k]] == 1 && !cc[i+dl[k]][j+dc[k]])
            ++ans[act];
        if (m[i+dl[k]][j+dc[k]] == 0)
            dfs(i+dl[k], j+dc[k]);
    }
}
int main()
{
    cin>>n>>em>>q;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=em;++j)
    {
        cin>>ch;
        if (ch == '*')
            m[i][j] = 1;
    }
    for (int i=1;i<=n;++i)
        for (int j=1;j<=em;++j)
        {
            if (m[i][j]) continue;
            ++act;
            dfs(i, j);
        }
    for (int i=1;i<=q;++i)
    {
        cin>>x>>y;
        cout<<ans[cc[x][y]]<<'\n';
    }
    return 0;
}
