#include <bits/stdc++.h>
#define nmax 305
using namespace std;
int n, b, g, ans;
bool got[nmax];
int main()
{
    cin>>b>>g>>n;
    for (int i=0; i<=b; ++i)
        for (int j=0; j<=g; ++j)
        {
            if (i + j != n) continue;
            // i baieti, j fete
            ++ans;
        }
    cout<<ans<<'\n';
    return 0;
}
