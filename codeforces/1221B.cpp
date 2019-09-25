#include <bits/stdc++.h>
#define nmax 105
using namespace std;
int a[nmax][nmax], n;
void print()
{
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=n;++j)
            if (a[i][j] == 1)
                cout<<'W';
            else
                cout<<'B';
        cout<<'\n';
    }
}
int main()
{
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        int j = 1;
        if (i % 2)
            j = 2;
        for (;j<=n;j+=2)
            a[i][j] = 1;
    }
    print();
    return 0;
}
