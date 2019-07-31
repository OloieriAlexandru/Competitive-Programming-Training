#include <bits/stdc++.h>
#define nmax 200005
using namespace std;
int n, act, a[nmax];
int main()
{
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    sort(a+1,a+n+1,[](int a, int b){return a > b;});
    act = a[1];
    for (int i=1;i<=n;++i)
    {
        if (!act){
            cout<<i-1<<'\n';
            return 0;
        }
        if (a[i] >= act)
            --act;
        else
            act = a[i]-1;
    }
    cout<<n<<'\n';
    return 0;
}
