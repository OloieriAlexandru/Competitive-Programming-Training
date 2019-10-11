#include <bits/stdc++.h>
#define lld long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
using namespace std;
int t, n, x, y;
lld ans;
unordered_map<int,int>mp1;
unordered_map<int,int>mp2;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        mp1.clear();
        mp2.clear();
        ans = 0;
        for (int i=1;i<=n;++i)
        {
            scanf("%d %d",&x,&y);
            ans += mp2[x];
            ans += mp1[y];
            ++mp2[y];
            ++mp1[x];
        }
        cout<<ans<<'\n';
    }
    return 0;
}
