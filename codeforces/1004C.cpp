#include <bits/stdc++.h>
#define nmax 100000
#define lld long long
using namespace std;
int difst[nmax], difdr[nmax], n, a[nmax];
bool cnt[nmax];
lld ans;
set<int>dif;
int main()
{
    cin>>n;
    for (int i=1; i<=n; ++i)
        cin>>a[i];
    for (int i=1; i<=n; ++i)
    {
        if (!dif.count(a[i]))
            cnt[i] = true;
        dif.insert(a[i]);
        difst[i] = dif.size();
    }
    dif.clear();
    for (int i=n; i>=1; --i)
    {
        dif.insert(a[i]);
        difdr[i] = dif.size();
    }
    for (int i=1; i<=n; ++i)
        if (cnt[i])
            ans += 1LL * difdr[i+1];
    cout<<ans<<'\n';
    return 0;
}
