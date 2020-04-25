#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
#define nmax 200005
using namespace std;
int n, ans, x, act;
bool imp;
int main()
{
    freopen("logik.in","r",stdin);
    freopen("logik.out","w",stdout);
    scanf("%d",&n);
    for (int i=0;i<=30;++i){
        ans |= (1<<i);
    }
    for (int i=1;i<=n;++i){
        scanf("%d",&x);
        if (x % 2 == 0){
            ans &= x;
        }
        if (imp){
            act |= x;
            if (x % 2 == 1){
                ans &= act;
                act = x;
            }
        } else {
            if (x % 2 == 1){
                imp = true;
                act = x;
            }
        }
    }
    if (n == 1 && x % 2 == 1){
        cout<<"-1\n";
        return 0;
    }
    cout<<ans<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
