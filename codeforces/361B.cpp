#include <bits/stdc++.h>
#define nmax 100005
using namespace std;
int n, k, ans[nmax];
int main()
{
    cin>>n>>k;
    if (k == n){
        cout<<"-1\n";
        return 0;
    }
    for (int i=1;i<=n;++i){
        ans[i] = i;
    }
    int p1 = 1;
    int cnt = n-1, act = n;
    while (cnt > k){
        swap(ans[p1],ans[act]);
        p1 = act;
        --act;
        --cnt;
    }
    for (int i=1;i<=n;++i){
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
    return 0;
}
