#include <bits/stdc++.h>
#define inf 999999999
#define lld long long
using namespace std;
lld ans = inf, n;
int main()
{
    cin>>n;
    for (lld i=1;i*i<=n;++i){
        if (n % i) continue;
        ans = min(ans, 2*(i+(n/i)));
    }
    cout<<ans<<'\n';
    return 0;
}
