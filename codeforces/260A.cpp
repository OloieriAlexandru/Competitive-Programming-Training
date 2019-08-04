#include <iostream>

using namespace std;

int main()
{
    int a, b, n;
    cin>>a>>b>>n;
    for (int i=0;i<10;++i)
    {
        int ca = a * 10 + i;
        if (ca % b == 0)
        {
            cout<<ca;
            for (int j=1;j<=n-1;++j)
                cout<<0;
            cout<<'\n';
            return 0;
        }
    }
    cout<<"-1\n";
    return 0;
}
