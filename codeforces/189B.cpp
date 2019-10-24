#include <bits/stdc++.h>
#define lld long long
using namespace std;
lld n, m, ans;
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;i+=2)
        for (int j=1;j<=m;j+=2)
            ans += (n-i)*(m-j);
    cout<<ans<<'\n';
    return 0;
}
