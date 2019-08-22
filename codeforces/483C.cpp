#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, st = 1, af = 0,dr;
    cin>>n>>k;
    if (k == 1)
    {
        for (int i=1;i<=n;++i)
            cout<<i<<' ';
        return 0;
    }
    dr = n;
    vector<int>ans;
    int ok = 0;
    for (int i=-1; i<k;)
    {
        ans.push_back(st);
        ++af, ++i, ++st;
        if (i == k-1)
        {
            ok = 1;
            break;
        }
        if (af == n) break;
        ans.push_back(dr);
        ++af, ++i, --dr;
        if (i == k-1) break;
        if (af == n) break;
    }
    if (!ok)
    {
        while (dr >= st && af < n)
        {
            ++af;
            ans.push_back(dr);
            --dr;
        }
    }
    else
    {
        while (st <= dr && af < n)
        {
            ++af;
            ans.push_back(st);
            ++st;
        }
    }
    for (auto x:ans)
        cout<<x<<' ';
    cout<<'\n';
    return 0;
}
