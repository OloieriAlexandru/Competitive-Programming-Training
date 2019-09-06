#include <bits/stdc++.h>
#define nmax 105
#define even(x) (!(x%2))
using namespace std;
int n, a[nmax], b[nmax], s1, s2;
int main()
{
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i]>>b[i], s1 += a[i], s2 += b[i];
    if (even(s1) && even(s2)) cout<<"0\n";
    else
    {
        for (int i=1;i<=n;++i)
        {
            int cs1 = s1, cs2 = s2;
            cs1 -= a[i], cs2 -= b[i];
            cs1 += b[i], cs2 += a[i];
            if (even(cs1) && even(cs2))
            {
                cout<<"1\n";
                return 0;
            }
        }
        cout<<"-1\n";
    }
    return 0;
}
