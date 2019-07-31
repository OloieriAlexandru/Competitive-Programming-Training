#include <bits/stdc++.h>
#define lld long long
#define inf 1000000001LL
using namespace std;
lld n, k;
int main()
{
    cin>>n>>k;
    lld st = 0, dr = inf - 1;
    while (st <= dr)
    {
        lld mid = (st + dr) / 2;
        lld tot = (mid * (mid + 1)) / 2; // nr bomboane
        lld rm = n - mid; // numarul de actiuni ramas
        if (tot - rm < 0)
        {
            st = mid + 1;
            continue;
        }
        if (tot - rm == k)
        {
            cout<<rm<<'\n';
            return 0;
        }
        if (tot - rm > k)
            dr = mid - 1;
        else
            st = mid + 1;
    }
    return 0;
}
