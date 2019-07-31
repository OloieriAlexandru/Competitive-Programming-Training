#include <bits/stdc++.h>
#define pii pair<int,int>
#define nmax 805
#define mkp make_pair
#define lld long long
#define inf 1000000000000000LL
using namespace std;
int n, m, k, nn;
int x, y, w;
vector<pair<int,pii>>edges;
set<int>st;
map<int,int>mp;
lld rf[nmax][nmax];
vector<lld>ans;
int main()
{
    cin>>n>>m>>k;
    for (int i=1; i<=m; ++i)
    {
        cin>>x>>y>>w;
        edges.push_back(mkp(w,mkp(x,y)));
    }
    sort(edges.begin(), edges.end());
    nn = min(m, k);
    for (int i=0; i<nn; ++i)
    {
        st.insert(edges[i].second.first);
        st.insert(edges[i].second.second);
    }
    int ind = 0;
    for (auto x:st)
        mp[x] = ind++;
    for (int i=0; i<ind; ++i)
        for (int j=0; j<ind; ++j)
            if (i != j)
                rf[i][j] = inf;
    for (int i=0; i<nn; ++i)
    {
        x = mp[edges[i].second.first];
        y = mp[edges[i].second.second];
        rf[x][y] = rf[y][x] = edges[i].first;
    }
    for (int k=0; k<ind; ++k)
        for (int i=0; i<ind; ++i)
            for (int j=0; j<ind; ++j)
                if (rf[i][k] + rf[k][j] < rf[i][j])
                    rf[i][j] = rf[i][k] + rf[k][j];
    for (int i=0; i<ind; ++i)
        for (int j=i+1; j<ind; ++j)
            ans.push_back(rf[i][j]);
    sort(ans.begin(), ans.end());
    cout<<ans[k-1]<<'\n';
    return 0;
}
