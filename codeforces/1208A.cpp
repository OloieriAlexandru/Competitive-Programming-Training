#include <iostream>

using namespace std;

int main()
{
    int t, a, b, c;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c;
        if (c == 0)
            cout<<a<<'\n';
        else
        if (c == 1)
            cout<<b<<'\n';
        else
        if (c % 3 == 0)
            cout<<a<<'\n';
        else
        if (c % 3 == 1)
            cout<<b<<'\n';
        else
            cout<<(a^b)<<'\n';
    }
    return 0;
}
