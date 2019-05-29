#include <bits/stdc++.h>
#define nmax 50005
using namespace std;
vector<int>g[nmax];
int st[nmax], dr[nmax];
int n, m, p, x, ans, y;
bool viz[nmax];
bool cup(int nod)
{
    if (viz[nod]) return false;
    viz[nod] = true;
    for (auto x:g[nod])
    {
        if (!dr[x])
        {
            dr[x] = nod;
            st[nod] = x;
            return true;
        }
    }
    for (auto x:g[nod])
    {
        if (cup(dr[x]))
        {
            dr[x] = nod;
            st[nod] = x;
            return true;
        }
    }
    return false;
}
int main()
{
    scanf("%d %d %d",&n,&m,&p);
    for (int i=1;i<=p;++i)
    {
        scanf("%d %d",&x,&y);
        g[x].push_back(y);
    }
    bool ok = true;
    while(ok)
    {
        memset(viz, 0, sizeof(viz));
        ok = false;
        for (int i=1;i<=n;++i)
            if (!viz[i] && !st[i])
                if (cup(i))
                    ok = true;
    }
    for (int i=1;i<=n;++i)
        if (st[i])++ans;
    cout<<ans<<'\n';
    return 0;
}
