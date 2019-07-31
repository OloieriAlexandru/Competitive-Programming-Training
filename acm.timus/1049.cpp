#include <bits/stdc++.h>
#define nmax 10005
using namespace std;
int a[10], ans = 1;
int main()
{
    for (int i=0;i<10;++i)
        cin>>a[i];
    for (int i=2;i<=10000;++i)
    {
        int curr = 0;
        for (int j=0;j<10;++j)
            while (a[j] % i == 0)
                ++curr, a[j] /= i;
        ans = (ans * (curr + 1));
        ans %= 10;
    }
    cout<<ans<<'\n';
    return 0;
}
