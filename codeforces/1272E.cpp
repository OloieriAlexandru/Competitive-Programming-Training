#include <bits/stdc++.h>
#define nmax 200005
#define pb push_back
#define inf 999999999
#define pii pair<int,int>
#define mp make_pair
using namespace std;
int ans[nmax], n, a[nmax];
vector<int>g[nmax];
bool uz[nmax];
void bfs(int r){
    queue<pii>q;
    memset(uz,0,sizeof(uz));
    for (int i=1;i<=n;++i){
        if (a[i]%2==r){
            uz[i] = true;
            q.push(mp(i,0));
        }
    }
    while(!q.empty()){
        auto act = q.front();
        q.pop();
        int node = act.first;
        int dist = act.second;
        if (a[node]%2==(1-r)){
            ans[node] = min(ans[node], dist);
        }
        for (auto x:g[node]){
            if (uz[x]){
                continue;
            }
            q.push(mp(x,dist+1));
            uz[x] = true;
        }
    }
}
int main()
{
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        ans[i] = inf;
    }
    for (int i=1;i<=n;++i){
        int val = i - a[i];
        if (val >= 1){
            g[val].pb(i);
        }
        val = i + a[i];
        if (val <= n){
            g[val].pb(i);
        }
    }
    bfs(1);
    bfs(0);
    for (int i=1;i<=n;++i){
        if (ans[i] == inf){
            cout<<"-1 ";
        } else {
            cout<<ans[i]<<' ';
        }
    }
    return 0;
}
