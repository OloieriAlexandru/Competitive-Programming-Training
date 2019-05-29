#include <bits/stdc++.h>
#define nmax 105
#define pii pair<int,int>
#define mp make_pair
using namespace std;
int a[nmax][nmax], n, m;
int water[nmax][nmax], mat[nmax][nmax];
int x1, x2, maxim;
int y1, y2;
int dl[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
bool interior(int x, int y)
{
    return x>=1&&x<=n&&y>=1&&y<=m;
}
void LEE(int mat[][nmax], int x, int y)
{
    queue<pair<int,pii>>q;
    q.push(mp(1,mp(x,y)));
    mat[x][y] = 1;
    while (!q.empty())
    {
        auto act = q.front();
        q.pop();
        for (int i=0; i<4; ++i)
        {
            int nx = act.second.first + dl[i];
            int ny = act.second.second + dc[i];
            if (!interior(nx, ny)) continue;
            if (!mat[nx][ny] && a[nx][ny]<=a[act.second.first][act.second.second])
            {
                mat[nx][ny] = act.first + 1;
                q.push(mp(act.first+1,mp(nx,ny)));
            }
        }
    }
}
bool ok(int jump)
{
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            mat[i][j] = 0;
    queue<pair<int,pii>>q;
    q.push(mp(1,mp(x1,y1)));
    while (!q.empty())
    {
        auto act = q.front();
        q.pop();
        if (!water[act.second.first][act.second.second])
            return true;
        if (water[act.second.first][act.second.second]<=mat[act.second.first][act.second.second])
            continue;
        for (int i=0;i<4;++i)
        {
            int nx = act.second.first + dl[i];
            int ny = act.second.second + dc[i];
            if (!interior(nx, ny)) continue;
            if (!mat[nx][ny] && a[nx][ny]<=(a[act.second.first][act.second.second]+jump))
            {
                mat[nx][ny] = act.first + 1;
                q.push(mp(act.first+1,mp(nx,ny)));
            }
        }
    }
    return false;
}
int main()
{
    scanf("%d %d",&n,&m);
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
        {
            scanf("%d",&a[i][j]);
            maxim = max(maxim, a[i][j]);
        }
    scanf("%d %d",&x1,&y1);
    scanf("%d %d",&x2,&y2);
    LEE(water, x2, y2);
    /*for (int i=1; i<=n; ++i)
    {
        for (int j=1; j<=m; ++j)
            printf("%d ", water[i][j]);
        printf("\n");
    }*/
    int ans = maxim+1;
    int st = 0, dr = maxim;
    while(st<=dr)
    {
        int mid = (st+dr)/2;
        if (ok(mid))
            ans = min(ans, mid),
            dr = mid-1;
        else
            st = mid+1;
    }
    if(ans == maxim+1)
        ans = -1;
    printf("%d\n", ans);
    return 0;
}