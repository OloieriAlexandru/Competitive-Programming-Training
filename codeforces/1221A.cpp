#include <bits/stdc++.h>
using namespace std;
int t, n, x;
map<int,int>mp;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        mp.clear();
        int p2 = 1;
        while (p2 <= 2048)
        {
            mp[p2] = 0;
            p2 *= 2;
        }
        for (int i=1;i<=n;++i)
        {
            cin>>x;
            ++mp[x];
        }
        for (auto x:mp)
        {
            if (x.second >= 2)
                mp[x.first*2] += x.second/2;
            if (x.first == 2048) break;
        }
        if (mp[2048] > 0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
