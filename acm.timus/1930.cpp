#include <bits/stdc++.h>
#define nmax 10005
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define inf 999999999
using namespace std;
int n, m, x, y, start, last, ans[nmax];
vector<pii>g[nmax];
void bfs(int k){
    for (int i=1;i<=n;++i){
        ans[i] = inf;
    }
    ans[k] = 0;
    queue<pii>q;
    q.push(mp(k,0));
    q.push(mp(k,1));
    while (!q.empty()){
        auto act = q.front();
        q.pop();
        for (auto x:g[act.first]){
            if (act.second == x.second){
                if (ans[x.first] > ans[act.first]){
                    ans[x.first] = ans[act.first];
                    q.push(mp(x.first,x.second));
                }
            } else {
                if (ans[x.first] > ans[act.first] + 1){
                    ans[x.first] = ans[act.first] + 1;
                    q.push(mp(x.first, x.second));
                }
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    for (int i=1;i<=m;++i){
        cin>>x>>y;
        g[x].pb(make_pair(y, 0));
        g[y].pb(make_pair(x, 1));
    }
    cin>>start>>last;
    bfs(start);
    cout<<ans[last]<<'\n';
    return 0;
}
