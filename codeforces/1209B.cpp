#include <bits/stdc++.h>
#define nm 1000005
using namespace std;
int cnt[nm+1], n, a, b, nxt, ans;
string init;
int main()
{
    cin>>n;
    cin>>init;
    for (int i=1; i<=n; ++i)
    {
        cin>>a>>b;
        int j = 0;
        if (init[i-1] == '1')
        {
            while (j<b)
                ++cnt[j++];
            nxt = b+a;
        }
        else
        nxt = b;
        bool on = false;
        while (j <= nm)
        {
            if (j == nxt) on = !on, nxt += a;
            if (on)
                ++cnt[j++];
            else
                ++j;
        }
    }
    for (int i=0; i<=nm; ++i)
        ans = max(ans, cnt[i]);
    cout<<ans<<'\n';
    return 0;
}
