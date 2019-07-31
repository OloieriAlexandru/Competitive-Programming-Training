#include <bits/stdc++.h>
#define nmax 100005
using namespace std;
int n;
long long x;
long long sum;
map<int,long long>mp;
long long a[nmax];
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        cin>>x;
        a[i] = x;
        ++mp[x];
    }
    if (n == 1 && mp.count(0))
    {
        cout<<"cslnb\n";
        return 0;
    }
    bool ok = true;
    int cnt = 0;
    for (auto x:mp)
    {
        if (x.second > 2) ok = false;
        if (x.second > 1) ++cnt;
        if (x.second > 1 && mp.count(x.first-1)) ok = false;
    }
    if (mp[0] >= 2) ok = false;
    if (cnt > 1) ok = false;
    if (!ok)
        cout<<"cslnb\n";
    else
    {
        sort(a+1,a+n+1);
        for (int i=1;i<=n;++i)
            sum += max(0LL,a[i] - (i-1));
        if (sum % 2LL)
            cout<<"sjfnb\n";
        else
            cout<<"cslnb\n";
    }
    return 0;
}
