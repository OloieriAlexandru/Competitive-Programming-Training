#include <iostream>

using namespace std;

int main()
{
    int n, z = 0, u = 0;
    char ch;
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>ch;
        if (ch == 'n') ++u;
        else if (ch == 'z') ++z;
    }
    for (int i=1;i<=u;++i)
        cout<<1<<' ';
    for (int i=1;i<=z;++i)
        cout<<0<<' ';
    cout<<'\n';
    return 0;
}
