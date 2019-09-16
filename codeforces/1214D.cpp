#include <bits/stdc++.h>
using namespace std;
int n, m;
char x;
vector<vector<char>>v;
vector<vector<bool>>uz;
bool interior(int i, int j)
{
    return i<=n&&j<=m && v[i][j] == '.';
}
bool dfs(int i, int j)
{
    v[i][j] = '#';
    if (i == n && j == m) return true;
    if (interior(i+1,j) && dfs(i+1,j)) return true;
    if (interior(i,j+1) && dfs(i,j+1)) return true;
    return false;
}
int main()
{
    cin>>n>>m;
    v.resize(n+5);
    for (int i=0; i<=n; ++i)
        v[i].resize(m+5);
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
        {
            cin>>x;
            v[i][j] = x;
        }
    dfs(1,1);
    if (v[n][m]=='.')
    {
        cout<<"0\n";
        return 0;
    }
    v[1][1] = v[n][m] = '.';
    dfs(1,1);
    if (v[n][m]=='#')
        cout<<"2\n";
    else
        cout<<"1\n";
    return 0;
}
