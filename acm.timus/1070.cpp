#include <bits/stdc++.h>
using namespace std;
int h1, h2, h3, h4;
int m1, m2, m3, m4;
int flightDuration(int h1, int m1, int h2, int m2)
{
    if (h1 == h2)
        return m2 - m1;
    int ret = 0;
    if (h2 < h1)
    {
        ret += 60 * h2;
        ret += (24-(h1+1)) * 60;
        ret += (60 - m1);
        ret += m2;
    }
    else
    {
        ret += (h2-(h1+1)) * 60;
        ret += (60 - m1);
        ret += m2;
    }
    return ret;
}
bool ok(int h1, int m1, int h2, int m2, int h3, int m3, int h4, int m4)
{
    int d1 = flightDuration(h1,m1,h2,m2);
    int d2 = flightDuration(h3,m3,h4,m4);
    if (d1 > 360 || d2 > 360) return false;
    if (abs(d1-d2) > 10) return false;
    return true;
}
void simulation(int h1, int m1, int h2, int m2, int h3, int m3, int h4, int m4, int add1, int add2)
{
    for (int i=1; i<=6; ++i)
    {
        if (ok(h1,m1,h2,m2,h3,m3,h4,m4))
        {
            cout<<(i-1)<<'\n';
            exit(0);
        }
        h2 = h2 + add1;
        h2 %= 24;
        h3 = h3 + add2;
        h3 %= 24;
        if (h2 < 0) h2+=24;
        if (h3 < 0) h3+=24;
    }
}
int main()
{
    scanf("%d.%d %d.%d",&h1,&m1,&h2,&m2);
    scanf("%d.%d %d.%d",&h3,&m3,&h4,&m4);
    simulation(h1,m1,h2,m2,h3,m3,h4,m4,1,1);
    simulation(h1,m1,h2,m2,h3,m3,h4,m4,1,-1);
    simulation(h1,m1,h2,m2,h3,m3,h4,m4,-1,1);
    simulation(h1,m1,h2,m2,h3,m3,h4,m4,-1,-1);
    simulation(h3,m3,h4,m4,h1,m1,h2,m2,1,1);
    simulation(h3,m3,h4,m4,h1,m1,h2,m2,1,-1);
    simulation(h3,m3,h4,m4,h1,m1,h2,m2,-1,1);
    simulation(h3,m3,h4,m4,h1,m1,h2,m2,-1,-1);
    return 0;
}
