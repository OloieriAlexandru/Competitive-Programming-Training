#include <iostream>

using namespace std;

int main()
{
    int ans = 0;
    int a, b;
    cin>>a>>b;
    // ia doar dintr-alea right
    ans = b*2 + 40;
    ans = max(ans, 39*2 + 40 + (a-40)*2 + 1);
    cout<<ans<<'\n';
    return 0;
}
