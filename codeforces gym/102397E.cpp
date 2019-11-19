#include <bits/stdc++.h>
#define lld long long
#define nmax 100005
using namespace std;
lld n, x, a[nmax], sum;
bool ok(int cnt){
    lld act = 0;
    for (int i=1;i<=cnt;++i){
        act += a[i];
    }
    for (int i=cnt+1;i<=n;++i){
        if (act>=x){
            return true;
        }
        act-=a[i-cnt];
        act+=a[i];
    }
    return (act>=x);
}
int main()
{
    cin>>n>>x;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        sum+=a[i];
    }
    if (sum < x){
        cout<<"-1\n";
        return 0;
    }
    int st = 1, dr = n, ans = n;
    while(st<=dr){
        int m=(st+dr)/2;
        if (ok(m)){
            ans=m;
            dr=m-1;
        } else {
            st=m+1;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
