#include <bits/stdc++.h>
#define lld long long
using namespace std;

int main()
{
    lld n;
    cin>>n;
    if (n%2){
        cout<<"0\n";
        return 0;
    }
    lld ans = 0;
    for (lld i = 10; n / i >= 1; i *= 5){
        ans += n / i;
    }
    cout<<ans<<'\n';
    return 0;
}
