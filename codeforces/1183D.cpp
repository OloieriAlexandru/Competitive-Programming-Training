#include <bits/stdc++.h>
#define nmax 200005
using namespace std;
int t, n, lst, x;
long long ans;
map<int,int>mp;
vector<int>act;
int main()
{
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        mp.clear();
        act.clear();
        ans = 0;
        for (int i=1; i<=n; ++i)
        {
            scanf("%d",&x);
            ++mp[x];
        }
        for (auto x:mp)
            act.push_back(x.second);
        sort(act.begin(), act.end(), [](int a, int b)
        {
            return a > b;
        });
        lst = act[0] + 1;
        for (int i=0;i<act.size();++i)
        {
            if (!lst) break;
            if (act[i] >= lst)
                ans += lst, --lst;
            else
                ans += act[i], lst = act[i] - 1;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
