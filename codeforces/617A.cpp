#include <iostream>

using namespace std;

int main()
{
    int ans = 0, n;
    cin>>n;
    ans += n/5;
    n %= 5;
    if (n){
        ++ans;
    }
    cout<<ans<<'\n';
    return 0;
}
