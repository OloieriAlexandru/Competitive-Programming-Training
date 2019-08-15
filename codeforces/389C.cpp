#include <bits/stdc++.h>
#define nmax 105
using namespace std;
int n, a[nmax];
bool ok(int k)
{
    for (int i=1;i<=n;++i)
        if ((i-1)/k > a[i]) return false;
    return true;
}
int main()
{
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=1;i<=n;++i)
        if (ok(i))
        {
            cout<<i<<'\n';
            break;
        }
    return 0;
}
