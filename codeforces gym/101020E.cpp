#include <bits/stdc++.h>
#define nmax 22
using namespace std;
int n;
int dl[] = {-1,-1,1,1};
int dc[] = {-1,1,-1,1};
bool interior(int i, int j)
{
    return i>=0&&j>=0&&i<n&&j<n;
}
bool uz[nmax][nmax];
int lee(int l, int c, int x, int y)
{
    queue<pair<int,pair<int,int>>>q;
    memset(uz,0,sizeof(uz));
    uz[l][c] = true;
    q.push(make_pair(0, make_pair(l, c)));
    if (l == x && y == c) return 0;
    while (!q.empty())
    {
        auto act = q.front();
        q.pop();
        int i = act.second.first;
        int j = act.second.second;
        for (int k=0; k<4; ++k)
        {
            if (!interior(i+dl[k], j+dc[k])) continue;
            if (uz[i+dl[k]][j+dc[k]]) continue;
            if (i+dl[k] == x && j+dc[k] == y) return act.first + 1;
            uz[i+dl[k]][j+dc[k]] = true;
            q.push(make_pair(act.first+1,make_pair(i+dl[k],j+dc[k])));
        }
    }
    return -1;
}
int main()
{
    int t;
    int xs, ys, xf, yf;
    cin>>t;
    cin>>n;
    while (t--)
    {
        cin>>xs>>ys;
        cin>>xf>>yf;
        int res = lee(xs,ys,xf,yf);
        if (res == -1)
            cout<<"can't reach!\n";
        else
            cout<<res<<'\n';
    }
    return 0;
}
