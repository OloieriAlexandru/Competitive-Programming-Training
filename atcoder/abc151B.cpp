#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define nmax 100005
#define inf 999999999
#define lld long long
#define ld long double
using namespace std;

int main(){
    int n, k, m, req, sum = 0, x, need;
    cin>>n>>k>>m;
    for (int i=1;i<n;++i){
        cin>>x;
        sum += x;
    }
    req = n * m;
    need = req - sum;
    if (need > k){
        cout<<"-1\n";
    } else {
        cout<<max(0,need)<<'\n';
    }
    return 0;
}
