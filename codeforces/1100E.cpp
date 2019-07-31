#include <bits/stdc++.h>
#define nmax 100005
using namespace std;
int n, m;
pair<pair<int,int>,int>control[nmax];
vector<int>g[nmax], anss;
int di[nmax], poz[nmax], pozans[nmax], ans = 1000999999;
bool ok(int k)
{
    for (int i=1;i<=n;++i)
        g[i].clear(), di[i] = 0;
    for (int i=1;i<=m;++i)
        if (control[i].second > k)
            ++di[control[i].first.second], g[control[i].first.first].push_back(control[i].first.second);
    queue<int>q;
    int pz = 0;
    for (int i=1;i<=n;++i)
        if (di[i] == 0)
            q.push(i);
    while (!q.empty())
    {
        auto act = q.front();
        q.pop();
        ++pz;
        poz[act] = pz;
        for (auto x:g[act])
        {
            --di[x];
            if (di[x] == 0)
                q.push(x);
        }
    }
    if (pz < n)
        return false;
    return true;
}
int main()
{
    scanf("%d %d",&n,&m);
    for (int i=1;i<=m;++i)
        scanf("%d %d %d",&control[i].first.first, &control[i].first.second, &control[i].second);
    int st = 0, dr = 1000999999;
    while (st <= dr)
    {
        int mid = (st + dr) / 2;
        if (ok(mid))
        {
            ans = min(ans, mid);
            for (int i=1;i<=n;++i)
                pozans[i] = poz[i];
            dr = mid - 1;
        }
        else
            st = mid + 1;
    }
    for (int i=1;i<=m;++i)
        if (pozans[control[i].first.first] > pozans[control[i].first.second])
            anss.push_back(i);
    cout<<ans<<' '<<anss.size()<<'\n';
    for (auto x:anss)
        cout<<x<<' ';
    cout<<'\n';
    return 0;
}
