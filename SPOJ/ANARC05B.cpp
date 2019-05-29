#include <iostream>
#include <map>
#include <utility>
#include <vector>
#define mp make_pair
#define pii pair<int,int>
#define pb push_back
#define LMAX 10005
using namespace std;

int n1, n2;
int a1[LMAX];
int s1[LMAX];
int a2[LMAX];
int s2[LMAX];

void solve()
{
    int x;
    int ans = 0;
    vector<pii>v;
    vector<pii>sums;
    map<int,int>m;
    for (int i=1;i<=n1;++i)
    {
        cin>>x;
        m[x] = i;
        a1[i] = x;
        s1[i] = s1[i-1] + x;
    }
    cin>>n2;
    for (int i=1;i<=n2;++i)
    {
        cin>>x;
        a2[i] = x;
        s2[i] = s2[i-1] + x;
    }

    for (int i=1;i<=n2;++i)
    {
        x = a2[i];
        if (m.count(x))
        {
            v.pb(mp(m[x], i));
        }
    }
    v.pb(mp(n1,n2));
    int last1 = 0, last2 = 0;
    for (int i=0;i<v.size();++i)
    {
        sums.pb(mp(s1[v[i].first] - s1[last1], s2[v[i].second] - s2[last2]));
        last1 = v[i].first;
        last2 = v[i].second;
    }
    for (int i=0;i<sums.size();++i)
    {
        ans+=max(sums[i].first, sums[i].second);
    }
    cout<<ans<<'\n';
    for (int i=1;i<=n1;++i)
    {
        s1[i] = a1[i] = 0;
    }
    for (int i=1;i<=n2;++i)
    {
        s2[i] = a2[i] = 0;
    }
}

int main()
{
    while(cin>>n1)
    {
        if (!n1)
        {
            break;
        }
        else
        solve();
    }
    return 0;
}
