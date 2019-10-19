#include <bits/stdc++.h>
using namespace std;
int t, h, w, d, endd, cnt, v;
int main()
{
    freopen("evil.in","r",stdin);
    cin>>t;
    while(t--)
    {
        cin>>h>>w>>d;
        v = 2 * w - 2;
        cnt = h % v;
        if (!cnt) endd = 2;
        else if (cnt>w)
            endd = 2 * w - cnt;
        else endd = cnt;
        if (endd == d)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}
