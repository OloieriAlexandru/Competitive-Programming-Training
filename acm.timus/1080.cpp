#include <bits/stdc++.h>
#define pb push_back
#define nmax 101
using namespace std;
vector<int>g[nmax];
bool ok, uz[nmax];
int ans[nmax], x, n;
void dfs(int k, int col){
    if (ok){
        return;
    }
    uz[k] = true;
    ans[k] = col;
    for (auto x:g[k]){
        if (ans[x] != 0){
            if (ans[x] == col){
                ok = true;
                return;
            }
        }
        if (uz[x]){
            continue;
        }
        dfs(x, 3-col);
        if (ok){
            return;
        }
    }
}
int main()
{
    cin>>n;
    for (int i=1;i<=n;++i){
        while(true){
            cin>>x;
            if (!x){
                break;
            }
            g[x].pb(i);
            g[i].pb(x);
        }
    }
    for (int i=1;i<=n;++i){
        if (uz[i]){
            continue;
        }
        dfs(i, 1);
    }
    if (ok){
        cout<<"-1\n";
    } else {
        for (int i=1;i<=n;++i){
            cout<<ans[i]-1;
        }
        cout<<'\n';
    }
    return 0;
}
