#include <bits/stdc++.h>
using namespace std;
int n, r;
double ans;
int main()
{
    cin>>n>>r;
    double alph = (3.14159265389 * (n-2.0)) / n;
    ans = (r * cos(alph/2.0)) / (1 - cos(alph/2.0));
    cout<<setprecision(10)<<fixed<<ans<<'\n';
    return 0;
}
