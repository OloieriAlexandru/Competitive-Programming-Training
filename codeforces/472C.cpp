#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define nmax 100005
using namespace std;
int n, perm[nmax];
string s1, s2;
vector<pair<string,string>>v;
vector<string>ans;
int main()
{
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>s1>>s2;
        if (s1 > s2) swap(s1, s2);
        v.pb(mp(s1,s2));
    }
    cin>>perm[1];
    ans.pb(v[perm[1]-1].first);
    for (int i=2;i<=n;++i)
    {
        cin>>perm[i];
        if (ans.back() <= v[perm[i]-1].first)
            ans.pb(v[perm[i]-1].first);
        else
        if (ans.back() <= v[perm[i]-1].second)
            ans.pb(v[perm[i]-1].second);
        else
        {
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
    return 0;
}
