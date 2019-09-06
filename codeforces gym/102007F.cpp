#include <bits/stdc++.h>
#define lld long long
#define INF 1000000000000LL
using namespace std;
vector<pair<int,pair<int,int>>>v;
int n, m, p, c, lastDay, need;
lld profit, days, oldDays, prof, lastProfit;
int main()
{
    scanf("%d %d",&n,&need);
    for (int i=1;i<=n;++i)
    {
        scanf("%d %d",&p,&c);
        int castig;
        if (p > c)
            castig = p-c;
        else
            castig = (c % p == 0 ? 0 : p-c%p);
        v.push_back(make_pair(c/p + (c%p ?1:0), make_pair(p, castig)));
    }
    sort(v.begin(), v.end());
    lastDay = v[0].first;
    //for (auto x:v)
    //    cout<<x.first<<' '<<x.second.first<<' '<<x.second.second<<'\n';
    for (int i=0;i<v.size();++i)
    {
        int day = v[i].first;
        oldDays = days;
        while (i < v.size() && v[i].first == day)
        {
            profit += v[i].second.second;
            days += v[i].second.first;
            ++i;
        }
        --i;
        profit += (v[i].first-lastDay) * oldDays;
        if (profit >= need)
        {
            // sigur v[i].first este un raspuns
            if (v[i].first - lastDay == 1)
            {
                cout<<v[i].first<<'\n';
                return 0;
            }
            int st = lastDay + 1;
            int scad = lastDay + 1;
            int ans = v[i].first;
            int dr = v[i].first;
            while (st <= dr)
            {
                int m = (st + dr)/2;
                prof = lastProfit + 1LL * (m - scad+1) * oldDays;
                if (prof >= need)
                {
                    ans = min(ans, m);
                    dr = m-1;
                }
                else st = m+1;
            }
            cout<<ans<<'\n';
            return 0;
        }
        lastDay = day;
        lastProfit = profit;
        oldDays = days;
    }
    lld st = lastDay + 1;
    lld dr = INF;
    lld ans = INF;
    lld scad = lastDay + 1;
    while (st<=dr)
    {
        lld m = (st + dr) / 2;
        prof = lastProfit + 1LL * (m-scad+1) * oldDays;
        if (prof >= need)
        {
            ans = min(ans, m);
            dr=m-1;
        }
        else st = m+1;
    }
    cout<<ans<<'\n';
    return 0;
}
