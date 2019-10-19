#include <bits/stdc++.h>
using namespace std;
#define nmax 100005
int n, a[nmax], b[nmax], ans, p1, p2;
bool checked[nmax];
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    for (int i=1;i<=n;++i)
        scanf("%d",&b[i]);
    p1 = 1, p2 = 1;
    while (p1 <= n)
    {
        if (checked[a[p1]])
        {
            ++p1;
            continue;
        }
        if (p2 == n+1)
        {
            ++p1;
            continue;
        }
        if (a[p1] == b[p2])
        {
            ++p1, ++p2;
            continue;
        }
        checked[b[p2]] = true;
        ++ans;
        ++p2;
    }
    printf("%d\n", ans);
    return 0;
}
