#include <bits/stdc++.h>
#define nmax 1005
using namespace std;
int n, m, a[nmax], sum;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        sum = 0;
        vector<pair<int,int>>v;
        for (int i=1;i<=n;++i){
            cin>>a[i];
            v.push_back(make_pair(a[i],i));
            sum += 2 * a[i];
        }
        if (m < n || (m == 2 && n == 2)){
            cout<<"-1\n";
            continue;
        }
        sort(v.begin(), v.end());
        int rm = m - n;
        int add = v[1].first + v[0].first;
        sum += add * rm;
        cout<<sum<<'\n';
        for (int i=1;i<=rm;++i){
            cout<<v[0].second<<' '<<v[1].second<<'\n';
        }
        for (int i=1;i<n;++i){
            cout<<i<<' '<<i+1<<'\n';
        }
        cout<<1<<' '<<n<<'\n';
    }
    return 0;
}
