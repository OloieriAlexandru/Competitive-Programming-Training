#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
#define nmax 1005
using namespace std;
int t;
char s[nmax];
string ans;
int main()
{
    freopen("robot3.in","r",stdin);
    freopen("robot3.out","w",stdout);
    cin>>t>>s;
    int n = strlen(s), poz, mov = 0;
    if (t == 1 || t == 2){
        for (int i=0;i<n;++i){
            if (s[i] == 'D'){
                ++i;
                poz = s[i] - '0';
                mov += poz;
                mov %= 10;
            } else if (s[i] == 'S'){
                ++i;
                poz = s[i] - '0';
                mov -= poz;
                if (mov < 0){
                    mov += 10;
                }
            } else if (s[i] == 'A'){
                ans.pb(mov+'0');
            } else {
                break;
            }
        }
        if (t == 1){
            cout<<ans.size()<<'\n';
        } else {
            cout<<ans<<'\n';
        }
    } else {
        for (int i=0;i<n;++i){
            int req = s[i] - '0', ds, dd;
            if (req == mov){
                ans.pb('A');
                continue;
            }
            if (mov < req){
                dd = req - mov;
                ds = mov + 10 - req;
            } else {
                dd = req + 10 - mov;
                ds = mov - req;
            }
            if (dd <= ds){
                ans.pb('D');
                ans.pb(dd+'0');
            } else {
                ans.pb('S');
                ans.pb(ds+'0');
            }
            ans.pb('A');
            mov = req;
        }
        ans.pb('T');
        cout<<ans<<'\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
