#include <bits/stdc++.h>
#define nmax 205
#define pdd pair<double,double>
#define mp make_pair
#define pb push_back
#define pid pair<int,double>
#define INF 999999999
using namespace std;
vector<pdd>stations;
vector<pid>g[nmax];
double sp1, sp2;
double x, y;
int n;
bool conn[nmax][nmax];
double xs, ys, xf, yf;
double x1, y1, x2, y2;
int start, finish;
double d;
double dst(double x1, double y1, double x2, double y2)
{
    return sqrt((double)(x2-x1)*(x2-x1) + (double)(y2-y1)*(y2-y1));
}
queue<int>qu;
int last[nmax];
vector<int>ans;
double cmin[nmax];
int main()
{
    cin>>sp1>>sp2;
    scanf("%d",&n);
    for (int i=0;i<n;++i)
    {
        cin>>x>>y;
        stations.push_back(mp(x,y));
    }
    int x, y;
    while(scanf("%d %d",&x,&y))
    {
        if (!x && !y) break;
        --x, --y;
        conn[x][y] = conn[y][x] = true;
    }
    cin>>xs>>ys;
    cin>>xf>>yf;
    stations.push_back(mp(xs,ys));
    stations.push_back(mp(xf,yf));
    start = n;
    finish = n+1;
    n+=2;
    for (int i=0;i<n;++i)
    {
        for (int j=i+1;j<n;++j)
        {
            x1 = stations[i].first;
            y1 = stations[i].second;

            x2 = stations[j].first;
            y2 = stations[j].second;

            d = dst(x1,y1,x2,y2);
            if (conn[i][j])
                d/=sp2;
            else
                d/=sp1;
            g[i].pb(mp(j,d));
            g[j].pb(mp(i,d));
        }
    }
    for (int i=0;i<n;++i)
        cmin[i] = INF, last[i] = -1;
    cmin[start] = 0;
    qu.push(start);
    while (!qu.empty())
    {
        auto act = qu.front();
        qu.pop();
        for (auto nd : g[act])
        {
            if (cmin[nd.first] > cmin[act] + nd.second)
            {
                cmin[nd.first] = cmin[act] + nd.second;
                last[nd.first] = act;
                qu.push(nd.first);
            }
        }
    }
    cout<<setprecision(8)<<fixed<<cmin[finish]<<'\n';
    while(true)
    {
        if (last[finish] == -1) break;
        if (finish<n-2)
            ans.push_back(finish);
        finish = last[finish];
    }
    reverse(ans.begin(), ans.end());
    cout<<ans.size()<<' ';
    for (auto af:ans)cout<<af+1<<' ';
    cout<<'\n';
    return 0;
}