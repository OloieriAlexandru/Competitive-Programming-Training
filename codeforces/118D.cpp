#include <bits/stdc++.h>
#define lld long long
#define nmax1 101
#define nmax2 11
using namespace std;
lld dp[nmax1][nmax1][nmax2][nmax2];
int n1, n2, kk1, kk2;
lld memo(int n1, int n2, int k1, int k2)
{
    if (dp[n1][n2][k1][k2] != -1)
        return dp[n1][n2][k1][k2];
    lld res = 0;
    if (n1 + n2 > 0)
    {
        if (n1 > 0 && k1 > 0)
            res += memo(n1-1,n2,k1-1,kk2);
        if (n2 > 0 && k2 > 0)
            res += memo(n1,n2-1,kk1,k2-1);
        res %= 100000000;
    }
    else
        res = 1;
    dp[n1][n2][k1][k2] = res;
    return res;
}
int main()
{
    cin>>n1>>n2>>kk1>>kk2;
    for (int i=0;i<=n1;++i)
        for (int j=0;j<=n2;++j)
            for (int k=0;k<=kk1;++k)
                for (int l=0;l<=kk2;++l)
                    dp[i][j][k][l] = -1;
    cout<<memo(n1,n2,kk1,kk2)<<'\n';
    return 0;
}
