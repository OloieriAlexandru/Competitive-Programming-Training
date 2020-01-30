#include <bits/stdc++.h>
#define pii pair<int,int>
#define pb push_back
#define nmax 100005
#define inf 999999999
#define lld long long
#define ld long double
using namespace std;

pair<int,bool>pro[nmax];

int main(){
    int n, m, nr;
    string ver;
    cin>>n>>m;
    int a1 = 0, a2 = 0;
    for (int i=1;i<=m;++i){
        cin>>nr>>ver;
        if (ver == "AC"){
            pro[nr].second = true;
        } else {
            if (pro[nr].second == false){
                ++pro[nr].first;
            }
        }
    }
    for (int i=1;i<=n;++i){
        if (pro[i].second){
            ++a1;
            a2 += pro[i].first;
        }
    }
    cout<<a1<<' '<<a2<<'\n';
    return 0;
}
