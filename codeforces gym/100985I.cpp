#include <bits/stdc++.h>
#define nmax 100005
using namespace std;
int a1[nmax], a2[nmax], a[nmax];
int cnt1, cnt2, t, n;
int main()
{
    cin>>n>>t;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        a1[i] = a1[i-1] + a[i];
    }
    reverse(a+1,a+n+1);
    for (int i=1;i<=n;++i)
        a2[i] = a2[i-1] + a[i];
    for (int i=1;i<=n;++i)
    {
        if (a1[i] <= t)
            cnt1 = i;
        if (a2[i] <= t)
            cnt2 = i;
    }
    if (cnt1 == cnt2)
        cout<<"Empate\n";
    else
    if (cnt1 > cnt2)
        cout<<"Yan\n";
    else
        cout<<"Nathan\n";
    return 0;
}
