#include <bits/stdc++.h>
using namespace std;
bool ok (int x)
{
    int fv[10];
    memset(fv,0,sizeof(fv));
    if (!x) return true;
    while (x)
        ++fv[x%10],x/=10;
    for (int i=0;i<=9;++i)
        if (fv[i] >= 2)
            return false;
    return true;
}
int main()
{
    int x, y;
    cin>>x>>y;
    for (int i=x;i<=y;++i)
    {
        if (ok(i))
        {
            cout<<i<<'\n';
            return 0;
        }
    }
    cout<<"-1\n";
    return 0;
}
