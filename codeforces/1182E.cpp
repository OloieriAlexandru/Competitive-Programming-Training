#include <bits/stdc++.h>
#define mod1 1000000007
#define mod2 1000000006
#define lld long long
using namespace std;

struct mat
{
    lld m[5][5];
    mat()
    {
        memset(m,0,sizeof(m));
    }
    mat(int i)
    {
        memset(m,0,sizeof(m));
        if (i == 5)
        {
            for (int i=0;i<5;++i)
                m[i][i] = 1;
        }
    }
} i5(5);

mat mul(mat a, mat b, lld mod)
{
    mat ans;
    for (int i=0; i<5; ++i)
        for (int j=0; j<5; ++j)
            for (int k=0; k<5; ++k)
                ans.m[i][j] = (ans.m[i][j] + a.m[i][k] * b.m[k][j]) % mod;
    return ans;
}

mat expLog(mat a, lld n, lld mod)
{
    if (!n) return i5;
    if (n & 1) return mul(a, expLog(mul(a,a,mod),n>>1,mod),mod);
    return expLog(mul(a,a,mod),n>>1,mod);
}

lld expLog(lld a, lld n, lld mod)
{
    if (!n) return 1;
    if (n & 1) return (a * expLog((a*a)%mod,n>>1,mod)) % mod;
    return expLog((a*a)% mod, n>>1,mod);
}

lld n, f[3], c;
int main()
{
    cin>>n>>f[0]>>f[1]>>f[2]>>c;

    mat m;
    m.m[0][0] = m.m[0][1] = m.m[0][2] = 1;
    m.m[1][0] = m.m[2][1] = 1;

    mat mp = expLog(m,n-1,mod2);
    lld ans = 1;

    for (int i=0;i<3;++i)
        ans = (ans * expLog(f[2-i],mp.m[2][i],mod1)) % mod1;

    m.m[0][3] = 2;
    m.m[3][3] = m.m[3][4] = m.m[4][4] = 1;

    mp = expLog(m,n-1,mod2);
    ans = (ans * expLog(c,mp.m[1][4],mod1))% mod1;

    cout<<ans<<'\n';
    return 0;
}
