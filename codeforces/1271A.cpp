#include <bits/stdc++.h>
#define lld long long
using namespace std;

int main()
{
    lld a, b, c, d, e, f, ans = 0;
    cin>>a>>b>>c>>d>>e>>f;
    if (e > f){
        lld mm = min(a, d);
        ans += mm * e;
        a -= mm;
        d -= mm;
        mm = min(min(b, c), d);
        ans += mm * f;
    } else {
        lld mm = min(min(b, c), d);
        ans += mm * f;
        b -= mm;
        c -= mm;
        d -= mm;
        mm = min(a, d);
        ans += mm * e;
    }
    cout<<ans<<'\n';
    return 0;
}
