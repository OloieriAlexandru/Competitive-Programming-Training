#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, m, a;
    int s = 0;
    scanf("%d:%d",&h,&m);
    scanf("%d",&a);
    s = h * 60 + m + a;
    s %= 1440;
    int nh = s/60;
    int nm = s%60;
    if (nh < 10)
        cout<<0;
    cout<<nh<<':';
    if (nm < 10)
        cout<<0;
    cout<<nm<<'\n';
    return 0;
}
