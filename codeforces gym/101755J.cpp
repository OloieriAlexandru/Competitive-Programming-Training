#include <bits/stdc++.h>
#define nmax 200005
using namespace std;
int eg, a[nmax], n;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for (int i=1;i<=n;++i)
    {
        if (i < n && a[i] == a[i+1])
            ++eg, ++i;
    }
    cout<<eg/2<<'\n';
    return 0;
}
