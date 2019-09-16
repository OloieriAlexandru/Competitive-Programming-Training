#include <bits/stdc++.h>
#define lld long long
using namespace std;
int q;
lld n, m, ans, sum;
int main()
{
    cin>>q;
    for (int i=1;i<=q;++i)
    {
        cin>>n>>m;
        ans = 0;
        n/=m;
        sum = 0;
        vector<int>digits;
        digits.resize(12);
        for (int i=1;i<=10;++i)
            digits[i] = ( i * m ) % 10, sum += digits[i];
        for (int i=0;i<n%10;++i)
            ans += digits[i+1];
        ans += n / 10 * sum;
        cout<<ans<<'\n';
    }
    return 0;
}
