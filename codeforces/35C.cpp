#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define nmax 2005
using namespace std;
int dl[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
queue<pii>q;
int dmin[nmax][nmax], n, m, nr, x, y, maxx;
bool uz[nmax][nmax];
bool interior(int i, int j)
{
    return i>=1&&j>=1&&i<=n&&j<=m;
}
void lee()
{
    while (!q.empty())
    {
        auto act = q.front();
        q.pop();
        int i = act.first;
        int j = act.second;
        for (int k=0;k<4;++k)
        {
            if (!interior(i+dl[k], j+dc[k])) continue;
            if (uz[i+dl[k]][j+dc[k]]) continue;
            dmin[i+dl[k]][j+dc[k]] = dmin[i][j] + 1;
            q.push(mp(i+dl[k], j+dc[k]));
            uz[i+dl[k]][j+dc[k]] = true;
        }
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n>>m;
    cin>>nr;
    for (int i=1; i<=nr; ++i)
    {
        cin>>x>>y;
        q.push(mp(x,y));
        uz[x][y] = true;
    }
    lee();
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            maxx = max(maxx, dmin[i][j]);
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            if (maxx == dmin[i][j])
            {
                cout<<i<<' '<<j<<'\n';
                return 0;
            }
    return 0;
}
