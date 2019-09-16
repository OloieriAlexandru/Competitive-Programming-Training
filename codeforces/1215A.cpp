#include <bits/stdc++.h>
using namespace std;
int a1, a2, k1, k2, n, ans1, ans2;
int main()
{
    cin>>a1>>a2>>k1>>k2>>n;
    if (k1 > k2)
    {
        swap(k1,k2);
        swap(a1,a2);
    }
    // k1 < k2
    int nr = n / k1;
    if (nr <= a1)
        ans1 = nr;
    else
    {
        int pls = nr - a1;
        int more = n % k1 + pls * k1;
        int add = more / k2;
        add = min(add, a2);
        ans1 = a1 + add;
    }
    int howm = a1*(k1-1) + a2*(k2-1);
    if (howm >= n)
        ans2 = 0;
    else
        ans2 = min(a1+a2,n-howm);
    cout<<ans2<<' '<<ans1<<'\n';
    return 0;
}
