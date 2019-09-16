#include <bits/stdc++.h>
#define nmax 200001
#define inf 1999999999
using namespace std;
vector<int>v[nmax];
int n, k, x, act, ans = inf;
int main()
{
    scanf("%d %d",&n,&k);
    for (int i=1;i<=n;++i)
    {
        scanf("%d",&x);
        act = 0;
        while (x)
        {
            v[x].push_back(act);
            ++act;
            x /= 2;
        }
    }
    for (int i=1;i<=200000;++i)
    {
        if (k > v[i].size()) continue;
        sort(v[i].begin(),v[i].end());
        act = 0;
        for (int j=0;j<k;++j)
            act += v[i][j];
        ans = min(ans, act);
    }
    printf("%d\n", ans);
    return 0;
}
