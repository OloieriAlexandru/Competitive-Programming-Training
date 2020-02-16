#include <bits/stdc++.h>
#define pii pair<int,int>
#define vv vector<vector<int> >
#define prt(x) for (auto l:x){for(auto c:l) cout<<c<<' '; cout<<'\n';} cout<<'\n';
using namespace std;
map<vv,int>mp;
queue<vv>q;
set<vv>st, seen;
int n, m, minn = 11, maxx, nw;
void init(vv& x){
    x.resize(n,vector<int>(m));
}
int main()
{
    freopen("joc15.in","r",stdin);
    freopen("joc15.out","w",stdout);
    cin>>n>>m;
    vv in;
    init(in);
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            cin>>in[i][j];
            minn=min(minn,in[i][j]);
        }
    }
    mp[in] = 0;
    q.push(in);
    while (!q.empty()){
        vv act = q.front(); q.pop();
        st.erase(act);
        nw = mp[act];
        for (int i=0;i<n-1;++i){
            for (int j=0;j<m-1;++j){
                maxx = act[i][j];
                if (act[i][j+1] > maxx){
                    maxx = act[i][j+1];
                }
                if (act[i+1][j] > maxx){
                    maxx = act[i+1][j];
                }
                if (act[i+1][j+1] > maxx){
                    maxx = act[i+1][j+1];
                }
                if (maxx == minn){
                    continue;
                }
                vv cp = act;
                cp[i][j] = cp[i+1][j] = cp[i][j+1] = cp[i+1][j+1] = minn;
                if (!seen.count(cp)){
                    seen.insert(cp);
                    st.insert(cp);
                    q.push(cp);
                    mp[cp] = nw + maxx - minn;
                    continue;
                }
                if (mp[cp] > nw + maxx - minn){
                    mp[cp] = nw + maxx - minn;
                    if (!st.count(cp)){
                        st.insert(cp);
                        q.push(cp);
                    }
                }
            }
        }
    }
    vv ans;
    init(ans);
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            ans[i][j]=minn;
        }
    }
    cout<<mp[ans]<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
