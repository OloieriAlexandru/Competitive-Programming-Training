#include <bits/stdc++.h>
#define inf 999999999
#define nmax 200005
using namespace std;
unordered_map<int,int>fv;
int a[nmax];
int main()
{
    int t, n, k, d;
    cin>>t;
    while (t--)
    {
        cin>>n>>k>>d;
        fv.clear();
        int ans = inf, curr = 0;
        for (int i=1; i<=d; ++i)
        {
            cin>>a[i];
            if (!fv[a[i]])
            {
                ++curr;
            }
            ++fv[a[i]];
        }
        for (int i=d+1; i<=n; ++i)
        {
            cin>>a[i];
            ans = min(ans, curr);
            if (fv[a[i-d]] == 1)
            {
                --curr;
            }
            --fv[a[i-d]];
            if (!fv[a[i]])
            {
                ++curr;
            }
            ++fv[a[i]];
            ans = min(ans, curr);
        }
        ans = min(ans, curr);
        cout<<ans<<'\n';
    }
    return 0;
}
