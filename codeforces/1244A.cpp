#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, a, b, c, d, k;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c>>d>>k;
        int v1 = a / c + (a % c ? 1 : 0);
        int v2 = b / d + (b % d ? 1 : 0);
        if (v1 + v2 <= k)
            cout<<v1<<' '<<v2<<'\n';
        else
            cout<<"-1\n";
    }
    return 0;
}
