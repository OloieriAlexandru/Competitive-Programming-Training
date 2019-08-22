#include <bits/stdc++.h>
using namespace std;
long double l, h, ans;
int main()
{
    cin>>h>>l;
    ans = (l*l-h*h)/(2*h);
    cout<<setprecision(10)<<fixed<<ans<<'\n';
    return 0;
}
