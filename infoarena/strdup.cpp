#include <bits/stdc++.h>
#define nmax 1005
#define mod 500000003
#define lld long long
using namespace std;
int t, ln, repTotal, subsTotal, gc;
char str[nmax];
int fv[75], unic, vec[nmax], cnt, rep, hsh, p67[nmax];
int main()
{
    freopen("strdup.in","r",stdin);
    freopen("strdup.out","w",stdout);
    scanf("%d",&t);
    p67[0] = 1;
    for (int i=1; i<=1000; ++i)
        p67[i] = (64LL * p67[i-1]) % mod;
    while(t--)
    {
        scanf("%s",str);
        ln = strlen(str);
        for (int i=0; i<ln; ++i)
        {
            if (str[i] >= 'a' && str[i] <= 'z')
                str[i] = str[i] - 'a' + 1;
            else if (str[i] >= 'A' && str[i] <= 'Z')
                str[i] = str[i] - 'A' + 27;
            else
                str[i] = str[i] - '0' + 53;
            ++fv[str[i]];
        }
        unic = 0;
        for (int i=1; i<=70; ++i)
        {
            if (fv[i] == 1)
                ++unic;
            fv[i] = 0;
        }
        repTotal = ln - unic;
        for (int i=2; i<=ln-1; ++i)
        {
            hsh = 0;
            rep = 0;
            cnt = 0;
            for (int j=0; j<i; ++j)
                hsh = (hsh + 1LL*p67[i-j-1] * str[j]) % mod;
            for (int j=i; j<ln; ++j)
            {
                vec[++cnt] = hsh;
                hsh = (hsh - 1LL*str[j-i] * p67[i-1] ) %mod;
                if (hsh < 0) hsh += mod;
                hsh = (64LL*hsh + str[j]) % mod;
            }
            vec[++cnt] = hsh;
            sort(vec+1,vec+cnt+1);

            unic = 0;
            vec[0] = -1;
            vec[cnt+1] = -1;
            for (int J=1;J<=cnt;++J)
            {
                if (vec[J] != vec[J-1] && vec[J] != vec[J+1])
                        ++unic;
            }

            repTotal += (ln - i + 1) - unic;
        }
        subsTotal = ln * (ln + 1) / 2;
        gc = __gcd(subsTotal, repTotal);
        repTotal /= gc;
        subsTotal /= gc;
        printf("%d/%d\n", repTotal, subsTotal);
    }
    return 0;
}

