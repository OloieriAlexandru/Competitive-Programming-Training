#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    if (n <= 3)
        cout<<"NO\n";
    else
    {
        cout<<"YES\n";
        if (n % 2 == 0)
        {
            cout<<"2 * 1 = 2\n";
            cout<<"2 * 3 = 6\n";
            cout<<"6 * 4 = 24\n";
            for (int i=5; i<n; i+=2)
            {
                cout<<i+1<<" - "<<i<<" = 1\n";
                cout<<"24 * 1 = 24\n";
            }
        }
        else
        {
            cout<<"2 - 1 = 1\n";
            cout<<"1 + 3 = 4\n";
            cout<<"4 * 5 = 20\n";
            cout<<"4 + 20 = 24\n";
            for (int i=6; i<n; i+=2)
            {
                cout<<i+1<<" - "<<i<<" = 1\n";
                cout<<"24 * 1 = 24\n";
            }
        }
    }
    return 0;
}
