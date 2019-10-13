#include <bits/stdc++.h>
#define nmax 6000005
using namespace std;
int ans[nmax], t, x;
int main()
{
    cin>>t;
    for (int i=1;;++i)
    {
        if (6*i*i >= nmax) break;
        ans[6*i*i] = i;
    }
    while(t--)
    {
        cin>>x;
        cout<<ans[x]<<'\n';
    }
    return 0;
}
