#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define ll long long
#define ld long double
#define pb push_back
#define nmax 1000001
using namespace std;
int t, nrtot, ans;
bool ciur[nmax];
ll tot[100000];
ll a, b, inf = 1000000000000LL;
int compute(ll x){
    int st = 0, m, dr = nrtot-1, res = -1;
    while (st <= dr){
        m = (st + dr) / 2;
        if (tot[m] <= x){
            res = m;
            st = m + 1;
        } else {
            dr = m - 1;
        }
    }
    if (res == -1){
        return 0;
    }
    return res + 1;
}
void primes(){
    for (int i=2;i*i<nmax;++i){
        if (ciur[i]){
            continue;
        }
        for (int j=i*i;j<nmax;j+=i){
            ciur[j] = true;
        }
    }
    for (int i=2;i<nmax;++i){
        if (!ciur[i]){
            ll x = 1LL * i * i;
            while (x <= inf){
                tot[nrtot++] = x;
                x = x * i;
            }
        }
    }
    sort(tot,tot+nrtot);
}
int main()
{
    freopen("asi.in","r",stdin);
    freopen("asi.out","w",stdout);
    scanf("%d",&t);
    primes();
    while (t--){
        scanf("%lld %lld",&a,&b);
        ans = compute(b) - compute(a-1);
        printf("%d\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
