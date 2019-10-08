#include <bits/stdc++.h>
#define nmax 100005
#define lsb(x) ((x)&(-x))
using namespace std;
int aint[26][nmax], q, type, x, y, ans, n;
char s[nmax], ch, lch;
int query(int arb, int poz)
{
    int ret = 0;
    for (;poz>=1;poz-=lsb(poz))
        ret += aint[arb][poz];
    return ret;
}
void update(int arb, int poz, int add)
{
    for(;poz<=n;poz+=lsb(poz))
        aint[arb][poz] += add;
}
int query(int arb, int l, int r)
{
    return query(arb, r) - query(arb, l-1);
}
int main()
{
    cin>>s;
    n = strlen(s);
    for (int i=0;i<n;++i)
        update(s[i]-'a',i+1,1);
    cin>>q;
    for (int i=1;i<=q;++i)
    {
        cin>>type;
        if (type == 2)
        {
            ans = 0;
            cin>>x>>y;
            for (int j=0;j<26;++j)
                if (query(j, x, y))
                    ++ans;
            cout<<ans<<'\n';
        }
        else
        {
            cin>>x>>ch;
            lch = s[x-1];
            update(lch-'a',x,-1);
            update(ch-'a',x,1);
            s[x-1] = ch;
        }
    }
    return 0;
}
