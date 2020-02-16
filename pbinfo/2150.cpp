#include <bits/stdc++.h>
#define pb push_back
#define nmax 10005
using namespace std;
vector<int>v[nmax];
priority_queue<int>pq;
int n, t, x, y, ans;
int main()
{
    freopen("credite.in","r",stdin);
    freopen("credite.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x>>y;
        v[y].pb(x);
        t = max(t, y);
    }
    for (int i=t;i>=1;--i){
        for (auto x:v[i]){
            pq.push(x);
        }
        if (!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
    }
    cout<<ans<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
