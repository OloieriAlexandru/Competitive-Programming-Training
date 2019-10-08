#include <bits/stdc++.h>
using namespace std;
int v[3], a, b;
void read(int &a, int &b)
{
    cin>>a>>b;
}
int main()
{
    cin>>v[1]>>v[2];
    while (v[1] || v[2])
    {
        if (v[1] > v[2])
        {
            cout<<1<<' '<<v[1]-v[2]<<'\n';
            cout.flush();
            v[1] = v[2];
        }
        else
        {
            cout<<2<<' '<<v[2]-v[1]<<'\n';
            cout.flush();
            v[2] = v[1];
        }
        if (!v[1] && !v[2]) break;
        read(a, b);
        v[a] -= b;
    }
    return 0;
}
