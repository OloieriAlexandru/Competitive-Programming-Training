#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
#define nmax 105
using namespace std;
vector<int>g[nmax];
int n, k, x, root;
bool seen;
vector<int>ans;
void dfs(int node, int lst){
    ans.pb(node);
    if (node == k){
        seen = true;
        return;
    }
    for (auto x:g[node]){
        if (x == lst){
            continue;
        }
        dfs(x, node);
        if (seen){
            return;
        }
    }
    ans.pop_back();
}
int main()
{
    freopen("detdrum.in","r",stdin);
    freopen("detdrum.out","w",stdout);

    cin>>n>>k;
    for (int i=1;i<=n;++i){
        cin>>x;
        if (!x){
            root = i;
        } else {
            g[x].pb(i);
        }
    }

    dfs(root, -1);
    reverse(ans.begin(), ans.end());
    for (auto x:ans){
        cout<<x<<' ';
    }
    cout<<'\n';

    fclose(stdin);
    fclose(stdout);
    return 0;
}
