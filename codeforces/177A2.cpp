#include <bits/stdc++.h>
#define nmax 101
using namespace std;
int a[nmax][nmax];
bool used[nmax][nmax];
void checkEl(int i, int j, int& sum){
    if (!used[i][j]){
        sum += a[i][j];
        used[i][j] = true;
    }
}
int main()
{
    int ans = 0, n, mid;
    cin>>n;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            cin>>a[i][j];
        }
    }
    mid = (n-1)/2+1;
    for (int i=1;i<=n;++i){
        checkEl(i, i, ans);
        checkEl(i, n-i+1, ans);
        checkEl(mid, i, ans);
        checkEl(i, mid, ans);
    }
    cout<<ans<<'\n';
    return 0;
}
