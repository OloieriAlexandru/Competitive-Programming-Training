#include <bits/stdc++.h>
#define lld long long
using namespace std;
lld fib[50];
int main()
{
    lld n, k;
    cin>>n>>k;
    fib[0] = 1;
    fib[1] = 1;
    fib[2] = 2;
    for (int i=3; i<=n; ++i)
        fib[i] = fib[i-1] + fib[i-2];
    --k;
    if (k>=fib[n]+fib[n-1])
    {
        cout<<"-1\n";
        return 0;
    }
    for (int i=n; i>=1; --i)
    {
        if (fib[i] <= k)
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }
        k %= fib[i];
    }
    return 0;
}