#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define nmax 105
#define lld long long
#define ld long double
#define pb push_back
using namespace std;
int n, p[nmax], sum1, sum2, num, x;
bool erased[nmax];
vector<int>g[nmax];
void rem(vector<int> & v, int e){
    int rm = -1;
    for (int i=0;i<v.size();++i){
        if (v[i] == e){
            rm = i;
            break;
        }
    }
    if (rm == -1){
        return;
    }
    v.erase(v.begin()+rm);
}
vector<pii>b;
bool cmp(const pii & p1, const pii & p2){
    return p1.first > p2.first;
}
int main()
{
    freopen("maroco.in","r",stdin);
    freopen("maroco.out","w",stdout);

    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>p[i];
        cin>>num;
        for (int j=1;j<=num;++j){
            cin>>x;
            g[i].push_back(x);
        }
        b.pb(mp(p[i],i));
    }

    sort(b.begin(),b.end(),cmp);

    for (int i=1;i<=n;++i){
        int turn = i % 2;
        int add = 0, wh = -1;

        for (int j=0;j<b.size();++j){
            if (erased[b[j].second]){
                continue;
            }
            if (g[b[j].second].size()){
                continue;
            }
            add = b[j].first;
            wh = b[j].second;
            erased[wh] = true;
            for (int t=1;t<=n;++t){
                rem(g[t],wh);
            }
            break;
        }

        if (turn == 1){
            sum1 += add;
        } else {
            sum2 += add;
        }
    }

    if (sum1 > sum2){
        cout<<"1 "<<sum1<<'\n';
    } else if (sum1 < sum2){
        cout<<"2 "<<sum2<<'\n';
    } else {
        cout<<"0 "<<sum1<<'\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
