#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, req, x;
    cin>>t;
    while(t--)
    {
        cin>>n>>req;
        int act = 1500;
        for (int i=1;i<=n;++i)
        {
            cin>>x;
            act += x;
        }
        if (act == req)
            cout<<"Correct\n";
        else
            cout<<"Bug\n";
    }
    return 0;
}
