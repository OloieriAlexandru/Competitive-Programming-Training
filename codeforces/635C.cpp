#include <bits/stdc++.h>
#define nmax 66
using namespace std;
int bitsAnd[nmax], bitsXor[nmax];
int main()
{
    long long s, x;
    cin>>s>>x;
    if ((s - x)%2 || x > s)
    {
        cout<<"0\n";
        return 0;
    }
    long long xorr = x;
    long long andd = (s - x) / 2;
    long long p = 0;
    long long lnxorr = 0;
    while (xorr)
        bitsXor[++p] = xorr % 2, xorr /= 2, ++lnxorr;
    p = 0;
    long long lnand = 0;
    long long ans = 1;
    while (andd)
        bitsAnd[++p] = andd % 2, andd /= 2, ++lnand;
    for (int i=1; i<=max(lnand, lnxorr); ++i)
    {
        if (bitsAnd[i] == 1 && bitsXor[i] == 1)
        {
            cout<<"0\n";
            return 0;
        }
        if (bitsXor[i] == 1 && bitsAnd[i] == 0)
            ans *= 2;
    }
    if (s == x) ans -= 2;
    cout<<ans<<'\n';
    return 0;
}
