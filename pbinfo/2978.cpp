#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
#define sint short int
#define ulld unsigned long long
using namespace std;
vector<char>digits;
int main()
{
    freopen("aur.in","r",stdin);
    freopen("aur.out","w",stdout);

    int t, n, x, k = 0;
    cin>>t>>n;
    if (!(t == 1)){
        cin>>k;
    }
    for (int i=1;i<=n;++i){
        scanf("%d",&x);
        vector<int>d;
        while (x){
            d.pb(x%10);
            x/=10;
        }
        for (int j=d.size()-1;j>=0;--j){
            digits.pb(d[j]);
        }
    }
    if (t == 1){
        cout<<digits.size();
    } else if (t == 2){
        cout<<(int)digits[k-1];
    } else {
        ulld md = 1, num = 0, ans = 0;
        for (int i=0;i<k;++i){
            md *= 10ULL;
            num = num * 10ULL + digits[i];
        }
        md /= 10ULL;
        for (unsigned int i=k;i<digits.size();++i){
            if (num > ans){
                ans = num;
            }
            num = (num % md) * 10ULL + digits[i];
        }
        if (num > ans){
            ans = num;
        }
        cout<<ans<<'\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
