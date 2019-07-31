#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin>>n>>k;
    int a = (n-k)/2;
    int af = 0;
    int rep = (n/(a+1));
    for (int i=1;i<=rep;++i)
    {
        af += (a+1);
        for (int j=1;j<=a;++j)
            cout<<'0';
        cout<<'1';
    }
    for (int i=af+1;i<=n;++i)
        cout<<'0';
    cout<<'\n';
    return 0;
}
