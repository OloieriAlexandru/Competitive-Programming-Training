#include <bits/stdc++.h>
#define lld long long
#define nmax 300
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
using namespace std;
int t, n, start, endd;
char s[nmax];
bool uz[nmax];
vector<int>g[nmax];
vector<pair<vector<int>,int>>fv;
int bfs(int k, int to)
{
    queue<pair<int,int>>q;
    memset(uz,0,sizeof(uz));
    q.push(make_pair(k,0));
    while (!q.empty())
    {
        auto act = q.front();
        q.pop();
        if (act.first == to)
            return act.second;
        for (auto x:g[act.first])
        {
            if (uz[x]) continue;
            uz[x] = true;
            q.push(make_pair(x, act.second+1));
        }
    }
    return -1;
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>start>>endd;
        fv.clear();
        for (int i=1; i<=n; ++i)
        {
            cin>>s;
            vector<int>actfv;
            actfv.resize(10, 0);
            for (int j=0; j<20; ++j)
                ++actfv[s[j]-'0'];
            for (auto x:fv)
            {
                int common = 0;
                for (int j=0; j<10; ++j)
                    common += min(x.first[j], actfv[j]);
                if (common == 17)
                {
                    g[i].push_back(x.second);
                    g[x.second].push_back(i);
                }
            }
            fv.push_back(make_pair(actfv, i));
        }
        cout<<bfs(start, endd)<<'\n';
        for (int i=1; i<=n; ++i)
            g[i].clear();
    }
    return 0;
}
