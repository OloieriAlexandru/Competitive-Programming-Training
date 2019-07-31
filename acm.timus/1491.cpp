#include <bits/stdc++.h>
#define lld long long
#define nmax 100005
using namespace std;
int n, a, b, c;
lld mars[nmax], act;
int main()
{
    cin>>n;
    for (int i=1;i<=n+1;++i)
    {
        cin>>a>>b>>c;
        mars[a] += c;
        mars[b+1] -= c;
    }
    for (int i=1;i<=n;++i)
    {
        act += mars[i];
        cout<<act<<' ';
    }
    cout<<'\n';
    return 0;
}
