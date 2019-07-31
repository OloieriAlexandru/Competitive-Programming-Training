#include <bits/stdc++.h>
#define lld unsigned long long
using namespace std;

int main()
{
    lld n;
    cin>>n;
    if (n == 0)
    {
        cout<<1<<'\n';
        return 0;
    }
    n = n * (n + 1) * 3ULL + 1;
    cout<<n<<'\n';
    return 0;
}
