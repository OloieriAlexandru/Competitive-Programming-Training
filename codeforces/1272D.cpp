#include <bits/stdc++.h>
#define nmax 200005
#define inf 1999999999
using namespace std;
int n, a[nmax], up[nmax], down[nmax], v[nmax], ans = 0;
int main()
{
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    a[n+1] = inf;
    for (int i=1;i<=n;++i){
        int act = 1;
        while (i <= n && a[i] < a[i+1]){
            down[i] = act++;
            ++i;
        }
        down[i] = act;
    }
    a[0] = -1;
    for (int i=n;i>=1;--i){
        int act = 1;
        while (i >= 1 && a[i] > a[i-1]){
            up[i] = act++;
            --i;
        }
        up[i] = act;
    }
    for (int i=1;i<=n;++i){
        ans = max(ans, up[i]);
    }
    for (int i=1;i<=n;++i){
        if (a[i+1] > a[i-1] && !(a[i] < a[i+1] && a[i-1] < a[i])){
            ans = max(ans, down[i-1] + up[i+1]);
        }
    }
    cout<<ans<<'\n';
    return 0;
}
