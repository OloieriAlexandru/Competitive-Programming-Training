#include <bits/stdc++.h>
using namespace std;
int a1, a2, a3, b1, b2, b3, a, b;
int n, s1, s2;
int main()
{
    cin>>a1>>a2>>a3;
    a += (a1 + a2 + a3);
    cin>>b1>>b2>>b3;
    b += (b1 + b2 + b3);
    cin>>n;
    s1 = a / 5 + (a % 5 ? 1 : 0);
    s2 = b / 10 + (b % 10 ? 1 : 0);
    if (s1 + s2 <= n)
        cout<<"YES\n";
    else
        cout<<"NO\n";

    return 0;
}
