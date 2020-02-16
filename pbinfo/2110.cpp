#include <bits/stdc++.h>
#define nmax 1005
using namespace std;
vector<int>g[nmax], gt[nmax];
int post[nmax], n, cnt, x, vote[nmax];
bool uz[nmax];
vector<int>ans,cc;
void dfs1(int k){
    uz[k] = true;
    for (auto x:g[k]){
        if (!uz[x]){
            dfs1(x);
        }
    }
    post[++cnt] = k;
}
void dfs2(int k){
    cc.push_back(k);
    uz[k] = false;
    for (auto x:gt[k]){
        if (uz[x]){
            dfs2(x);
        }
    }
}
int main()
{
    freopen("vot.in","r",stdin);
    freopen("vot.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x;
        vote[i] = x;
        g[i].push_back(x);
        gt[x].push_back(i);
    }
    for (int i=1;i<=n;++i){
        if (uz[i]){
            continue;
        }
        dfs1(i);
    }
    for (int i=n;i>=1;--i){
        if (!uz[post[i]]){
            continue;
        }
        cc.clear();
        dfs2(post[i]);
        if (cc.size()>=2){
            for (auto x:cc){
                ans.push_back(x);
            }
        } else {
            if (vote[cc[0]] == cc[0]){
                ans.push_back(cc[0]);
            }
        }
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<'\n';
    for (auto x:ans){
        cout<<x<<' ';
    }
    cout<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
