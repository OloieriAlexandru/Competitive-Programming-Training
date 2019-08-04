#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
int n, m, l, r, k;
vector<pii>v, ans;
bool cmp(pii a, pii b)
{
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}
int main()
{
    scanf("%d %d",&n,&k);
    for (int i=1;i<=n;++i)
    {
        scanf("%d %d",&l,&r);
        v.push_back(mp(l,1));
        v.push_back(mp(r,-1));
    }
    sort(v.begin(), v.end(), cmp);
    int act = 0, lst = 0, l;
    for (int i=0;i<v.size();++i)
    {
        act += v[i].second;
        if (act == k && lst == k-1)
            l = v[i].first;
        if (act == k-1 && lst == k)
            ans.push_back(mp(l,v[i].first));
        lst = act;
    }
    cout<<ans.size()<<'\n';
    sort(ans.begin(), ans.end());
    for (auto x:ans)
        cout<<x.first<<' '<<x.second<<'\n';
    return 0;
}
