#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define nmax 1001003
#define lld long long
#define ld long double
#define pb push_back
using namespace std;
int a[nmax], b[nmax], s1[nmax], s2[nmax];
int n, diff, ans;
int main()
{
    freopen("2sec.in","r",stdin);
    freopen("2sec.out","w",stdout);

    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    for (int i=1;i<=n;++i){
        s1[i] = a[i] + min(0,s1[i-1]);
    }
    for (int i=n;i>=1;--i){
        s2[i] = a[i] + max(0,s2[i+1]);
    }
    for (int i=1;i<n;++i){
        diff = s2[i+1] - s1[i];
        if (diff > ans){
            ans = diff;
        }
    }
    cout<<ans<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
