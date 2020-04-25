#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
#define nmax 105
using namespace std;
int n, t, a[nmax], b[nmax];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for (int i=1;i<=n;++i){
            cin>>a[i];
        }
        for (int i=1;i<=n;++i){
            cin>>b[i];
        }
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
        for (int i=1;i<=n;++i){
            cout<<a[i]<<' ';
        }
        cout<<'\n';
        for (int i=1;i<=n;++i){
            cout<<b[i]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
