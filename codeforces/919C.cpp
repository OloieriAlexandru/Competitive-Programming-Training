#include <bits/stdc++.h>
#define nmax 2005
using namespace std;
int n, m, k;
char mat[nmax][nmax];
long long ans;
int main()
{
    cin>>n>>m>>k;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            cin>>mat[i][j];
        }
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            if (mat[i][j]=='*'){
                continue;
            }
            int cnt=1;
            while (j<m&&mat[i][j]==mat[i][j+1]){
                ++cnt,++j;
            }
            if (cnt>=k){
                ans+=(cnt-k+1);
            }
        }
    }
    for (int j=1;j<=m;++j){
        for (int i=1;i<=n;++i){
            if (mat[i][j]=='*'){
                continue;
            }
            int cnt=1;
            while (i<n&&mat[i][j]==mat[i+1][j]){
                ++cnt,++i;
            }
            if (cnt>=k&&k>1){
                ans+=(cnt-k+1);
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}
