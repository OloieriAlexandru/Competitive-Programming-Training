#include <bits/stdc++.h>
#define nmax 200005
using namespace std;
string s1, s2;
int a[nmax], n;
bool el[nmax];
bool match()
{
    int i1 = 0, i2 = 0;
    while (i1 < s1.size() && i2 < s2.size())
    {
        if (el[i1])
        {
            ++i1;
            continue;
        }
        if (s1[i1] == s2[i2])
            ++i1, ++i2;
        else
            ++i1;
    }
    if (i2 == s2.size()) return true;
    return false;
}
bool ok(int m)
{
    memset(el, 0, sizeof(el));
    for (int i=1; i<=m; ++i)
        el[a[i]-1] = 1;
    return match();
}
int main()
{
    cin>>s1;
    cin>>s2;
    n = s1.size();
    for (int i=1; i<=n; ++i)
        cin>>a[i];
    int st = 1, dr = n, ans = 0;
    while (st <= dr)
    {
        int m = (st + dr) / 2;
        if (ok(m))
        {
            ans = max(ans, m);
            st = m + 1;
        }
        else dr = m-1;
    }
    cout<<ans<<'\n';
    return 0;
}
