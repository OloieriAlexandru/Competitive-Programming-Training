#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin>>a>>b;
    if (a % b || a == b)
    {
        cout<<"-1\n";
        return 0;
    }
    cout<<b<<' '<<a-b<<'\n';
    return 0;
}
