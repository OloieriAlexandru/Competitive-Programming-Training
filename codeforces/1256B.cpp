#include <bits/stdc++.h>
#define nmax 105
using namespace std;
int a[nmax], n;
bool done[nmax];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        memset(done,0,sizeof(done));
        for (int i=1;i<=n;++i){
            cin>>a[i];
        }
        for (int i=1;i<=n;++i){
            int poz;
            for (int j=1;j<=n;++j){
                if (a[j]==i){
                    poz=j;
                    break;
                }
            }
            while (poz>i&&!done[poz-1]){//&&a[poz]<a[poz-1]){
                done[poz-1]=true;
                swap(a[poz],a[poz-1]);
                --poz;
            }
        }
        for (int i=1;i<=n;++i){
            cout<<a[i]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
