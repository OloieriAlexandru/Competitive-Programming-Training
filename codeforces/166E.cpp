#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
unsigned int n;
int main()
{
    cin>>n;
    if (n == 1) cout<<"0\n";
    else if (n == 2) cout<<"3\n";
    else
    {
        unsigned int d=1,a=0,dv,av;
        for (int i=1;i<=n;++i)
        {
            dv=(a*3)%mod;
            av=(a*2+d)%mod;
            d=dv;
            a=av;
        }
        cout<<d<<'\n';
    }
    return 0;
}
