#include <bits/stdc++.h>
#define lld long long
using namespace std;
lld a, b, c, ans;
int main()
{
    cin>>a>>b>>c;
    ans = a/3 + b/3 + c/3;
    --a,--b,--c;
    if (a >= 0 && b >=0 && c >=0)
        ans = max(ans, a/3 + b/3 + c/3 + 1);
    --a, --b, --c;
    if (a >= 0 && b >=0 && c >=0)
        ans = max(ans,a/3 + b/3 + c/3 + 2);
    --a, --b, --c;
    if (a >= 0 && b >=0 && c >=0)
        ans = max(ans,a/3 + b/3 + c/3 + 3);
    cout<<ans<<'\n';
    return 0;
}
