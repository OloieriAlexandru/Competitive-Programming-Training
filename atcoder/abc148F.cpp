#include <bits/stdc++.h>
#define pb push_back
#define nmax 200005
using namespace std;
vector<int>g[nmax];
int n, x, y, h[nmax], u, v, wh;
int lastNode[nmax], big[nmax], ans;
bool onPath[nmax];
void dfs1(int nod, int hei, int lst = -1){
    lastNode[nod] = lst;
    h[nod] = hei;
    if (nod == u){
        int curr = nod;
        while (curr != -1){
            onPath[curr] = true;
            curr = lastNode[curr];
        }
    }
    for (auto x:g[nod]){
        if (x == lst){
            continue;
        }
        dfs1(x, hei+1, nod);
    }
}
void dfs2(int nod, int lst = -1){
    for (auto x:g[nod]){
        if (x == lst || !onPath[x]){
            continue;
        }
        if (h[x] > h[u]-h[x]){
            ans = max(ans, big[x]-1);
        }
        if (nod != u){
            dfs2(x, nod);
        }
    }
}
void dfs3(int nod, int lst = -1){
    int leaf = true;
    for (auto x:g[nod]){
        if (x == lst){
            continue;
        }
        leaf = false;
        dfs3(x, nod);
    }
    if (leaf){
        big[nod] = h[nod];
    } else {
        int maxx = -1;
        for (auto x:g[nod]){
            if (x == lst){
                continue;
            }
            maxx = max(maxx, big[x]);
        }
        big[nod] = maxx;
    }
}
int main()
{
    cin>>n>>u>>v;
    for (int i=1;i<n;++i){
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs1(v, 0);
    dfs3(v);
    dfs2(v);
    cout<<ans<<'\n';
    return 0;
}
