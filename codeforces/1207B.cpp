#include <bits/stdc++.h>
#define nmax 55
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
using namespace std;
int n, a[nmax][nmax], b[nmax][nmax], m;
bool ok = false;
vector<pii>ans;
int main()
{
    cin>>n>>m;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            cin>>a[i][j];
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
        {
            if (a[i][j] && a[i+1][j+1] && a[i][j+1] && a[i+1][j])
            {
                b[i][j] = 1, b[i+1][j] = 1, b[i+1][j+1] = 1, b[i][j+1] = 1;
                ans.pb(mp(i,j));
            }
            else if (a[i][j] && !b[i][j])
            {
                cout<<"-1\n";
                return 0;
            }
        }
    cout<<ans.size()<<'\n';
    for (auto x:ans)
        cout<<x.first<<' '<<x.second<<'\n';
    return 0;
}
