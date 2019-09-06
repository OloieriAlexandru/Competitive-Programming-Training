#include <bits/stdc++.h>
#define lld long long
using namespace std;
int t;
lld st, in, ex, ans, dif;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>st>>in>>ex;
        if (st+ex <= in)
        {
            cout<<"0\n";
            continue;
        }
        dif = ex-st+in;
        if (dif < 0) ans = 0;
        else ans = dif / 2 + 1;
        ans = ex - ans + 1;
        cout<<ans<<'\n';
    }
    return 0;
}
