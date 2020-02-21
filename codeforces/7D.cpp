#include <bits/stdc++.h>
#define base 131
#define mod 1000000007
#define nmax 5000005
#define lld long long
using namespace std;
char s[nmax];
int k, v[nmax];
lld ans, h1, h2, b131 = 1;
int main()
{
    scanf("%s",s);
    for (int i=0;s[i];++i){
        h1 = (h1 * base + s[i])%mod;
        h2 = (h2 + b131 * s[i])%mod;
        b131 = (b131 * base)%mod;
        k = 0;
        if (h1 == h2){
            k = v[(i+1)/2] + 1;
        }
        ans += k;
        v[i+1] = k;
    }

    cout<<ans<<'\n';
    return 0;
}
