#include <bits/stdc++.h>
#define mkp make_pair
using namespace std;
int n, m, x, y, ans1, ans2, v1, v2, minn;
bool ex1[1005], ex2[1005];
map<pair<int,int>,int>mp1;
map<pair<int,int>,int>mp2;
pair<int,int>p1;
int main()
{
    scanf("%d %d",&n,&m);
    for (int i=1; i<=n; ++i)
    {
        scanf("%d %d",&x,&y);
        swap(x,y);
        ex1[x] = true;
        ++mp1[mkp(x,y)];
    }
    for (int i=1; i<=m; ++i)
    {
        scanf("%d %d",&x,&y);
        swap(x,y);
        ex2[x] = true;
        ++mp2[mkp(x,y)];
    }
    for (int i=1; i<=1000; ++i)
        for (int j=1; j<=1000; ++j)
        {
            if (!ex1[i] || !ex2[i]) continue;
            p1 = mkp(i,j);
            minn = mp1[p1];
            minn = min(minn, mp2[p1]);
            mp1[p1] -= minn;
            mp2[p1] -= minn;
            ans2 += minn;
        }
    for (int i=1; i<=1000; ++i)
    {
        if (!ex1[i] || !ex2[i]) continue;
        v1 = 0;
        v2 = 0;
        for (int j=1; j<=1000; ++j)
        {
            p1 = mkp(i,j);
            v1 += mp1[p1];
            v2 += mp2[p1];
        }
        ans1 += min(v1, v2);
    }
    cout<<ans1+ans2<<' '<<ans2<<'\n';
    return 0;
}
