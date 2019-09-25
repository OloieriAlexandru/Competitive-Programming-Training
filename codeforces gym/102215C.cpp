#include <bits/stdc++.h>
#define lld long long
#define nmax 20000005
using namespace std;
bool used[nmax];
int p, ans = 1;
lld n, cnt, nw;
int main()
{
    cin>>p>>n;
    used[0] = 1;
    cnt = min(2LL*p, n);
    for (int i=0;i<=cnt;++i)
    {
        nw = (1LL*i*(i+1)/2)%p;
        if (!used[nw])
        {
            used[nw] = 1;
            ++ans;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
