#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    if (n > 4)
        cout<<"Glupenky Pierre\n";
    else
    {
        string act[] = {"", "16", "06", "68", "88"};
        for (int i=1;i<=n;++i)
            cout<<act[i]<<' ';
        cout<<'\n';
    }
    return 0;
}
