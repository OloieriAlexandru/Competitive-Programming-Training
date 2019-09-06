#include <bits/stdc++.h>
#define nmax 1000005
using namespace std;
int n, ans[nmax];
int main()
{
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        int poz = (i%2)?i/2:(n-1)+i/2;
        int poz2 = poz + (n-i);
        ans[poz] = ans[poz2] = i;
    }
    ans[2*n-1] = n;
    for (int i=0;i<2*n;++i)
        cout<<ans[i]<<' ';
    return 0;
}
