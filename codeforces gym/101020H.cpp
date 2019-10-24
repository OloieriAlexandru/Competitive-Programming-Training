#include <bits/stdc++.h>
#define inf 999999999
#define nmax 105
using namespace std;
int n, m, f, x, y, d, roy[nmax][nmax], a[15], sol[15], ans;
bool uz[15];
void gen(int k)
{
    if (k - 1 == f)
    {
        int act = 0;
        for (int i=0;i<=f;++i){
            act += roy[sol[i]][sol[i+1]];
        }
        ans = min(ans, act);
        return;
    }
    for (int i=1;i<=f;++i)
    {
        if (uz[i]) continue;
        uz[i] = true;
        sol[k] = a[i];
        gen(k+1);
        uz[i] = false;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for (int tt = 1; tt <= t; ++tt)
    {
        scanf("%d %d %d",&n,&m,&f);
        for (int i=1; i<=n; ++i)
            for (int j=1; j<=n; ++j)
            {
                if (i == j)
                    roy[i][j] = 0;
                else
                    roy[i][j] = inf;
            }
        for (int i=1; i<=m; ++i)
        {
            scanf("%d %d %d",&x,&y,&d);
            roy[x][y] = roy[y][x] = d;
        }
        for (int k=1; k<=n; ++k)
            for (int i=1; i<=n; ++i)
                for (int j=1; j<=n; ++j)
                    if (roy[i][j] > roy[i][k] + roy[k][j])
                        roy[i][j] = roy[i][k] + roy[k][j];
        for (int i=1; i<=f; ++i)
            scanf("%d",&a[i]);
        ans = inf;
        sol[0] = 1;
        sol[f+1] = n;
        gen(1);
        printf("Case %d: %d\n", tt, ans);
    }
    return 0;
}
