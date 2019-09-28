#include <bits/stdc++.h>
#define lld long long
#define pii pair<lld,lld>
#define mp make_pair
#define pb push_back
#define inf 9223372036854775807LL
using namespace std;
vector<pii>v;
int n, x, y;
lld ans = inf;
lld s(pii a, pii b, pii c)
{
    //cout<<"test\n";
    return a.first * b.second + b.first * c.second + c.first * a.second
        - b.second * c.first - c.second * a.first - a.second * b.first;
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        scanf("%d %d",&x,&y);
        v.pb(mp(x,y));
    }
    v.pb(v[0]);
    v.pb(v[1]);
    for (int i=0;i<v.size()-2;++i)
    {
        lld ss = s(v[i],v[i+1],v[i+2]);
        if (ss < ans)
            ans = ss;
    }
    cout<<ans<<'\n';
    return 0;
}
