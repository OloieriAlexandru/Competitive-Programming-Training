#include <bits/stdc++.h>
#define nmax 255555
#define mod 1000000007
#define lld long long
using namespace std;
unsigned char s[nmax], t[2*nmax];
int n;
lld pw[nmax];
lld expectedHash, currHash;
const lld poww = 31;
int ans = -1;
int main()
{
    scanf("%d\n",&n);
    scanf("%s\n",s);
    scanf("%s",t);
    for (int i=0;i<n;++i)
        t[i+n] = t[i];
    pw[0] = 1;
    for (int i=1;i<=n;++i)
        pw[i] = ( pw[i-1] * poww ) % mod;
    for (int i=n-1;i>=0;--i)
    {
        expectedHash = ( expectedHash + s[i] * pw[n-i-1] ) %mod;
        currHash = ( currHash + t[i] * pw[n-i-1] ) %mod;
    }
    if (expectedHash == currHash)
    {
        printf("0\n");
        return 0;
    }
    for (int i=n;i<2*n;++i)
    {
        currHash = (currHash - 1LL * t[i-n] * pw[n-1]) % mod;
        if (currHash < 0)
            currHash = mod + currHash;
        currHash = (currHash * poww) % mod;
        currHash = (currHash + t[i]) % mod;
        //cout<<currHash<<' '<<expectedHash<<'\n';
        if (currHash == expectedHash)
        {
            bool ok = true;
            for (int j=0;j<n;++j)
                if (s[j] != t[i-n+j+1])
            {
                ok = false;
                break;
            }
            if (!ok) continue;
            ans = i - n + 1;
            break;
        }
    }
    printf("%d\n",ans);
    return 0;
}