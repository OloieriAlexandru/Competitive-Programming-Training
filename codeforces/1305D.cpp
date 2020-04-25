#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
#define nmax 1005
using namespace std;
int n, x, y, ans, q;
bool ok;
vector<int>g[nmax];
int ask(int a, int b, bool& stp){
    if (!(a>=1&&a<=n)){
        stp = true;
        return ans;
    }
    if (!(b>=1&&b<=n)){
        stp = true;
        return ans;
    }
    if (q >= n/2){
        stp = true;
        return ans;
    }
    if (a == b){
        stp = true;
        return ans;
    }
    ++q;
    cout<<"? "<<a<<' '<<b<<'\n';
    cout.flush();
    int ans;
    cin>>ans;
    return ans;
}
int maxx, nd;
vector<int>p1, p2, p;
void dfs(int k, int lst, int lvl){
    if (lvl > maxx){
        maxx = lvl;
        nd = k;
    }
    for (int i=0;i<g[k].size();++i){
        if (g[k][i] == lst){
            continue;
        }
        dfs(g[k][i], k, lvl+1);
    }
}
void remv(int nd, int x){
    int rm = -1;
    for (int i=0;i<g[nd].size();++i){
        if (g[nd][i] == x){
            rm = i;
            break;
        }
    }
    if (rm == -1){
        return;
    }
    g[nd].erase(g[nd].begin()+rm);
}
void dfs2(int k, int lst, int wh){
    if (ok){
        return;
    }
    if (k == ans){
        ok = true;
        if (wh == 1){
            p1 = p;
        } else {
            p2 = p;
        }
        return;
    }
    for (int i=0;i<g[k].size();++i){
        if (g[k][i] == lst){
            continue;
        }
        p.pb(g[k][i]);
        dfs2(g[k][i], k, wh);
        if (ok){
            return;
        }
        p.pop_back();
    }
}
int main()
{
    cin>>n;
    for (int i=1;i<n;++i){
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    ans = 1;
    while (true){
        maxx = -1;
        dfs(ans, -1, 0);
        int n1 = nd, n2;
        maxx = -1;
        dfs(nd, -1, 0);
        n2 = nd;
        bool stp = false;
        ans = ask(n1, n2, stp);
        if (stp){
            break;
        }
        p.clear();
        p.push_back(n1);
        ok = false;
        dfs2(n1, -1, 1);

        p.clear();
        ok = false;
        p.push_back(n2);
        dfs2(n2, -1, 2);

        for (int i=0;i<p1.size();++i){
            if (g[p1[i]].size() <= 1 && p1[i] != ans){
                if (g[p1[i]].size() == 0){
                    continue;
                }
                remv(g[p1[i]][0], p1[i]);
                g[p1[i]].clear();
            } else {
                break;
            }
        }
        for (int i=0;i<p2.size();++i){
            if (g[p2[i]].size() <= 1 && p2[i] != ans){
                if (g[p2[i]].size() == 0){
                    continue;
                }
                remv(g[p2[i]][0], p2[i]);
                g[p2[i]].clear();
            } else {
                break;
            }
        }
    }
    cout<<"! "<<ans<<'\n';
    return 0;
}
