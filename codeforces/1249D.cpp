#include <bits/stdc++.h>
#define nmax 200005
#define pii pair<int,int>
using namespace std;
int n, k, x, y;
vector<pii>a[nmax];
int main()
{
    cin>>n>>k;
    int nn = 0;
    for (int i=1;i<=n;++i)
    {
        cin>>x>>y;
        a[x].push_back(make_pair(y, i));
        nn = max(nn, y);
    }
    vector<int>ans;
    set<pair<int,int>>st;
    for (int i=1;i<=nn;++i)
    {
        for (auto x:a[i])
            st.insert(x);
        while (!st.empty() && (*st.begin()).first < i){
            st.erase(st.begin());
        }
        while (st.size() > k){
            ans.push_back((*st.rbegin()).second);
            auto it = *st.rbegin();
            st.erase(it);
        }
    }
    cout<<ans.size()<<'\n';
    for (auto x:ans)
        cout<<x<<' ';
    return 0;
}
