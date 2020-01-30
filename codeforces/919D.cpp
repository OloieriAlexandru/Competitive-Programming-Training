#include <bits/stdc++.h>
#define nmax 300005
#define pb push_back
using namespace std;
int n, m, ans, di[nmax], di1[nmax];
char s[nmax];
vector<int>g[nmax];
bool uz[nmax];
int dp[nmax][26], curr[26];
bool hasCycle(){
    queue<int>q;
    int cnt=0;
    for (int i=1;i<=n;++i){
        if (di[i]==0){
            q.push(i);
        }
    }
    while (!q.empty()){
        auto act=q.front();
        q.pop();
        ++cnt;
        for (auto x:g[act]){
            --di[x];
            if (!di[x]){
                q.push(x);
            }
        }
    }
    if (cnt!=n){
        return true;
    }
    return false;
}
void dfs2(int k, int lst){
    uz[k]=true;
    ++curr[s[k]-'a'];
    for (auto x:g[k]){
        if (x == lst){
            continue;
        }
        if (!uz[x]) {
            dfs2(x, k);
        }
        for (int j=0;j<26;++j){
            ans=max(ans,curr[j]+dp[x][j]);
        }
    }
    for (auto x:g[k]){
        if (x == lst){
            continue;
        }
        for (int j=0;j<26;++j){
            dp[k][j]=max(dp[k][j],dp[x][j]);
        }
    }
    ++dp[k][s[k]-'a'];
    --curr[s[k]-'a'];
}
int main()
{
    int x, y;
    cin>>n>>m;
    cin>>(s+1);
    for (int i=1;i<=m;++i){
        cin>>x>>y;
        g[x].pb(y);
        ++di[y];
        ++di1[y];
    }
    if (hasCycle()){
        cout<<"-1\n";
        return 0;
    }
    for (int i=1;i<=n;++i){
        if (di1[i]){
            continue;
        }
        dfs2(i,-1);
    }
    cout<<ans<<'\n';
    return 0;
}
