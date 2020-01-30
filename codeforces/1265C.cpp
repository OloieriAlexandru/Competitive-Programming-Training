#include <bits/stdc++.h>
#define nmax 100005
using namespace std;
int a[nmax*4];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for (int i=1;i<=n;++i){
            cin>>a[i];
        }
        int maxx = n / 2;
        int g = 0, s = 0, b = 0;
        bool ok = true;
        int i1 = 1;
        if (i1 <= n){
            g = 1;
            while (i1 < n && a[i1] == a[i1+1]){
                ++g, ++i1;
            }
            ++i1;
        }
        if (i1 <= n){
            s = 1;
            while (i1 < n && (a[i1] == a[i1+1] || s <= g)){
                ++s, ++i1;
            }
            ++i1;
        }
        if (i1 <= n){
            b = 1;
            while (i1 < n && (a[i1] == a[i1+1] || b <= g)){
                ++b, ++i1;
            }
            ++i1;
        }
        if (i1 > maxx+1){
            ok = false;
        } else {
            while (i1 <= maxx){
                ++b, ++i1;
            }
            --i1;
            if (a[i1] == a[i1+1]){
                while(a[i1] == a[i1-1]){
                    --i1, --b;
                }
                --i1, --b;
            }
            if (!b){
                ok = false;
            }
        }
        if (!ok){
            g = 0, s = 0, b = 0;
        }
        cout<<g<<' '<<s<<' '<<b<<'\n';
    }
    return 0;
}
