#include <bits/stdc++.h>
#define inf 999999999
#define mp make_pair
#define pii pair<int,int>
#define nmax 105
using namespace std;
int n, m, ans = inf, d, dist[3][nmax][nmax];
char a[nmax][nmax];
deque<pair<int,pii>>q;
int dl[] = {-1,-1,0,1,1,1,0,-1};
int dc[] = {0,1,1,1,0,-1,-1,-1};
pair<int,pii>act;
int x1, x2, x3, x;
int y1, y2, y3, y;
bool viz[nmax][nmax];
vector<pii>tlp[26];
bool interior(int i, int j)
{
    return i>=1 && i<=n && j>=1 && j<=m;
}
void lee(int mat[nmax][nmax], int x, int y)
{
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            mat[i][j] = -1, viz[i][j] = false;
    q.push_back(mp(0,mp(x,y)));
    viz[x][y] = true;
    mat[x][y] = 0;
    while (!q.empty())
    {
        act = q.front();
        q.pop_front();
        x = act.second.first;
        y = act.second.second;
        d = act.first;
        if (a[x][y] >= 'A' && a[x][y] <= 'Z')
        {
            for (auto cv : tlp[a[x][y]-'A'])
            {
                if (!viz[cv.first][cv.second])
                {
                    viz[cv.first][cv.second] = true;
                    mat[cv.first][cv.second] = d;
                    q.push_front(mp(d,mp(cv.first,cv.second)));
                }
            }
        }
        for (int i=0;i<8;++i)
        {
            if (!interior(x+dl[i], y+dc[i])) continue;
            if (viz[x+dl[i]][y+dc[i]]) continue;
            if (a[x+dl[i]][y+dc[i]] == '#' || a[x+dl[i]][y+dc[i]] == '*') continue;
            viz[x+dl[i]][y+dc[i]] = true;
            mat[x+dl[i]][y+dc[i]] = d + 1;
            q.push_back(mp(d+1,mp(x+dl[i],y+dc[i])));
        }
    }
}
int main()
{
    cin>>n>>m;
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=m;++j)
        {
            cin>>a[i][j];
            if (a[i][j]>='A' && a[i][j]<='Z')
                tlp[a[i][j]-'A'].push_back(mp(i,j));
            else
            if (a[i][j] == '$')
                x1 = i, y1 = j;
            else
            if (a[i][j] == '!')
                x2 = i, y2 = j;
            else
            if (a[i][j] == '*')
                x3 = i, y3 = j;
        }
    }
    lee(dist[0],x1,y1);
    lee(dist[1],x2,y2);
    lee(dist[2],x3,y3);
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
    {
        if (dist[0][i][j] == -1) continue;
        if (dist[1][i][j] == -1) continue;
        if (dist[2][i][j] == -1) continue;
        d = max(dist[0][i][j],dist[1][i][j]) + dist[2][i][j];
        ans = min(ans, d);
    }
    if (ans == inf)
        cout<<"Impossible\n";
    else
        cout<<ans<<'\n';
    return 0;
}