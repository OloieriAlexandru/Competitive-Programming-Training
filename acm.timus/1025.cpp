#include <bits/stdc++.h>
using namespace std;
vector<int>ans;
int main()
{
    int n, a;
    cin>>n;
    for (int i=1; i<=n; ++i)
    {
        cin>>a;
        ans.push_back(a/2 + 1);
    }
    sort(ans.begin(), ans.end());
    int anss = 0;
    for (int i=0;i<n/2 + 1;++i)
        anss += ans[i];
    cout<<anss<<'\n';
    return 0;
}
