#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
#define nmax
using namespace std;
int main()
{
    freopen("numere17.in","r",stdin);
    freopen("numere17.out","w",stdout);
    int t, n, x;
    cin>>t>>n;
    if (t == 1){
        int ans = 1;
        for (int i=1;i<=n;++i){
            cin>>x;
            if (x == 1){
                ans += i;
            } else {
                ans += (i+1);
            }
        }
        cout<<ans<<'\n';
    } else {
        int line = 1;
        while (n > (line*(line+1)/2)){
            ++line;
        }
        int col = n - (line*(line-1))/2;
        long long ans = 0, lst = 0;
        for (int i=1;i<=col;++i){
            lst += i;
            ans += lst;
        }
        for (int i=col+1;i<=line;++i){
            lst += i;
            ans += lst - (i-col);
        }
        cout<<ans<<'\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
