#include <bits/stdc++.h>
#define nmax 25
using namespace std;
int n, l, r, p2[nmax], ans1, ans2, sum[nmax];
int main()
{
    cin>>n>>l>>r;
    p2[0] = 1;
    sum[0] = 1;
    for (int i=1;i<=20;++i)
        p2[i] = p2[i-1] * 2;
    for (int i=1;i<=20;++i)
        sum[i] = sum[i-1] + p2[i];
    ans1 = sum[l-1] + (n-l);
    ans2 = sum[r-1] + (n-r)*p2[r-1];
    cout<<ans1<<' '<<ans2<<'\n';
    return 0;
}
