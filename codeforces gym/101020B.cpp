#include <iostream>

using namespace std;

int main()
{
    int t, a, b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        if ((a*b)%2)
            cout<<"Hussain\n";
        else
            cout<<"Hasan\n";
    }
    return 0;
}
