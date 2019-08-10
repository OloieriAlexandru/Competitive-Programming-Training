#include <bits/stdc++.h>
#define EPS 0.000000001
using namespace std;
int v[3], n, asd[3];
double d[3];
int main()
{
    cin>>v[0]>>v[1]>>v[2]>>v[3];
    asd[0] = v[1] - v[0];
    asd[1] = v[2] - v[1];
    asd[2] = v[3] - v[2];
    if (asd[0] == asd[1] && asd[1] == asd[2])
    {
        cout<<v[3] + asd[0]<<'\n';
        return 0;
    }
    d[0] = v[1] / (double)v[0];
    d[1] = v[2] / (double)v[1];
    d[2] = v[3] / (double)v[2];
    if (abs(d[0]-d[1]) < EPS && abs(d[1]-d[2]) < EPS)
    {
        double af = v[3] * d[0];
        if (abs(af - ((double)(long long)(af)))<EPS)
        {
            cout<<af<<'\n';
            return 0;
        }
    }
    cout<<"42\n";
    return 0;
}
