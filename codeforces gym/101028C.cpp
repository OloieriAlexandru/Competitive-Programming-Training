#include <bits/stdc++.h>
#define mod 1000000007
#define lld long long
using namespace std;
int t, n;
string s1, s2;
lld ans = 1;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>s1>>s2;
        bool ok = true;
        ans = 1;
        for (int i=0;i<n;++i)
        {
            if (s1[i] == '1' && s2[i] == '1')
                ans = (ans * 2) % mod;
            if (s1[i] == '1' && s2[i] == '0')
            {
                ok = false;
                break;
            }
        }
        if (ok)
            cout<<ans<<'\n';
        else
            cout<<"IMPOSSIBLE\n";
    }
    return 0;
}
