#include <bits/stdc++.h>
#define nmax 100005
#define pb push_back
#define mp make_pair
using namespace std;
int cc, n, a[nmax], root;
vector<int>g[nmax];
void dfs(int k, int lst){
    ++cc;
    for (auto x:g[k]){
        if (x == lst){
            continue;
        }
        dfs(x, k);
    }
}
int main()
{
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        if (a[i]){
            g[i].pb(a[i]);
            g[a[i]].pb(i);
        } else {
            if (root == 0){
                root = i;
            } else {
                cout<<"NU\n";
                return 0;
            }
        }
    }
    dfs(root, -1);
    if (cc == n){
        cout<<"DA\n";
    } else {
        cout<<"NU\n";
    }
    return 0;
}
