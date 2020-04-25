#include <bits/stdc++.h>
#define pii pair<int,int>
#define pb push_back
#define nmax
#define inf
using namespace std;

int main()
{
    int n;
    long long ans = 0;
    cin>>n;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            int gc = __gcd(i, j);
            for (int k=1;k<=n;++k){
                int gcc = __gcd(gc, k);
                ans += gcc;
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}
