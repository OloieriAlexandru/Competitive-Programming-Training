#include <bits/stdc++.h>
#define lld long long
using namespace std;
int n;
lld inc;
bool isPrime(lld x)
{
    if (x == 1 || (x %2 == 0 && x != 2)) return false;
    for (lld d = 3; d*d <=x; d+= 2)
        if (x % d == 0) return false;
    return true;
}
int nrc(lld x)
{
    int ans = 0;
    while (x) ++ans, x/=10;
    return ans;
}
int main()
{
    cin>>n;
    cin>>inc;
    if (inc == 0)
    {
        cout<<"000000000002\n";
        return 0;
    }
    for (int i=1; i<=(12-n); ++i)
        inc = inc * 10;
    lld x = inc;
    if (isPrime(x))
    {
        int nr = nrc(x);
        int l = 12 - nr;
        for (int i=1; i<=l; ++i)
            cout<<0;
        cout<<x<<'\n';
        return 0;
    }
    if (x % 2 == 0) ++x;
    while (1)
    {
        if (isPrime(x))
        {
            int nr = nrc(x);
            int l = 12 - nr;
            for (int i=1; i<=l; ++i)
                cout<<0;
            cout<<x<<'\n';
            return 0;
        }
        x+=2;
    }
    return 0;
}