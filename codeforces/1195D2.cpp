#include <bits/stdc++.h>
#define nmax 22
#define lld long long
#define mod 998244353
#define nmax2 100005
using namespace std;
int nrc(int x)
{
    if (x<=9) return 1;
    return 1 + nrc(x/10);
}
int n, x, a[nmax2], cnt[nmax];
lld z[nmax], ans;
int func1(int ln, vector<int>&digits)
{
    lld ret = 0;
    lld pw = 1;
    for (int i=0; i<max(ln, (int)digits.size()); ++i)
    {
        if (i < ln) pw = (pw * 10) % mod;
        if (i < digits.size())
        {
            ret = (ret + (digits[i] * pw)%mod) % mod;
            pw = (pw * 10) % mod;
        }
    }
    return ret;
}
int func2(int ln, vector<int>&digits)
{
    lld ret = 0;
    lld pw = 1;
    for (int i=0; i<max(ln, (int)digits.size()); ++i)
    {
        if (i < digits.size())
        {
            ret = (ret + (digits[i] * pw)%mod) % mod;
            pw = (pw * 10) % mod;
        }
        if (i < ln) pw = (pw * 10) % mod;
    }
    return ret;
}
int main()
{
    cin>>n;
    z[0] = 1;
    for (int i=1; i<=20; ++i)
        z[i] = (z[i-1] * 10) % mod;
    for (int i=1; i<=n; ++i)
    {
        cin>>a[i];
        ++cnt[nrc(a[i])];
    }
    for (int i=1; i<=n; ++i)
    {
        vector<int>dig;
        int cx = a[i];
        while (cx)
        {
            dig.push_back(cx % 10);
            cx /= 10;
        }
        for (int i=1; i<=10; ++i)
        {
            lld act = func1(i, dig);
            ans = (ans + (act * cnt[i]) % mod) % mod;
            act = func2(i, dig);
            ans = (ans + (act * cnt[i])% mod) % mod;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
