#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        int r=n%4;
        if (!r) cout<<n<<'\n';
        else if (r==1) cout<<1<<'\n';
        else if (r==2) cout<<n+1<<'\n';
        else cout<<0<<'\n';
    }
    return 0;
}
