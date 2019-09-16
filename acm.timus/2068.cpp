#include <iostream>

using namespace std;

int main()
{
    int n, x, moves = 0;
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>x;
        moves += (x-1)/2;
    }
    if (moves%2)
        cout<<"Daenerys\n";
    else
        cout<<"Stannis\n";
    return 0;
}
