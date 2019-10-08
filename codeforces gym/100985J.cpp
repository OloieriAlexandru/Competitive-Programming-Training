#include <bits/stdc++.h>
#define nmax 1005
using namespace std;
int n, a[nmax], b[nmax], c[nmax];
double dist(int i1, int i2)
{
    return sqrt((a[i2]-a[i1])*(a[i2]-a[i1])+(b[i2]-b[i1])*(b[i2]-b[i1]));
}
bool intersects(int i1, int i2)
{
    double d1 = dist(i1, i2);
    double d2 = c[i1]+c[i2];
    if (d1 <= d2)
        return true;
    return false;
}
int main()
{
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i]>>b[i]>>c[i];
        for (int j=i-1;j>=1;--j)
            if (intersects(i, j))
                cout<<i<<' '<<j<<'\n';
    }
    return 0;
}
