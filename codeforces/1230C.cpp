#include <bits/stdc++.h>
#define nmax 7
#define pb push_back
using namespace std;
int n, m, x, y, taken[nmax][nmax], ans, c1, c2;
int color[nmax];
vector<pair<int,int>>edges;
void rec(int k)
{
    if (k == 8)
    {
        int cnt = 0;
        memset(taken,0,sizeof(taken));
        for(auto edge:edges)
        {
            x = edge.first;
            y = edge.second;
            c1 = color[x];
            c2 = color[y];
            if (c1 > c2)
                swap(c1,c2);
            if (!taken[c1][c2])
                ++cnt, taken[c1][c2] = true;
        }
        ans = max(ans, cnt);
        return;
    }
    for (int i=1;i<=6;++i)
    {
        color[k] = i;
        rec(k+1);
    }
}
int main()
{
    cin>>n>>m;
    for (int i=1;i<=m;++i)
    {
        cin>>x>>y;
        edges.pb(make_pair(x,y));
    }
    if (n <= 6)
    {
        cout<<m<<'\n';
        return 0;
    }
    rec(1);
    cout<<ans<<'\n';
    return 0;
}
