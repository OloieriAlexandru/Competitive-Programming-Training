#include <bits/stdc++.h>
#define mod 1000000007
#define lld long long
using namespace std;
int n, m, ans;
int fib(int x)
{
    if (x == 1) return 1;
    if (x == 2) return 2;
    int a = 1, b = 2, c;
    for (int i=3;i<=x;++i){
        c = (a+b)%mod;
        a = b;
        b = c;
    }
    return c;
}
int main()
{
    cin>>n>>m;
    int ans = (2*((fib(n)+fib(m)-1)%mod))%mod;
    cout<<ans%mod<<'\n';
    return 0;
}
