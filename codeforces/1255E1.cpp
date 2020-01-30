#include <bits/stdc++.h>
#define nmax 1000005
#define inf (long long)1e18+5
#define lld long long
using namespace std;
int n, a[nmax];
lld sum, ans = inf, s[nmax];
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        sum += a[i];
        s[i] = s[i-1] + a[i];
    }
    if (s[n] == 1){
        cout<<"-1\n";
        return 0;
    }
    lld d = 2, v = s[n];
    while (d * d <= v){
        if (v % d == 0){
            lld act = 0;
            for (int i=1;i<=n;++i){
                act += min(s[i]%d, d - s[i]%d);
            }
            ans = min(ans, act);
            while (v % d == 0){
                v /= d;
            }
        }
        ++d;
    }
    if (v!=1){
        lld act = 0;
        for (int i=1;i<=n;++i){
            act += min(s[i]%v, v - s[i]%v);
        }
        ans = min(ans, act);
    }
    printf("%lld\n", ans);
    return 0;
}
