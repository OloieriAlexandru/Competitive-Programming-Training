#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    if (n % 2)
        cout<<"0\n";
    else
        cout<<(1LL << (n/2))<<'\n';
    return 0;
}
