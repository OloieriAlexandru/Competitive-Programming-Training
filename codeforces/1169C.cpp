#include <bits/stdc++.h>
#define nmax 300005
using namespace std;
int n, m, a[nmax];
bool ok(int op)
{
    int lst = a[1];
    if (lst + op >= m)
        lst = 0;
    for (int i=2;i<=n;++i)
    {
        // cate operatii imi trebuie ca elementul curent sa fie >= lst?
        if (a[i] + op < lst) return false;
        if (a[i] > lst)
        {
            if (a[i] + op < m + lst)
                lst = a[i];
        }
    }
    return true;
}
int main()
{
    scanf("%d %d",&n,&m);
    for (int i=1; i<=n; ++i)
        scanf("%d",&a[i]);
    int st = 0, dr = 999999999, ans = 1111111111;
    while (st<=dr)
    {
        int m = (st + dr)/2;
        if (ok(m))
        {
            ans = min(ans, m);
            dr = m-1;
        }
        else
            st = m+ 1;
    }
    cout<<ans<<'\n';
    return 0;
}
