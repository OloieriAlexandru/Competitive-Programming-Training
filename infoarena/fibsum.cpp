#include <bits/stdc++.h>
#define mod 1000000007LL
#define lld long long
using namespace std;
struct matrix
{
    lld m[2][2];
    matrix()
    {
        memset(m,0,sizeof(m));
    }
};
matrix mul(matrix a, matrix b)
{
    matrix res;
    for (int k=0; k<2; ++k)
        for (int i=0; i<2; ++i)
            for (int j=0; j<2; ++j)
                res.m[i][j] = (res.m[i][j] + 1LL * a.m[i][k] * b.m[k][j]) % mod;
    return res;
}
matrix i2;
matrix expLog(matrix a, lld n)
{
    if (!n) return i2;
    if (n == 1) return a;
    if (n % 2 == 0)
        return expLog(mul(a,a),n>>1);
    else
        return mul(expLog(mul(a,a),n>>1),a);
}
lld l, r;
lld fib(lld k)
{
    if (k == 0) return 1;
    if (k == 1) return 1;
    if (k == 2) return 2;
    matrix ml;
    matrix init;
    init.m[0][0] = 2;
    init.m[0][1] = 1;
    ml.m[0][0] = 1;
    ml.m[0][1] = 1;
    ml.m[1][0] = 1;
    matrix inm = expLog(ml, k-2);
    matrix res = mul(init, inm);
    return res.m[0][0] % mod;
}
lld suma(lld k)
{
    lld ret = fib(k+2)-1;
    if (ret < 0) ret += mod;
    return ret;
}
int main()
{
    freopen("fibsum.in","r",stdin);
    freopen("fibsum.out","w",stdout);
    int t;
    scanf("%d",&t);
    i2.m[0][0] = i2.m[1][1] = 1;
    while(t--)
    {
        cin>>l>>r;
        if (l == r)
        {
            printf("%lld\n", fib(l));
            continue;
        }
        else
        if (r - 1 == l)
        {
            lld sum = (fib(l)+fib(l+1))%mod;
            printf("%lld\n", sum);
        }
        else
        {
            lld ans = suma(r);
            if (l > 0)
                ans -= suma(l-1);
            if (ans < 0) ans += mod;
            printf("%lld\n", ans);
        }
    }
    return 0;
}
