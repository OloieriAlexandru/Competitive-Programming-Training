#include <bits/stdc++.h>
#define nmax 100001
using namespace std;
vector<pair<int,int>>av[nmax];
vector<int>ans;
priority_queue<pair<int,int>>pq;
int n, x, y;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        scanf("%d %d",&x,&y);
        av[x].push_back(make_pair(y,i));
    }
    for (int i=nmax-1;i>=1;--i){
        for (auto x:av[i]){
            pq.push(x);
        }
        if (pq.empty()){
            continue;
        }
        ans.push_back(pq.top().second);
        pq.pop();
    }
    cout<<ans.size()<<'\n';
    reverse(ans.begin(),ans.end());
    for (auto x:ans){
        cout<<x<<' ';
    }
    cout<<'\n';
    return 0;
}
