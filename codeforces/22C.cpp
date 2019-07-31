#include <bits/stdc++.h>
#define nmax 100005
using namespace std;
int c1[nmax], c2[nmax], n, m, v;
int main()
{
    cin>>n>>m>>v;
    int rm = n-1;
    // trebuie sa impart in 2 componente conexe in care sa pot sa bag numar maxim de muchii
    int cnt1, cnt2;
    cnt1 = 1;
    cnt2 = rm - cnt1;
    int tot = cnt1 + cnt2 + (cnt1 * (cnt1 - 1))/2 + (cnt2 * (cnt2 - 1))/2;
    if (n-1 > m || tot < m)
    {
        printf("-1\n");
        return 0;
    }
    int nr1 = 0, nr2 = 0;
    for (int i=1; i<=n; ++i)
    {
        if (v == i) continue;
        ++nr1;
        c1[nr1] = i;
        if (nr1 == cnt1) break;
    }
    for (int i=c1[nr1] + 1; i<=n; ++i)
    {
        if (v == i) continue;
        ++nr2;
        c2[nr2] = i;
        if (nr2 == cnt2) break;
    }
    int af = 2;
    printf("%d %d\n", v, c1[1]);
    printf("%d %d\n", v, c2[1]);
    for (int i=2; i<=nr1; ++i)
        printf("%d %d\n", c1[1], c1[i]), ++af;
    for (int i=2; i<=nr2; ++i)
        printf("%d %d\n", c2[1], c2[i]), ++af;
    for (int i=2; i<nr1; ++i)
        for (int j=i+1; j<=nr1; ++j)
        {
            if (af == m) return 0;
            printf("%d %d\n", c1[i], c1[j]);
            ++af;
        }
    for (int i=2; i<nr2; ++i)
        for (int j=i+1; j<=nr2; ++j)
        {
            if (af == m) return 0;
            printf("%d %d\n", c2[i], c2[j]);
            ++af;
        }
    for (int i=2; i<=nr1; ++i)
    {
        if (af == m) return 0;
        printf("%d %d\n", v, c1[i]);
        ++af;
    }
    for (int i=2; i<=nr2; ++i)
    {
        if (af == m) return 0;
        printf("%d %d\n", v, c2[i]);
        ++af;
    }
    return 0;
}
