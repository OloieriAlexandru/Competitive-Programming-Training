#include <bits/stdc++.h>
#define nmax 120005
#define lld long long
using namespace std;
set<int>addedToSet;
unordered_map<int,int>mp;
int n, a[nmax], ans;
lld pow2[33], nec;
int main()
{
    pow2[0] = 1;
    for (int i=1;i<=32;++i)
        pow2[i] = pow2[i-1] * 2;
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        ++mp[a[i]];
    }
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=32;++j)
        {
            nec = pow2[j] - a[i];
            if (nec <= 0)
                continue;
            if (nec == a[i])
            {
                if (mp[nec] > 1)
                {
                    addedToSet.insert(a[i]);
                }
            }
            else
            {
                if (mp.count(nec))
                {
                    addedToSet.insert(nec);
                    addedToSet.insert(a[i]);
                }
            }
        }
    }
    for (int i=1;i<=n;++i)
        if (!addedToSet.count(a[i]))
            ++ans;
    cout<<ans<<'\n';
    return 0;
}
