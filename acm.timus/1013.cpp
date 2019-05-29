#include <bits/stdc++.h>
#define lld unsigned long long
using namespace std;
lld n, k, mod;
class big
{
private:
    short nr[100];
    int ln;
public:
    big()
    {
        memset(nr, 0, sizeof(nr));
        ln = 1;
    }
    big (int x)
    {
        memset(nr, 0, sizeof(nr));
        if (!x)
        {
            ln = 1;
            return;
        }
        ln = 0;
        while (x) nr[ln++] = x%10, x/=10;
    }
    friend big operator+(big a, big b)
    {
        big ans;
        ans.ln = max(a.ln, b.ln);
        int t = 0, v;
        for (int i=0;i<ans.ln;++i)
        {
            v = a.nr[i] + b.nr[i] + t;
            ans.nr[i] = v%10;
            t = v/10;
        }
        if (t)
            ans.nr[ans.ln++] = 1;
        return ans;
    }
    big& operator=(lld x)
    {
        ln = 0;
        memset(nr, 0, sizeof(nr));
        if (!x)
        {
            ln =1;
            return *this;
        }
        while (x)
            nr[ln++]=x%10, x/=10;
        return *this;
    }
    friend big operator+(big a, lld x)
    {
        big ans;
        ans.ln = a.ln;
        lld t = 0, v;
        for (int i=0;i<ans.ln;++i)
        {
            v = a.nr[i]*x + t;
            ans.nr[i] = v%10;
            t = v/10;
        }
        while (t)
            ans.nr[ans.ln++] = t%10, t/=10;
        return ans;
    }
    friend big operator%(big a, lld mod)
    {
        big ans;
        lld r = 0;
        for (int i=a.ln-1;i>=0;--i)
        {
            r = r * 10 + a.nr[i];
            r %= mod;
        }
        ans = r;
        return ans;
    }
    friend big operator*(big a, big b)
    {
        big ans;
        for (int i=0;i<a.ln;++i)
            for (int j=0;j<b.ln;++j)
                ans.nr[i+j] += a.nr[i]*b.nr[j];
        lld v, t = 0;
        int i = 0;
        for (i=0;i<a.ln+b.ln-1 || t;++i)
        {
            v = ans.nr[i] + t;
            ans.nr[i] = v%10;
            t = v/10;
        }
        ans.ln = i;
        return ans;
    }
    friend ostream& operator<<(ostream &out, big a)
    {
        for (int i=a.ln-1;i>=0;--i)
            out<<a.nr[i];
        return out;
    }
};
struct mat
{
    big m[2][2];
};
mat mul(mat a, mat b)
{
    mat ans;
    for (int i=0;i<2;++i)
        for (int j=0;j<2;++j)
            for (int k=0;k<2;++k)
                ans.m[i][j] = (ans.m[i][j] + (a.m[i][k]%mod)*(b.m[k][j])%mod)%mod;
    return ans;
}
mat i2, rd, ans;
mat expLog(mat a, lld pw)
{
    if (!pw)
        return i2;
    if (pw & 1)
        return mul(a,expLog(mul(a,a),pw>>1));
    return expLog(mul(a,a),pw>>1);
}
int main()
{
    cin>>n>>k>>mod;
    i2.m[0][0] = i2.m[1][1] = 1;
    rd.m[0][0] = rd.m[0][1] = ( k-1 ) % mod;
    rd.m[1][0] = 1;
    rd = expLog(rd,n-1);
    ans.m[0][0] = (k-1) % mod;
    ans.m[1][0] = 1;
    ans = mul(rd, ans);
    cout<<ans.m[0][0]<<'\n';
    return 0;
}