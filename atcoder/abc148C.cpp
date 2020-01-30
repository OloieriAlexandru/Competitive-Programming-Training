#include <bits/stdc++.h>
#define mkp make_pair
#define pb push_back
#define nmax
#define pii pair<int,int>
#define inf
using namespace std;

int main() {
    long long a, b;
    cin>>a>>b;
    long long gc = __gcd(a, b);
    long long ans = a * b / gc;
    cout<<ans<<'\n';
	return 0;
}
