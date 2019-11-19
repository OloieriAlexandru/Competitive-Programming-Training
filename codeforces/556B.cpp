#include <bits/stdc++.h>
#define nmax 1005
using namespace std;
int a[nmax], n;
int main()
{
    cin>>n;
    for (int i=0;i<n;++i){
        cin>>a[i];
    }
    int pushes=(n-a[0])%n;
    for (int i=0;i<n;++i){
        if (!(i%2)){
            a[i]+=pushes;
        } else {
            a[i]-=pushes;
        }
        a[i]%=n;
        if (a[i]<0){
            a[i]+=n;
        }
    }
    for (int i=0;i<n;++i){
        if (a[i]!=i){
            cout<<"No\n";
            return 0;
        }
    }
    cout<<"Yes\n";
    return 0;
}
