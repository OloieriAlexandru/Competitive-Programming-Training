#include <bits/stdc++.h>
#define nmax 1005
using namespace std;
int n, a[nmax];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for (int i=1; i<=n; ++i)
        {
            cin>>a[i];
        }
        sort(a+1,a+n+1,[](int a, int b)
        {
            return a>=b;
        });
        int ans = 1;
        for (int i=1;i<=n;++i){
            ans=max(ans,min(i, a[i]));
        }
        cout<<ans<<'\n';
    }
    return 0;
}
