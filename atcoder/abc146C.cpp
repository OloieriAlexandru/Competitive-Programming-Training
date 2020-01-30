#include <bits/stdc++.h>
#define lld long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define nmax
#define mod
using namespace std;

lld a, b, x;
lld dig(lld x){
    if (!x){
        return 1;
    }
    lld res = 0;
    while (x){
        ++res;
        x/=10;
    }
    return res;
}
bool ok(lld m){
    lld val = m * a + b * dig(m);
    return val <= x;
}

int main()
{
    cin>>a>>b>>x;
    lld ans = 0;
    lld st = 0, dr = 1000000000LL;
    while (st <= dr){
        lld m = (st + dr) / 2;
        if (ok(m)){
            st = m + 1;
            ans = m;
        } else {
            dr = m - 1;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
