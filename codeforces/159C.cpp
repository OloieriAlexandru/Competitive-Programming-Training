#include <bits/stdc++.h>
#define nmax 200005
using namespace std;
int m, p, aib[26][nmax], n, st, dr, k, updpos, rs, q;
string s, ls;
char ch;
void update(int arb, int poz, int add)
{
    for (; poz<=n; poz+=(poz&-poz))
        aib[arb][poz] += add;
}
int query(int arb, int poz)
{
    int ret = 0;
    for (; poz>=1; poz-=(poz&-poz))
        ret += aib[arb][poz];
    return ret;
}
void upd(int arb, int ap)
{
    st = 1, dr = n;
    while (st <= dr)
    {
        m = (st + dr) / 2;
        rs = query(arb, m);
        if (rs == ap) updpos = m, dr = m-1;
        else if (rs > ap) dr = m-1;
        else st = m+1;
    }
    update(arb, updpos, -1);
}
int main()
{
    cin>>k;
    cin>>s;
    cin>>q;
    n = s.size() * k;
    for (int i=1; i<=k; ++i)
        ls = ls + s;
    for (int i=0; i<n; ++i)
        update(ls[i]-'a', i+1, 1);
    for (int i=1; i<=q; ++i)
    {
        cin>>p>>ch;
        upd(ch-'a', p);
    }
    for (int i=1; i<=n; ++i)
    {
        for (int j=0; j<26; ++j)
            if (query(j, i)-query(j,i-1) == 1)
            {
                cout<<(char)(j+'a');
                break;
            }
    }
    return 0;
}
