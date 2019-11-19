#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, x1, x2, y1, y2;
    cin>>t;
    while(t--)
    {
        cin>>x1>>y1>>x2>>y2;
        int d1=(x2-x1);
        int d2=(y2-y1);
        d1=abs(d1);
        d2=abs(d2);
        cout<<__gcd(d1,d2)+1<<'\n';
    }
    return 0;
}
