#include <iostream>
#include <cmath>
using namespace std;

double x, y;

bool ok(int v)
{
    double v1 = (x*v + (1e-7))/100;
    double v2 = (y*v - (1e-7))/100;
    int c1 = v1;
    int c2 = v2;
    return c1!=c2;
}

int main()
{
    cin>>x>>y;
    int i;
    for(i= 1;1;i++)
    {
        if (ok(i))
        {
            break;
        }
    }
    cout<<i<<'\n';
    return 0;
}