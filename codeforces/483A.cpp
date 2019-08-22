#include <bits/stdc++.h>
#define lld long long
using namespace std;
lld l, r, gc1, gc2, gc3;
int main()
{
    cin>>l>>r;
    for (lld i=l;i<=r;++i)
        for (lld j=i+1;j<=r;++j)
            for (lld k=j+1;k<=r;++k)
        {
            gc1 = __gcd(i,j);
            gc2 = __gcd(j,k);
            gc3 = __gcd(i,k);
            if (gc1 == 1 && gc2 == 1 && gc3 != 1)
            {
                cout<<i<<' '<<j<<' '<<k<<'\n';
                return 0;
            }
        }
    cout<<"-1\n";
    return 0;
}
