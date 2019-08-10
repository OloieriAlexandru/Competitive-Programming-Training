#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
using namespace std;
int n, x, y, ans;
vector<pii>v;
bool cmp(pii a, pii b)
{
    return a.second < b.second;
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        scanf("%d %d",&x,&y);
        v.pb(mp(x,y));
    }
    sort(v.begin(), v.end(), cmp);
    int lst = v[0].second, ans = 1;
    for (int i=1;i<v.size();++i)
    {
        if (v[i].first > lst)
        {
            lst = v[i].second;
            ++ans;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
