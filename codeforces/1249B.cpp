#include <bits/stdc++.h>
#define nmax 200005
using namespace std;
int nxt[nmax], cc[nmax], ccc, sz[nmax], curr, n;
bool uz[nmax];
void dfs(int k)
{
    if (uz[k]) return;
    ++curr;
    uz[k] = true;
    cc[k] = ccc;
    dfs(nxt[k]);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for (int i=1;i<=n;++i)
            cin>>nxt[i];
        ccc = 0;
        for (int i=1;i<=n;++i)
        {
            if (uz[i]) continue;
            curr = 0;
            ++ccc;
            dfs(i);
            sz[ccc] = curr;
        }
        for (int i=1;i<=n;++i)
        {
            cout<<sz[cc[i]]<<' ';
            uz[i] = false;
        }
        cout<<'\n';
    }
    return 0;
}
