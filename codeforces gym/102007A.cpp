#include <bits/stdc++.h>
#define nmax 100005
using namespace std;
long long a[nmax], x;
int n;
int main()
{
    cin>>n>>x;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=1;i<n;++i)
    {
        if (a[i] + a[i+1] > x)
        {
            cout<<i<<'\n';
            return 0;
        }
    }
    cout<<n<<'\n';
    return 0;
}
