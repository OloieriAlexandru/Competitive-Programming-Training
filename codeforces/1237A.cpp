#include <bits/stdc++.h>
#define nmax 14000
using namespace std;
int a[nmax], n, rm, cnt;
bool checked[nmax];
int main()
{
    cin>>n;
    for (int i=1; i<=n; ++i)
        cin>>a[i];
    for (int i=1; i<=n; ++i)
    {
        if (a[i]% 2 == 0)
        {
            a[i] /= 2;
            checked[i] = true;
            continue;
        }
        ++rm;
    }
    for (int i=1; i<=n; ++i)
    {
        if (checked[i]) continue;
        if (cnt < (rm / 2))
        {
            ++cnt;
            a[i] = (int)(ceil(a[i] / 2.0));
        }
        else
        {
            a[i] = (int)(floor(a[i]/2.0));
        }
    }
    for (int i=1; i<=n; ++i)
        cout<<a[i]<<'\n';
    return 0;
}
