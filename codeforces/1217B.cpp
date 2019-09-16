#include <bits/stdc++.h>
#define nmax 105
#define mp make_pair
#define pb push_back
#define lld long long
#define inf 1000000005
using namespace std;
int n, x, y, hp;
int maxx[nmax];
vector<pair<int,int>>v;
bool cmp(pair<int,int> a, pair<int,int>b)
{
    int d1 = a.first - a.second;
    int d2 = b.first - b.second;
    return d1 > d2;
}
int main()
{
    //freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>hp;
        v.clear();
        for (int i=1; i<=n; ++i)
        {
            cin>>x>>y;
            v.pb(mp(x,y));
        }
        sort(v.begin(), v.end(), cmp);
        maxx[n-1] = v[n-1].first;
        maxx[n] = 0;
        for (int i=n-2; i>=0; --i)
            maxx[i] = max(maxx[i+1], v[i].first);
        lld ans = -1;
        int difMax = v[0].first - v[0].second;
        if (difMax <= 0 && maxx[0] < hp)
        {
            cout<<ans<<'\n';
            continue;
        }
        lld st = 1, dr = inf;
        while (st <= dr)
        {
            lld m = (st + dr) / 2;
            lld cm = m-1;
            lld sc = cm * difMax + maxx[0];
            if (sc >= hp)
            {
                ans = m;
                dr = m-1;
            }
            else st = m + 1;
        }
        if (hp <= maxx[0])
            ans = 1;
        cout<<ans<<'\n';
    }
    return 0;
}
