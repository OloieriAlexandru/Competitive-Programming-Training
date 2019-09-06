#include <bits/stdc++.h>
#define lld long long
#define INF 999999999999999LL
using namespace std;

int main()
{
    int n;
    cin>>n;
    lld ans = INF;
    lld v1, v2, v3, v4, act;
    for (int i=1;i*i<=n;++i)
    {
        if (n % i) continue;
        v1 = n/i;
        v2 = i;
        if (v1 > v2) swap(v1,v2);
        for (int j=1;j*j<=v1;++j)
        {
            if (v1 % j) continue;
            v3 = v1/j;
            v4 = j;
            act = (v3*v4 + v4*v2 + v2*v3) * 2;
            ans = min(ans, act);
        }
        for (int j=1;j*j<=v2;++j)
        {
            if (v2 % j) continue;
            v3 = v2/j;
            v4 = j;
            act = (v3*v4 + v4*v1 + v1*v3) * 2;
            ans = min(ans, act);
        }
    }
    cout<<ans<<'\n';
    return 0;
}
