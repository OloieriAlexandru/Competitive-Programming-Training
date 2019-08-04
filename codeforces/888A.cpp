#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, a[1000], ans=0;
    cin>>n;
    for (int i=1; i<=n; ++i)
        cin>>a[i];
    for (int i=2; i<n; ++i)
        if (a[i] > a[i-1] && a[i] > a[i+1] || a[i] < a[i-1] && a[i] < a[i+1]) ++ans;
    cout<<ans<<'\n';
    return 0;
}
