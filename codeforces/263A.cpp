#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n = 5, a, x, y, ans;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
    {
        cin>>a;
        if (a) x = i, y = j;
    }
    ans = abs(x-3) + abs(y-3);
    cout<<ans<<'\n';
    return 0;
}
