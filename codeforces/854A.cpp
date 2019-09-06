#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, a, b;
    cin>>n;
    for (int i=n-1; i>=1; --i)
    {
        a = i;
        b = n - i;
        if (a >= b) continue;
        if (__gcd(a,b) == 1)
        {
            cout<<a<<' '<<b<<'\n';
            return 0;
        }
    }
    return 0;
}
