#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
#define nmax 100005
using namespace std;
int a[nmax], n, k, x, b[31];
lld ans = 0;
void add(int x){
    for (int i=0;i<=30;++i){
        if ((1<<i) & x){
            ++b[i];
        }
    }
}
void rem(int x){
    for (int i=0;i<=30;++i){
        if ((1<<i) & x){
            --b[i];
        }
    }
}
int countt(){
    int res = 0;
    for (int i=0;i<=30;++i){
        if (b[i]){
            ++res;
        }
    }
    return res;
}
int main()
{
    freopen("nane.in","r",stdin);
    freopen("nane.out","w",stdout);
    scanf("%d %d",&n, &k);
    for (int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    int st = 1;
    for (int dr=1;dr<=n;++dr){
        add(a[dr]);
        while (st <= dr && countt()> k){
            rem(a[st]);
            ++st;
        }
        ans += (dr-st+1);
    }
    cout<<ans<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
