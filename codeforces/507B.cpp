#include <bits/stdc++.h>
#define ld long double
using namespace std;
ld r, x, y, x1, y1;
int main()
{
    cin>>r>>x>>y>>x1>>y1;
    ld dist = sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1));
    int ans = (int)ceil(dist) / (r*2) + ((int)ceil(dist) % ((int)r*2) ? 1 : 0);
    cout<<ans<<'\n';
    return 0;
}
