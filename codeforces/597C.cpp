#include <bits/stdc++.h>
#define ll long long
#define nmax 100005
#define lsb(x) ((x)&(-x))
using namespace std;
ll aib[12][nmax], act, ans;
int n, k, x;
const int nm = 100000;
void update(int arb, int poz, ll add)
{
    for (;poz<=nm;poz+=lsb(poz))
        aib[arb][poz] += add;
}
ll query(int arb, int poz)
{
    ll ret = 0;
    for (;poz>=1;poz-=lsb(poz))
        ret+=aib[arb][poz];
    return ret;
}
int main()
{
    scanf("%d %d",&n,&k);
    for (int i=1;i<=n;++i)
    {
        scanf("%d",&x);
        for (int j=k;j>=1;--j)
        {
            act = query(j, x);
            if (j == k) ans += act;
            update(j+1, x, act);
        }
        if (k == 0)++ans;
        update(1, x, 1);
    }
    cout<<ans<<'\n';
    return 0;
}
