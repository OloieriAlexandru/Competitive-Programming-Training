#include <bits/stdc++.h>
#define nmax 100005
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define lld long long
using namespace std;
vector<pii>g[nmax];
vector<int>sumXor;
int currentXorSum;
int n, x, y, c;
void dfs(int k, int lst)
{
    for (auto x:g[k])
    {
        if (x.first == lst)
        {
            continue;
        }
        currentXorSum ^= x.second;
        dfs(x.first, k);
        currentXorSum ^= x.second;
    }
    sumXor.pb(currentXorSum);
}
int main()
{
    scanf("%d",&n);
    for (int i=1; i<n; ++i)
    {
        scanf("%d %d %d",&x,&y,&c);
        g[x].pb(mp(y,c));
        g[y].pb(mp(x,c));
    }
    dfs(1,-1);
    lld ans = 0;
    for (int i=0; i<30; ++i)
    {
        int cnt = 0;
        for (auto x:sumXor)
            if (x & (1<<i))
                ++cnt;
        ans += ((1LL<<i)*cnt*(sumXor.size()-cnt));
    }
    cout<<ans<<'\n';
    return 0;
}
