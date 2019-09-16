#include <bits/stdc++.h>
#define nmax 1000005
#define lld long long
using namespace std;
char s[nmax], t[nmax];
lld n, m;
int lns, lnt, cnt[nmax][26], gc;
int main()
{
    cin>>n>>m;
    cin>>s;
    cin>>t;
    lns = strlen(s);
    lnt = strlen(t);
    gc = __gcd(lns, lnt);
    lld ans = lns * (lld)lnt / gc;
    lld mul = ans;
    for (int i=0;i<lnt;++i)
        ++cnt[i%gc][t[i]-'a'];
    for (int i=0;i<lns;++i)
        mul -= cnt[i%gc][s[i]-'a'];
    lld af = mul * (n * lns / ans);
    cout<<af<<'\n';
    return 0;
}
