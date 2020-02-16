#include <bits/stdc++.h>
#define nmax 1000005
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
using namespace std;
int n, r, m, x, y;
int viz[nmax];
vector<int>g[nmax];
bool bfs(int start, int depth){
    queue<pii>q;
    pii act;
    q.push(mp(start,0));
    if (viz[start] && viz[start] != start){
        return false;
    }
    viz[start] = start;
    while (!q.empty()){
        act = q.front();
        q.pop();
        if (act.second == depth){
            continue;
        }
        for (auto x:g[act.first]){
            if (viz[x]){
                if (viz[x] == start){
                    continue;
                }
                return false;
            }
            q.push(mp(x,act.second+1));
            viz[x] = start;
        }
    }
    return true;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d %d",&n,&r,&m);
        for (int i=1;i<=r;++i){
            scanf("%d %d",&x,&y);
            g[x].pb(y);
            g[y].pb(x);
        }
        bool ok = true;
        for (int i=1;i<=m;++i){
            scanf("%d %d",&x,&y);
            if (!ok){
                continue;
            }
            ok = bfs(x, y);
        }
        for (int i=1;i<=n;++i){
            if (!viz[i]){
                ok = false;
            }
        }
        if (ok){
            printf("Yes\n");
        } else {
            printf("No\n");
        }
        for (int i=1;i<=n;++i){
            g[i].clear();
            viz[i] = 0;
        }
    }
    return 0;
}
