#include <bits/stdc++.h>
#define nmax 200005
#define lld long long
#define mp make_pair
#define pb push_back
using namespace std;
int sumdr[nmax], a[nmax], b[nmax], n, k;
lld act, ans = 1000000000000000LL;
vector<pair<int,int>>v;
bool cmp(pair<int,int> a, pair<int,int> b)
{
    return a.first - a.second < b.first - b.second;
}
int main()
{
    cin>>n>>k;
    for (int i=1; i<=n; ++i)
        cin>>a[i];
    for (int j=1; j<=n; ++j)
        cin>>b[j];
    for (int i=1; i<=n; ++i)
        v.pb(mp(a[i],b[i]));
    sort(v.begin(), v.end(), cmp);
    for (int i=n-1; i>=0; --i)
        sumdr[i] = sumdr[i+1] + v[i].second;
    for (int i=0; i<k; ++i)
        act += v[i].first;
    for (int i=k; i<n; ++i)
    {
        ans = min(ans, act + sumdr[i]);
        act += v[i].first;
    }
    ans = min(ans, act);
    cout<<ans<<'\n';
    return 0;
}
