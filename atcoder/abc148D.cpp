#include <bits/stdc++.h>
#define mkp make_pair
#define pb push_back
#define nmax 200005
#define pii pair<int,int>
using namespace std;
int n, ans, a[nmax], br[nmax];
int main() {
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    int curr = 1;
    for (int i=1;i<=n;++i){
        if (a[i] == curr){
            ++curr;
        } else {
            br[i] = 1;
        }
    }
    int destr = 0;
    for (int i=1;i<=n;++i){
        if (br[i]){
            ++destr;
        }
    }
    if (destr == n){
        ans = -1;
    } else {
        ans = destr;
    }
    cout<<ans<<'\n';
	return 0;
}
