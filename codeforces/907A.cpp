#include <bits/stdc++.h>
using namespace std;
bool good(int v, int c)
{
    return v <= c && v*2>=c;
}
int main()
{
    int v1, v2, v3, v4;
    cin>>v1>>v2>>v3>>v4;
    for (int i=1; i<=200; ++i)
        for (int j=1; j<i; ++j)
            for (int k=1; k<j; ++k)
            {
                if (good(v1, i) && good(v2, j) && good(v3, k) && good(v4, k) && 2*v4 < j)
                {
                    cout<<i<<'\n'<<j<<'\n'<<k<<'\n';
                    return 0;
                }
            }
    cout<<"-1\n";
    return 0;
}
