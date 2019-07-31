#include <bits/stdc++.h>
#define nmax 200005
using namespace std;
int cnt[nmax], sum, n, m, d, t, req[nmax];
vector<int>tranzactions[nmax];
vector<int>availableTypes[2*nmax];
bool ok(int tim)
{
    for (int i=1;i<=n;++i)
    {
        if (!tranzactions[i].size()) continue;
        int st = 0, dr = tranzactions[i].size() - 1;
        while (st <= dr)
        {
            int mid = (st + dr)/2;
            if (tranzactions[i][mid] > tim)
                dr = mid - 1;
            else
                st = mid + 1;
        }
        --st;
        if (st < 0 || tranzactions[i][st] > tim) continue;
        availableTypes[tranzactions[i][st]].push_back(i);
    }
    for (int i=1;i<=n;++i)
        req[i] = cnt[i];
    int avail = 0, buy;
    for (int i=1;i<=tim;++i)
    {
        ++avail;
        if (!availableTypes[i].size()) continue;
        for (int j=0;j<availableTypes[i].size();++j)
        {
            buy = availableTypes[i][j];
            if (req[buy] <= avail)
            {
                // le cumpar pe toate de tipul asta
                avail -= req[buy];
                req[buy] = 0;
            }
            else
            {
                req[buy] -= avail;
                avail = 0;
                break;
            }
        }
    }
    buy = 0;
    for (int i=1;i<=n;++i)
    {
        buy += req[i];
    }
    for (int i=1;i<=tim;++i)
        availableTypes[i].clear();
    return avail >= 2 * buy;
}
int main()
{
    scanf("%d %d",&n,&m);
    for (int i=1; i<=n; ++i)
    {
        cin>>cnt[i];
        sum += cnt[i];
    }
    for (int i=1; i<=m; ++i)
    {
        scanf("%d %d",&d,&t);
        tranzactions[t].push_back(d);
    }
    for (int i=1; i<=n; ++i)
        sort(tranzactions[i].begin(), tranzactions[i].end());
    int st = 1, dr = 2*sum, ans = 2*sum;
    while(st<=dr)
    {
        int m = (st + dr) / 2;
        if (ok(m))
        {
            ans = min(ans, m);
            dr = m - 1;
        }
        else
            st = m + 1;
    }
    cout<<ans<<'\n';
    return 0;
}
