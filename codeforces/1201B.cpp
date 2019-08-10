#include <bits/stdc++.h>
#define lld long long
#define nmax 100005
using namespace std;
int n, a[nmax];
lld sum;
int main()
{
    cin>>n;
    for (int i=1; i<=n; ++i)
    {
        cin>>a[i];
        sum += a[i];
    }
    sort(a+1,a+n+1);
    if (sum%2)
    {
        cout<<"NO\n";
        return 0;
    }
    sum -= a[n];
    if (a[n] > sum)
    {
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    return 0;
}
