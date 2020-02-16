#include <bits/stdc++.h>
#define NMAX 2
#define lld long long
using namespace std;

lld MOD;

struct matrix
{
    int values[NMAX][NMAX];
    matrix()
    {
        memset(values,0,sizeof(values));
    }

    friend matrix operator* (matrix a, matrix b)
    {
        matrix ans;
        for (int i=0; i<NMAX; ++i)
            for (int j=0; j<NMAX; ++j)
                for (int k=0; k<NMAX; ++k)
                    ans.values[i][j] = (ans.values[i][j]+1LL*a.values[i][k]*b.values[k][j])%MOD;
        return ans;
    }
};

matrix multiply (matrix a, matrix b)
{
    matrix ans;
    for (int i=0; i<NMAX; ++i)
        for (int j=0; j<NMAX; ++j)
            for (int k=0; k<NMAX; ++k)
                ans.values[i][j] = (ans.values[i][j]+1LL*a.values[i][k]*b.values[k][j])%MOD;
    return ans;
}

matrix iNmax;

/*matrix logPow(matrix x, int n)
{
    if (!n) return iNmax; // returnam matricea ce contine 1 pe diagonala principala
    if (n&1) return multiply(x, logPow(multiply(x, x), n>>1));
    return logPow(multiply(x, x), n>>1);
}*/

matrix logPow(matrix x, int n)
{
    if (!n) return iNmax;
    if (n&1) return x*logPow(x*x,n>>1);
    return logPow(x*x,n>>1);
}

int main()
{
    int n, m;
    while(cin>>n>>m)
    {
        MOD = 1LL<<m;
        if (n==0){
            cout<<0<<'\n';
            continue;
        }
        else if (n==1){
            cout<<1%MOD<<'\n';
            continue;
        }
        iNmax.values[0][0] = iNmax.values[1][1] = 1;
        matrix m;
        m.values[0][0] = m.values[0][1] = m.values[1][0] = 1;
        m = logPow(m, n-2);
        matrix vectorr;
        vectorr.values[0][0]=1;
        vectorr.values[1][0]=1;
        matrix ans = m * vectorr;
        printf("%d\n",ans.values[0][0]);
        // ans.values[0][0] este Tn
    }
    return 0;
}
