#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long a, b, c;
        cin>>a>>b>>c;
        int gc = __gcd(a, b);
        a /= gc;
        b /= gc;
        if (a > b){
            swap (a, b);
        }
        if ((c-1)*a + 1 >= b){
            cout<<"OBEY\n";
        } else {
            cout<<"REBEL\n";
        }
    }
    return 0;
}
