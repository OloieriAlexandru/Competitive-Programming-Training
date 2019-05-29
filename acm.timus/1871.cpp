#include <bits/stdc++.h>
#define nmax 105
#define pb push_back
#define lmax 200
#define INF 999999999
using namespace std;
unordered_map<string,int>mp;
unordered_map<int,string>mpBack;
vector<pair<int,int>>G[nmax];
int n, nr, act, ans;
bool used[nmax];
string s, s2;
int cmin[nmax];
char es[lmax];
void check(string s)
{
    if (!mp.count(s))
    {
        ++act;
        mp[s] = act;
        mpBack[act] = s;
    }
}
int main()
{
    cin>>n;
    for (int i=1; i<=n; ++i)
    {
        cin>>s;
        //cout<<s.size()<<'\n';
        check(s);
        cin>>nr;
        for (int j=1; j<=nr; ++j)
        {
            cin>>s2;
            check(s2);
            G[mp[s]].pb(make_pair(mp[s2], s.size()+6));
        }
    }
    cin.get();
    cin.getline(es, lmax);
    int init = strlen(es);
    for (int i=1; i<=n; ++i)
        cmin[i] = INF;

    queue<int>q;
    cmin[1] = init;
    q.push(1);

    while(!q.empty())
    {
        int act = q.front();
        q.pop();
        for (auto x:G[act])
        {
            if (cmin[x.first] > cmin[act] + x.second && cmin[act] + x.second <= 140)
            {
                cmin[x.first] = cmin[act] + x.second;
                q.push(x.first);
            }
            else
            if (cmin[x.first] == INF)
            {
                cmin[x.first] = INF - 1;
            }
        }
    }

    for (int i=1; i<=n; ++i)
    {
        if (cmin[i] != INF)
            ++ans;
    }
    cout<<ans<<'\n';
    for (int i=1; i<=n; ++i)
        if (cmin[i]!=INF)
            cout<<mpBack[i]<<'\n';
    return 0;
}