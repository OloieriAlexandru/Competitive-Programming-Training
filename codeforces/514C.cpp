#include <bits/stdc++.h>
#define nmax 1000005
#define lld long long
#define mod 10000000009LL
using namespace std;
int n, m, ln;
char s[nmax];
unordered_set<lld>hashes;
lld p31[nmax], hashL[nmax], hashR[nmax], pozH[nmax];
lld getHash(char *s)
{
    lld ret = 0;
    int index = 0;
    while (*s)
    {
        ret = (ret + p31[index++] * (lld)*s)%mod;
        ++s;
    }
    return ret;
}
void compute(char *s)
{
    int index = 0;
    while (*s)
    {
        pozH[index] = (p31[index] * (lld)*s)%mod;
        hashL[index] = pozH[index];
        if (index)
            hashL[index] = (hashL[index-1] + pozH[index])%mod;
        ++s, ++index;
    }
    hashR[ln] = 0;
    for (int i=ln-1; i>=0; --i)
        hashR[i] = (hashR[i+1] + pozH[i])%mod;
}
int main()
{
    scanf("%d %d\n",&n,&m);
    p31[0] = 1;
    for (int i=1; i<nmax; ++i)
        p31[i] = (p31[i-1] * 31) % mod;
    for (int i=1; i<=n; ++i)
    {
        scanf("%s",s);
        hashes.insert(getHash(s));
    }
    for (int j=1; j<=m; ++j)
    {
        scanf("%s",s);
        ln = strlen(s);
        compute(s);
        bool found = false;
        for (int i=0; i<ln && !found; ++i)
        {
            for (char c = 'a'; c<='c'; ++c)
            {
                if (c == s[i]) continue;
                lld curr = p31[i] * c;
                lld thisHash = ((i > 0 ? hashL[i-1] : 0) + curr + hashR[i+1] ) % mod;
                if (hashes.count(thisHash))
                {
                    found = true;
                    break;
                }
            }
        }
        if(found)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
