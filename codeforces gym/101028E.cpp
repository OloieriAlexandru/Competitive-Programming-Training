#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, x, sum = 0, gc;
        cin>>n;
        cin>>gc;
        sum += gc;
        for (int i=2;i<=n;++i)
        {
            cin>>x;
            sum += x;
            gc = __gcd(x, gc);
        }
        cout<<gc<<' '<<sum / gc<<'\n';
    }
    return 0;
}
