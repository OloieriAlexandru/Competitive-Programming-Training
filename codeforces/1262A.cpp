#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
using namespace std;
int n, x, y, v1, v2;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for (int i=1;i<=n;++i){
            cin>>x>>y;
            if (i == 1){
                v2 = y;
                v1 = x;
            } else {
                v2 = min(v2, y);
                v1 = max(v1, x);
            }
        }
        cout<<max(v1 - v2,0)<<'\n';
    }
    return 0;
}
