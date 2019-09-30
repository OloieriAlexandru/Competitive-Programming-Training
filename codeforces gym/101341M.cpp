#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>>v;
vector<pair<int,int>>ans;
queue<int>q;
int x, n, dead;
int main()
{
    cin>>n;
    for (int i=1; i<=n; ++i)
    {
        cin>>x;
        v.push_back(make_pair(x,i));
    }
    sort(v.begin(), v.end());
    for (int i=0; i<v.size(); ++i)
    {
        if (!v[i].first)
        {
            ++dead;
            q.push(v[i].second);
            continue;
        }
        if (v[i].first > dead)
        {
            cout<<"NO\n";
            return 0;
        }
        for (int j=0; j<v[i].first; ++j)
        {
            --dead;
            ans.push_back(make_pair(v[i].second, q.front()));
            q.pop();
        }
        ++dead;
        q.push(v[i].second);
    }
    cout<<"YES\n";
    for (auto x:ans)
        cout<<x.first<<' '<<x.second<<'\n';
    return 0;
}
