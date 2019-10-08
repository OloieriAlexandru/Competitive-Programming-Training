#include <bits/stdc++.h>
#define nmax
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define lld long long
using namespace std;
int main()
{
	int t;
	lld a, b, gc;
	cin>>t;
	while(t--)
    {
        cin>>a>>b;
        gc = __gcd(a,b);
        if (gc > 1)
            printf("Sim\n");
        else
            printf("Nao\n");
    }
	return 0;
}
