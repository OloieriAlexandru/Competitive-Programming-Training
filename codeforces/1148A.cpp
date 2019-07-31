#include <bits/stdc++.h>
#define lld long long
using namespace std;
lld a, b, ab, ans;
int main()
{
    cin>>a>>b>>ab;
    if (!ab)
    {
        ans = min(a,b)*2;
        if (a != b) ++ans;
        cout<<ans<<'\n';
    }
    else
    {
        ans = 2 * ab;
        lld v1, v2;
        // pun in dreapta
        v1 = ans + 2 * min(a,b);
        if (a > b) ++v1;
        v2 = ans + 2 * min(a,b);
        if (b > a) ++v2;
        ans = max(v1, v2);
        cout<<ans<<'\n';
    }
    return 0;
}
