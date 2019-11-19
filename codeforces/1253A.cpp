#include <bits/stdc++.h>
#define nmax 100005
using namespace std;
int a[nmax], b[nmax], d[nmax];
int n;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for (int i=1;i<=n;++i){
            cin>>a[i];
        }
        bool ok = true;
        for (int i=1;i<=n;++i){
            cin>>b[i];
            d[i]=b[i]-a[i];
            if (d[i]<0){
                ok=false;
            }
        }
        if (!ok){
            cout<<"NO\n";
            continue;
        }
        bool found = false;
        for (int i=1;i<=n;++i){
            if (!d[i]){
                continue;
            }
            if (found){
                ok=false;
                break;
            }
            found=true;
            while (i<n&&d[i]==d[i+1]){
                ++i;
            }
            if (i<n&&d[i+1]){
                ok=false;
                continue;
            }
        }
        if (ok){
            cout<<"YES\n";
        } else {
            cout<<"NO\n";
        }
    }
    return 0;
}
