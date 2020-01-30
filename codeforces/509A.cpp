#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int a[11][11];
    cin>>n;
    for (int i=1;i<=n;++i){
        a[1][i] = a[i][1] = 1;
    }
    for (int i=2;i<=n;++i){
        for (int j=i;j<=n;++j){
            a[i][j] = a[i-1][j] + a[i][j-1];
            a[j][i] = a[j-1][i] + a[j][i-1];
        }
    }
    cout<<a[n][n]<<'\n';
    return 0;
}
