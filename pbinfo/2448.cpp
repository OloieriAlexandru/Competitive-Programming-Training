#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
using namespace std;
int main()
{
    freopen("patrate3.in","r",stdin);
    freopen("patrate3.out","w",stdout);
    int t;
    lld n;
    cin>>t>>n;
    if (t == 1){
        cout<<n*8<<'\n';
    } else {
        lld st = 1, dr = 8;
        for (int i=1;;++i){
            if (st <= n && n <= dr){
                cout<<i<<'\n';
                return 0;
            }
            st = dr+1;
            dr = dr + (i+1)*8;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
