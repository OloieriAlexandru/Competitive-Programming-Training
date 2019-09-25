#include <bits/stdc++.h>
#define nmax 100005
using namespace std;
int n, a[nmax], maxx[nmax], cnt[nmax];
int main()
{
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    maxx[n] = a[n];
    cnt[n] = 1;
    for (int i=n-1;i>=1;--i)
    {
        maxx[i] = maxx[i+1];
        cnt[i] = cnt[i+1];
        if (a[i] == maxx[i])
            ++cnt[i];
        else
        if (a[i] > maxx[i])
            maxx[i] = a[i], cnt[i] = 1;
    }
    for (int i=1;i<=n;++i)
    {
        if (a[i] == maxx[i] && cnt[i] == 1)
            cout<<"0 ";
        else
        if (a[i] == maxx[i])
            cout<<"1 ";
        else
            cout<<maxx[i]+1-a[i]<<' ';
    }
    cout<<'\n';
    return 0;
}
