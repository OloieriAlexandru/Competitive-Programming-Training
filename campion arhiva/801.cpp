#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
#define nmax 152
#define nmax2 1002
#define inf 999999999
using namespace std;

int n, k, dp[nmax], d[35][35];
char s[nmax2], *p;
bool visited[nmax];
vector<int>g[nmax];
string words[nmax];
set<string> st;

bool good(int ii, int jj){
    int n = words[ii].size();
    int m = words[jj].size();
    for (int j=0;j<=m;++j){
        d[n][j] = m-j;
    }
    for (int i=0;i<=n;++i){
        d[i][m] = n-i;
    }
    for (int i=n-1;i>=0;--i){
        for (int j=m-1;j>=0;--j){
            if (words[ii][i] == words[jj][j]){
                d[i][j] = d[i+1][j+1];
            } else {
                d[i][j] = inf;
            }
            if (d[i][j] > 1+d[i][j+1]){
                d[i][j] = 1+d[i][j+1];
            }
            if (d[i][j] > 1+d[i+1][j]){
                d[i][j] = 1+d[i+1][j];
            }
        }
    }

    return d[0][0] <= k;
}

void dfs(int k){
    if (visited[k]){
        return;
    }
    visited[k] = true;
    if (!g[k].size()){
        dp[k] = 1;
    } else {
        for (unsigned int i=0;i<g[k].size();++i){
            dfs(g[k][i]);
            dp[k] += dp[g[k][i]];
        }
    }
}

int main()
{
    freopen("lant.in","r",stdin);
    freopen("lant.out","w",stdout);
    cin>>k;
    cin.get();
    while (cin.getline(s, nmax2)){
        p = strtok(s, ",:;.!?- ");
        while (p){
            string act(p);
            if (!st.count(act)){
                st.insert(act);
                words[++n] = act;
            }
            p = strtok(NULL, ",:;.!?- ");
        }
    }
    for (int i=1;i<n;++i){
        for (int j=i+1;j<=n;++j){
            if (good(i,j)){
                g[i].pb(j);
            }
        }
    }
    dfs(1);
    cout<<dp[1]<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
