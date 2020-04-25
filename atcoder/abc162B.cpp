#include <bits/stdc++.h>
#define pii pair<int,int>
#define pb push_back
#define nmax
#define inf
using namespace std;

int main()
{
    long long ans = 0;
    int n;
    cin>>n;
    for (int i=1;i<=n;++i){
        if (i % 5 == 0 || i % 3 == 0){
            continue;
        }
        ans += i;
    }
    cout<<ans<<'\n';
    return 0;
}
