#include <bits/stdc++.h>
#define nmax 1805
#define lld long long
using namespace std;
class big
{
private:
    short nr[2005];
    int ln;
public:
    big()
    {
        ln = 1;
        memset(nr, 0, sizeof(nr));
    }
    big(int x)
    {
        ln = 0;
        memset(nr, 0, sizeof(nr));
        while (x) nr[ln++] = x%10, x/=10;
    }
    friend big operator +(big a, big b)
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
        if (t) ans.nr[ans.ln++] = 1;
        return ans;
    }
    friend big operator *(big a, int x)
    {
        big ans;
        ans.ln = a.ln;
        int t = 0, v;
        for (int i=0;i<ans.ln;++i)
        {
            v = a.nr[i] * x + t;
            ans.nr[i] = v%10;
            t = v/=10;
        }
        while (t) ans.nr[ans.ln++] = t%10, t/=10;
        return ans;
    }
    big& operator=(big x)
    {
        ln = x.ln;
        memcpy(nr, x.nr, sizeof(nr));
        return *this;
    }
    big& operator=(int x)
    {
        ln = 0;
        memset(nr, 0, sizeof(nr));
        while (x) nr[ln++] = x%10,x/=10;
        return *this;
    }
    friend ostream& operator<<(ostream &out,big a)
    {
        for (int i=a.ln-1;i>=0;--i)
            out<<a.nr[i];
        return out;
    }
};
big dp[nmax];
int main()
{
    int n, k;
    cin>>n>>k;
    dp[0] = 1;
    dp[1] = k-1;
    for (int i=2;i<=n;++i)
        dp[i] = (dp[i-1] + dp[i-2])*(k-1);
    cout<<dp[n]<<'\n';
    return 0;
}