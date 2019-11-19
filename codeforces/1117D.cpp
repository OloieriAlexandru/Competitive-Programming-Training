#include <bits/stdc++.h>
#define mod 1000000007
#define lld long long
using namespace std;
struct matrix
{
    vector<vector<lld>>values;
    int NMAX;
    matrix() { }
    matrix(int n){
        create(n);
        NMAX = n;
    }
    void create(int n){
        values.resize(n, vector<lld>(n));
    }
    friend matrix operator* (matrix a, matrix b)
    {
        matrix ans(a.NMAX);
        for (int i=0; i<a.NMAX; ++i)
            for (int j=0; j<a.NMAX; ++j)
                for (int k=0; k<a.NMAX; ++k)
                    ans.values[i][j] = (ans.values[i][j]+a.values[i][k]*b.values[k][j])%mod;
        return ans;
    }
};
matrix multiply (matrix a, matrix b)
{
    matrix ans(a.NMAX);
    for (int i=0; i<a.NMAX; ++i)
        for (int j=0; j<a.NMAX; ++j)
            for (int k=0; k<a.NMAX; ++k)
                ans.values[i][j] = (ans.values[i][j]+a.values[i][k]*b.values[k][j])%mod;
    return ans;
}
matrix iNmax;
matrix logPow(matrix x, lld n)
{
    if (!n) return iNmax; // returnam matricea ce contine 1 pe diagonala principala
    if (n&1) return multiply(x, logPow(multiply(x, x), n>>1));
    return logPow(multiply(x, x), n>>1);
}

/*matrix logPow(matrix x, lld n)
{
    if (!n) return iNmax;
    if (n&1) return x*logPow(x*x,n>>1);
    return logPow(x*x,n>>1);
}*/
int m;
lld n;
int main()
{
    cin>>n>>m;
    if (n < m){
        cout<<1<<'\n';
        return 0;
    }
    iNmax.create(m);
    for (int i=0;i<m;++i){
        iNmax.values[i][i] = 1;
    }
    matrix mul(m);
    mul.values[0][0] = mul.values[0][m-1] = 1;
    for (int i=1;i<m;++i){
        mul.values[i][i-1] = 1;
    }
    mul = logPow(mul, n);
    matrix ans(m);
    for (int i=0;i<m;++i){
        ans.values[i][0] = 1;
    }
    ans = multiply(ans,mul);
    cout<<ans.values[0][0]<<'\n';
    return 0;
}
