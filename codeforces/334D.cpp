#include <bits/stdc++.h>
#define nmax 1005
#define inf 999999999
using namespace std;
int n, m, v1, v2, x, y;
int minL[nmax], maxL[nmax], minC[nmax], maxC[nmax];
bool can1[nmax], can2[nmax];
int main()
{
    cin>>n>>m;
    for (int i=1;i<=n;++i)
        minL[i] = minC[i] = inf;
    for (int i=1;i<=m;++i)
    {
        cin>>x>>y;
        minL[x] = min(minL[x], y);
        maxL[x] = max(maxL[x], y);
        minC[y] = min(minC[y], x);
        maxC[y] = max(maxC[y], x);
    }
    for (int i=2;i<n;++i){
        if (minC[i] == inf){
            can1[i] = true;
        }
        if (minL[i] == inf){
            can2[i] = true;
        }
    }
    int ans = 0;
    for (int i=2;i<n;++i){
        if (can1[i]) ++ans;
        if (can2[i]) ++ans;
        if (can1[i] && can2[i] && n % 2 && i == n/2+1) --ans;
    }
    cout<<ans<<'\n';
    return 0;
}
