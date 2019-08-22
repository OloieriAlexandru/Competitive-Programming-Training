#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    if (n == 1)
    {
        int x;
        cin>>x;
        if (!x) cout<<"NO\n";
            else cout<<"YES\n";
    }
    else
    {
        int x, u = 0, z = 0;
        for (int i=1;i<=n;++i)
        {
            cin>>x;
            if (x == 1)++u;
            else ++z;
        }
        if (z == 1)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
