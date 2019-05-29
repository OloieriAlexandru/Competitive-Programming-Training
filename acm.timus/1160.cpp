#include <bits/stdc++.h>
#define nmax 1005
#define mp make_pair
#define pii pair<int,pair<int,int>>
#define pb push_back
using namespace std;
int h[nmax], t[nmax];
int n, m;
int x, y, c;
int c1, c2;
priority_queue<pii, vector<pii>, greater<pii> >pq;
vector<pair<int,int>>anss;
int ans, af1;
int findd(int x)
{
    int cx = x, up;
    while (t[x]) x = t[x];
    if (x != cx) while (t[cx]) up = t[cx], t[cx] = x, cx = up;
    return cx;
}
void unionn(int x, int y)
{
    if (h[x] > h[y])
        t[y] = x;
    else if (h[x] < h[y])
        t[x] = y;
    else
        ++h[x], t[x] = y;
}
int main()
{
    scanf("%d %d",&n,&m);
    for (int i=1;i<=m;++i)
    {
        scanf("%d %d %d",&x,&y,&c);
        pq.push(mp(c,mp(x,y)));
    }
    while (!pq.empty())
    {
        x = pq.top().second.first;
        y = pq.top().second.second;
        c = pq.top().first;
        pq.pop();
        c1 = findd(x);
        c2 = findd(y);
        if (c1 != c2)
        {
            af1 = c;
            ans += c;
            unionn(c2, c1);
            anss.pb(mp(x,y));
        }
    }
    cout<<af1<<'\n'<<anss.size()<<'\n';
    for (auto x:anss)
        cout<<x.first<<' '<<x.second<<'\n';
    return 0;
}