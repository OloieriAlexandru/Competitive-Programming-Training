#include <bits/stdc++.h>
#define nmax 2005
using namespace std;
unordered_map<int,int>fv;
int a[nmax], n, ans;
unordered_map<int,int>currfv;
bool good()
{
    for (auto x:fv)
        if (currfv.count(x.first))
        {
            if (x.second - currfv[x.first] > 1) return false;
        }
        else
        if (x.second > 1) return false;
    return true;
}
bool ok(int x)
{
    currfv.clear();
    for (int i=1;i<=x;++i)
        ++currfv[a[i]];
    for (int i=x+1;i<=n;++i)
    {
        if (good()) return true;
        --currfv[a[i-x]];
        ++currfv[a[i]];
    }
    return good();
}
int main()
{
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i], ++fv[a[i]];
    int st = 0, dr = n;
    while (st <= dr)
    {
        int m = (st + dr) / 2;
        if (ok(m))
        {
            ans = m;
            dr = m-1;
        } else st = m + 1;
    }
    cout<<ans<<'\n';
    return 0;
}
