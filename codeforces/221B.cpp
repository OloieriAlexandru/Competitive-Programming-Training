#include <bits/stdc++.h>
using namespace std;
bool check(int a, int b)
{
    int fv[10];
    memset(fv,0,sizeof(fv));
    if (!a)
        fv[0] = 1;
    else
    while(a)
        ++fv[a%10], a/=10;
    if (!b)
        return fv[0];
    while(b)
    {
        if (fv[b%10]) return true;
        b/=10;
    }
    return false;
}
int main()
{
    int n, ans = 0;
    cin>>n;
    for (int i=1;i*i<=n;++i)
    {
        if (n % i) continue;
        ans += check(i, n);
        if (i*i!=n)
            ans += check(n/i,n);
    }
    cout<<ans<<'\n';
    return 0;
}
