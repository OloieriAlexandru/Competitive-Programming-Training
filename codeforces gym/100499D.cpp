#include <bits/stdc++.h>
#define nmax 1000005
using namespace std;
int ans[nmax];
bool prime(int x)
{
    if (x % 2 == 0 && x != 2) return false;
    for (int d=3;d*d<=x;d+=2)
        if (x % d == 0) return false;
    return true;
}
void calc()
{
    ans[1] = 1;
    for (int i=2;i<=1000000;++i)
    {
        ans[i] = ans[i-1];
        if (prime(i))++ans[i];
    }
}
int main()
{
    int t, n;
    calc();
    cin>>t;
    for (int q=1;q<=t;++q)
    {
        cin>>n;
        printf("Case #%d: %d\n", q, ans[n]);
    }
    return 0;
}
