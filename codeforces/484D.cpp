#include <bits/stdc++.h>
#define lld long long
#define nmax 1000005
using namespace std;
int n, a[nmax];
lld dp[nmax];
bool interest[nmax];
vector<int>v;
int main()
{
    scanf("%d",&n);
    for (int i=1; i<=n; ++i)
        scanf("%d",&a[i]);
    interest[1] = 1;
    for (int i=2; i<n; ++i)
    {
        if (a[i] >= a[i-1] && a[i] >= a[i+1]) interest[i] = 1, interest[i+1] = 1, interest[i-1] = 1;
        if (a[i] <= a[i-1] && a[i] <= a[i+1]) interest[i] = 1, interest[i+1] = 1, interest[i-1] = 1;
    }
    dp[1] = 0;
    v.push_back(1);
    for (int i=2; i<=n; ++i)
    {
        dp[i] = dp[i-1];
        for (int j=v.size()-1,nr=0; j>=0 && nr <= 50; --j,++nr)
            dp[i] = max(dp[i], dp[v[j]-1] + abs(a[v[j]]-a[i]));
        if (interest[i])
            v.push_back(i);
    }
    cout<<dp[n]<<'\n';
    return 0;
}
