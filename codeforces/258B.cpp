#include <bits/stdc++.h>
#define lld long long
using namespace std;
lld n, ans;
int main()
{
    cin>>n;
    for (int i=1;i<=n-1;++i)
        ans += (n-i)*i;
    ans += n;
    cout<<ans<<'\n';
    return 0;
}
