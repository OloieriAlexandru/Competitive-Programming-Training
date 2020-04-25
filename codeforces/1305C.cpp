#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
#define nmax 200005
using namespace std;
int n, m, a[nmax];
int main()
{
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    if (n > m){
        printf("0\n");
        return 0;
    }
    lld ans = 1;
    for (int i=1;i<n;++i){
        for (int j=i+1;j<=n;++j){
            ans *= (abs(a[i]-a[j]));
            ans %= m;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
