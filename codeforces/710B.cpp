#include <bits/stdc++.h>
#define nmax 300005
using namespace std;
int n, v[nmax];
int main()
{
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>v[i];
    sort(v+1,v+n+1);
    int ind = n / 2;
    if (n % 2)++ind;
    cout<<v[ind]<<'\n';
    return 0;
}
