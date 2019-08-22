#include <bits/stdc++.h>
#define nmax 105
using namespace std;
unordered_map<string,int>fv;
string s;
int p[nmax], a[nmax], ans1, ans2;
int main()
{
    int n, m;
    cin>>n>>m;
    for (int i=1;i<=n;++i)
        cin>>p[i];
    for (int i=1;i<=m;++i)
    {
        cin>>s;
        ++fv[s];
    }
    int it = 0;
    for (auto x:fv)
        a[++it] = x.second;
    auto desc = [](int a, int b){ return a > b; };
    sort(a+1,a+it+1,desc);
    sort(p+1,p+n+1);
    for (int i=1;i<=it;++i)
        ans1 += a[i]*p[i];
    sort(p+1,p+n+1,desc);
    for (int i=1;i<=it;++i)
        ans2 += a[i]*p[i];
    cout<<ans1<<' '<<ans2<<'\n';
    return 0;
}
