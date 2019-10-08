#include <bits/stdc++.h>
#define nmax 105
using namespace std;
int fv[26], n, ans;
char s1[nmax], s2[nmax];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d\n",&n);
        scanf("%s", s1);
        scanf("%s", s2);
        memset(fv, 0, sizeof(fv));
        for (int i=0; i<n; ++i)
        {
            ++fv[s1[i]-'a'];
            --fv[s2[i]-'a'];
        }
        bool ok = true;
        for (int i=0; i<26; ++i)
            if (fv[i])
            {
                ok = false;
                break;
            }
        if (!ok)
        {
            printf("-1\n");
            continue;
        }
        ans = n;
        for (int i=0;i<n;++i)
        {
            int act = i;
            int good = 0;
            for (int j=0;j<n;++j)
            {
                if (s1[j] == s2[act])
                {
                    ++act;
                    ++good;
                }
            }
            ans = min(ans, n - good);
        }
        printf("%d\n", ans);
    }
    return 0;
}
