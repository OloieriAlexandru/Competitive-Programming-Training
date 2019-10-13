#include <bits/stdc++.h>
#define nmax 505
#define pii pair<int,int>
#define mp make_pair
#define inf 999999999
using namespace std;
int d1[nmax][nmax], d2[nmax][nmax], n, m, nr, x, y;
bool good[nmax][nmax], uz[nmax][nmax];
char mat[nmax][nmax];
int dl[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
bool interior(int i, int j)
{
    return i>=0&&j>=0&&i<n&&j<m;
}
void lee(int x, int y, int d[nmax][nmax], bool g[nmax][nmax])
{
    int i, j;
    memset(uz,0,sizeof(uz));
    queue<pii> q;
    q.push(mp(x,y));
    uz[x][y] = true;
    while (!q.empty())
    {
        auto act = q.front();
        q.pop();
        i = act.first;
        j = act.second;
        for (int k=0; k<4; ++k)
        {
            if (!interior(i+dl[k], j+dc[k])) continue;
            if (mat[i+dl[k]][j+dc[k]] == 'x' && !g[i+dl[k]][j+dc[k]]) continue;
            if (uz[i+dl[k]][j+dc[k]]) continue;
            d[i+dl[k]][j+dc[k]] = d[i][j] + 1;
            uz[i+dl[k]][j+dc[k]] = true;
            q.push(mp(i+dl[k],j+dc[k]));
        }
    }
}
int main()
{
    cin>>n>>m>>nr;
    for (int i=0; i<n; ++i)
        cin>>mat[i];
    d1[n-1][m-1] = d2[n-1][m-1] = inf;
    lee(0,0,d1,good);
    for (int i=1; i<=nr; ++i)
    {
        cin>>x>>y;
        good[x][y] = true;
    }
    lee(0,0,d2,good);
    if (d2[n-1][m-1] + 5< d1[n-1][m-1])
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}
