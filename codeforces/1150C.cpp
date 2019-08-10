#include <iostream>

using namespace std;

int main()
{
    int n, x, cnt2 = 0, cnt1 = 0;
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>x;
        if (x == 2) ++cnt2; else ++cnt1;
    }
    if (!cnt2)
        for (int i=1;i<=cnt1;++i)
            cout<<1<<' ';
    else
    if (!cnt1)
        for (int i=1;i<=cnt2;++i)
            cout<<2<<' ';
    else
    {
        cout<<2<<' '<<1<<' ';
        --cnt2, --cnt1;
        for (int i=1;i<=cnt2;++i)
            cout<<2<<' ';
        for (int i=1;i<=cnt1;++i)
            cout<<1<<' ';
    }
    cout<<'\n';
    return 0;
}
