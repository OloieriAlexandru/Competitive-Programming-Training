#include <bits/stdc++.h>
#define nmax 5005
using namespace std;
int n, m, ans, one[nmax][nmax], nw;
int act[nmax];
char s[nmax][nmax];
int main()
{
    scanf("%d %d",&n,&m);
    for (int i=1; i<=n; ++i)
        scanf("%s",s[i]+1);
    for (int i=1; i<=n; ++i)
        for (int j=m; j>=1; --j)
            if (s[i][j] == '1')
                one[i][j] = one[i][j+1] + 1;
    for (int j=1; j<=m; ++j)
    {
        for (int i=1; i<=n; ++i)
            act[i] = one[i][j];
        sort(act+1, act+n+1, [](int a, int b)
        {
            return a>b;
        });
        for (int i=1; i<=n; ++i)
        {
            if (!act[i]) break;
            ans = max(ans, act[i] * i);
        }
    }
    cout<<ans<<'\n';
    return 0;
}
