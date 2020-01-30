#include <bits/stdc++.h>
using namespace std;
int n, x, y;
long long ans;
int main()
{
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x>>y;
        ans = 0;
        int nr = y / x;
        int r = y % x;
        for (int i=1;i<=x;++i){
            if (i <= r){
                ans += 1LL * (nr+1)*(nr+1);
            } else {
                ans += 1LL * nr * nr;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
