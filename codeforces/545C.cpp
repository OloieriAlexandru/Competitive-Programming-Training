#include <bits/stdc++.h>
using namespace std;
#define nmax 100005
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
vector<pii>woods;
int n, x, y, l, ans;
int main()
{
    cin>>n;
    for (int i=1; i<=n; ++i)
    {
        cin>>x>>y;
        woods.pb(mp(x,y));
    }
    sort(woods.begin(), woods.end());
    l = -2000000000;
    for (int i=0;i<woods.size();++i)
    {
        if (woods[i].first - woods[i].second > l)
            ++ans, l = woods[i].first;
        else
        if (i == n-1 || (woods[i].first + woods[i].second < woods[i+1].first))
            ++ans, l = woods[i].first + woods[i].second;
        else
            l = woods[i].first;
    }
    cout<<ans<<'\n';
    return 0;
}
