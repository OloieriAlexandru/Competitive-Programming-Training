#include <bits/stdc++.h>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
using namespace std;
int n, x, r, ans;
vector<pii>segm;
bool crit(const pii& p1, const pii& p2){
    if (p1.second == p2.second){
        return p1.first > p2.first;
    }
    return p1.second < p2.second;
}
int main()
{
    freopen("cerc3.in","r",stdin);
    freopen("cerc3.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x>>r;
        segm.pb(mp(x-r,x+r));
    }
    sort(segm.begin(),segm.end(),crit);
    int lst = -1000;
    for (auto x:segm){
        if (x.first > lst){
            lst = x.second;
            ++ans;
        }
    }
    printf("%d\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
