#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
#define nmax 105
using namespace std;
vector<int>g[nmax];
int ans, x, n, k, a[nmax], root;
bool seen;
void dfs(int node, int lst){
    if (node == k){
        seen = true;
    }

    if (seen){
        ans += a[node];
    }

    for (auto x:g[node]){
        if (x == lst){
            continue;
        }
        dfs(x, node);
    }

    if (node == k){
        seen = false;
    }
}
int main()
{
    freopen("subarbore2.in","r",stdin);
    freopen("subarbore2.out","w",stdout);

    cin>>n>>k;
    for (int i=1;i<=n;++i){
        cin>>x;
        if (!x){
            root = i;
        } else {
            g[x].pb(i);
        }
    }
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }

    dfs(root, -1);
    cout<<ans<<'\n';

    fclose(stdin);
    fclose(stdout);
    return 0;
}
