#include <bits/stdc++.h>
#define nmax 405
using namespace std;
string s1, s2, s3;
int t, act, ans, nw, n, gi[nmax];
vector<int>g[nmax];
map<string,int>mp;
void process(string& a)
{
    if (!mp.count(a))
        mp[a] = ++act;
}
bool uz[nmax];
void dfs(int k, int lst)
{
    ++nw;
    ans = max(ans, nw);
    for (auto x:g[k])
    {
        if (x == lst) continue;
        dfs(x,k);
    }
    --nw;
}
int main()
{
    cin>>n;
    for (int i=1; i<=n; ++i)
    {
        cin>>s1>>s2>>s3;
        for (auto &x:s3)
            if (x >= 'A' && x <= 'Z')
                x = x - 'A' + 'a';
        for (auto &x:s1)
            if (x >= 'A' && x <= 'Z')
                x = x - 'A' + 'a';
        process(s1);
        process(s3);
        g[mp[s1]].push_back(mp[s3]);
        ++gi[mp[s3]];
    }
    for (int i=1; i<=act; ++i)
    {
        if (gi[i]) continue;
        nw = 0;
        dfs(i,-1);
    }
    cout<<ans<<'\n';
    return 0;
}
