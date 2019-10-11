#include <bits/stdc++.h>
#define ld long double
using namespace std;
int t, a, c;
ld x, y;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>a>>x>>c>>y;
        x *= log(a);
        y *= log(c);
        if (x > y)
            cout<<">\n";
        else
            cout<<"<\n";
    }
    return 0;
}
