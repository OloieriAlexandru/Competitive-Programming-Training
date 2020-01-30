#include <bits/stdc++.h>
#define nmax 200005
using namespace std;
set<int>g[nmax];
int n, lst[26], ans;
bool uz[nmax];
string s;
void dfs (int k){
    uz[k] = true;
    for (auto x:g[k]){
        if (uz[x]){
            continue;
        }
        dfs(x);
    }
}
int main()
{
    cin>>n;
    for (int i=0;i<26;++i){
        lst[i]=-1;
    }
    for (int i=1;i<=n;++i){
        cin>>s;
        for (auto x:s){
            int ch=x-'a';
            if (lst[ch]==-1){
                lst[ch]=i;
            }
            if (lst[ch]==i){
                continue;
            }
            g[lst[ch]].insert(i);
            g[i].insert(lst[ch]);
            lst[ch]=i;
        }
    }
    for (int i=1;i<=n;++i){
        if (uz[i]){
            continue;
        }
        ++ans;
        dfs(i);
    }
    cout<<ans<<'\n';
    return 0;
}
