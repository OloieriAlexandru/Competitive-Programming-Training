#include <bits/stdc++.h>
#define nmax 101
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
using namespace std;

bool cmp(const pair<pii,int>& x, const pair<pii,int>& y) {
    return x.first.second < y.first.second;
}

void solve(int t){
    int n;
    int count1 = 0, count2 = 0;
    vector<pair<pii,int>>act;
    vector<pair<pii,int>>act2;
    cin>>n;
    string ans;
    ans.resize(n);
    for (int i=0;i<n;++i){
        int x, y;
        cin>>x>>y;
        act.pb(mp(mp(x,y),i));
    }
    sort(act.begin(), act.end(), cmp);
    int last = -1;
    for (int i=0;i<act.size();++i){
        if (act[i].first.first >= last) {
            ++count1;
            ans[act[i].second] = 'C';
            last = act[i].first.second;
        } else {
            act2.pb(act[i]);
        }
    }
    cout<<count1<<'\n';
    return ;
    last = -1;
    for (int i=0;i<act2.size();++i){
        if (act2[i].first.first >= last){
            ++count2;
            ans[act2[i].second] = 'J';
            last = act2[i].first.second;
        } else {
            break;
        }
    }
    if (count1 + count2 < n){
        printf("Case #%d: IMPOSSIBLE\n", t);
        return;
    }
    printf("Case #%d: %s\n", t, ans.c_str());
}

int main()
{
    freopen("spectacole.in","r",stdin);
    freopen("spectacole.out","w",stdout);
    solve(1);
    fclose(stdin);
    fclose(stdout);
    return 0;
    int nnn;
    cin>>nnn;
    for (int t=1;t<=nnn;++t){
        solve(t);
    }
    return 0;
}
