#include <bits/stdc++.h>
#define pb push_back
using namespace std;
int t, n, x, ans, r;
vector<int>v;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>r;
        v.clear();
        for (int i=1; i<=n; ++i)
        {
            cin>>x;
            v.pb(x);
        }
        sort(v.begin(), v.end(), [](int a, int b)
        {
            return a > b;
        });
        ans = 0;
        for (int i=0;i<v.size();++i)
        {
            if (v[i] - ans * r <= 0) break;
            ++ans;
            while (i < v.size()-1 && v[i] == v[i+1])++i;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
