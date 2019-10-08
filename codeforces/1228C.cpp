#include <bits/stdc++.h>
#define nmax 32000
#define pb push_back
#define mod 1000000007LL
#define lld long long
using namespace std;
vector<int>primes;
vector<lld>fp;
bool ciur[nmax];
void erath()
{
    for (int i=2; i<nmax; ++i)
    {
        if (ciur[i]) continue;
        primes.pb(i);
        for (int j=i+i; j<nmax; j+=i)
            ciur[j] = true;
    }
}
lld ans = 1, x;
int n;
lld expLog(lld x, lld n)
{
    if (n<=0) return 1;
    if (n & 1)
        return (x*expLog((x*x)%mod, n>>1))%mod;
    return expLog((x*x)%mod,n>>1);
}
int main()
{
    cin>>n>>x;
    erath();
    int cn = n;
    for (int i=0; i<primes.size()&&n>1; ++i)
    {
        if (n % primes[i]) continue;
        fp.pb(primes[i]);
        while (n % primes[i] == 0)
            n /= primes[i];
    }
    if (n > 1) fp.pb(n);
    lld r, v1, cnt, act;
    for (auto primeFac:fp)
    {
        lld cx = x;
        lld pf = primeFac;
        while (pf <= cx / primeFac)
        {
            ans = (ans * expLog(primeFac, cx / pf))%mod;
            pf *= primeFac;
        }
        ans =(ans * expLog(primeFac, cx/pf))%mod;
    }
    cout<<ans<<'\n';
    return 0;
}
