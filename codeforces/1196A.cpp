#include <bits/stdc++.h>
#define lld long long
using namespace std;
lld a, b, c, d;
lld v[3];
int t;
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> v[0] >> v[1] >> v[2];
        sort(v,v+3);
        a = v[0];
        b = v[1];
        c = v[2];
        if (a > b) swap(a, b);
        a += c;
        if (a <= b)
            cout << a << '\n';
        else
        {
            d = a - b;
            d /= 2;
            a = b + d;
            cout << a << '\n';
        }
    }
    return 0;
}
