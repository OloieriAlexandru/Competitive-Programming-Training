#include <bits/stdc++.h>
#define inf 999999999
#define nmax 200005
using namespace std;
int t, n, k, ans;
char s[nmax];
char v1[nmax], v2[nmax], v3[nmax];
void precalc(const char *rep, char v[])
{
    for (int i=0;i<200000;++i)
        v[i] = rep[i%3];
}
void calc(char rep[])
{
    int gr = 0;
    for (int i=0;i<k;++i)
        if (rep[i] != s[i])
            ++gr;
    for (int i=k;i<n;++i)
    {
        ans = min(ans, gr);
        if (s[i-k] != rep[i-k]) --gr;
        if (s[i] != rep[i]) ++gr;
    }
    ans = min(ans, gr);
}
int main()
{
    scanf("%d",&t);
    precalc("RGB",v1);
    precalc("GBR",v2);
    precalc("BRG",v3);
    while (t--)
    {
        scanf("%d %d",&n,&k);
        scanf("%s",s);
        ans = inf;
        calc(v1);
        calc(v2);
        calc(v3);
        printf("%d\n", ans);
    }
    return 0;
}
