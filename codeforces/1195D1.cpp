#include <bits/stdc++.h>
#define lld unsigned long long
#define mod 998244353LL
using namespace std;
lld pows[20], ans, add;
int x, n;
vector<int>cif;
int main()
{
    scanf("%d",&n);
    pows[0] = 1;
    for (int i=1;i<=19;++i)
        pows[i] = pows[i-1] * 10LL;
    for (int i=1;i<=n;++i)
    {
        cif.clear();
        int ln = 0;
        scanf("%d",&x);
        while (x)
        {
            cif.push_back(x%10);
            x /= 10;
            ++ln;
        }
        add = 0;
        for (int j=0;j<ln;++j)
            add = (add + 1LL*pows[2*j] * cif[j] + 1LL* pows[2*j+1] * cif[j]) % mod;
        add = (add * n) % mod;
        ans = (ans + add) % mod;
    }
    cout<<ans<<'\n';
    return 0;
}
