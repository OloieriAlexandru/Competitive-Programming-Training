#include <bits/stdc++.h>
#define nmax 100005
using namespace std;
int nrsol[nmax], lst[nmax], a[105], n, g;
bool notMissing[105];
vector<int>ans;
int main()
{
    cin>>g;
    cin>>n;
    for (int i=1; i<=n; ++i)
        cin>>a[i];
    nrsol[0] = 1;
    for (int i=1; i<=n; ++i)
        for (int j=nmax-1; j>=1; --j)
        {
            if (j - a[i] < 0) break;
            if (nrsol[j-a[i]])
                nrsol[j] += nrsol[j-a[i]];
            if (nrsol[j-a[i]] && !lst[j])
                lst[j] = i;
        }
    if (nrsol[g] > 1)
    {
        cout<<"-1\n";
        return 0;
    }
    if (nrsol[g] == 0)
    {
        cout<<"0\n";
        return 0;
    }
    while (g > 0)
    {
        notMissing[lst[g]] = true;
        g -= a[lst[g]];
    }
    for (int i=1;i<=n;++i)
        if (!notMissing[i])
            cout<<i<<' ';
    cout<<'\n';
    return 0;
}
