#include <bits/stdc++.h>
#define nmax 100005
#define lld long long
using namespace std;
int n, a[nmax];
int main()
{
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    sort(a+1,a+n+1);
    lld v1 = 0, v2 = 0;
    int st = 1, dr = n, cnt = 0;
    while (st <= dr){
        ++cnt;
        if (cnt % 2) v1 += a[dr--];
        else v2 += a[st++];
    }
    cout<<v1 * v1 + v2 * v2<<'\n';
    return 0;
}
