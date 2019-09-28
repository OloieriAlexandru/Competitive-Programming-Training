#include <bits/stdc++.h>
using namespace std;
int a[5], v1, v2, v3, v4;
int main()
{
    for (int i=1;i<=4;++i)
        cin>>a[i];
    sort(a+1,a+5);
    v1 = a[1] + a[4];
    v2 = a[2] + a[3];
    v3 = a[4];
    v4 = a[1] + a[2] + a[3];
    if (v1 == v2 || v3 == v4)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}
