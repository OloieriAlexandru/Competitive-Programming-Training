#include <bits/stdc++.h>
#define nmax 105
using namespace std;
int t, n, a, b, c, won;
bool nc[nmax];
string s, ans;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>a>>b>>c;
        cin>>s;
        won=0;
        int curr=0;
        ans.clear();
        for (auto x:s){
            if (x == 'R'){
                if (b){
                    --b, ++won;
                    ans.push_back('P');
                } else {
                    nc[curr] = true;
                }
            }
            else if (x == 'P'){
                if (c){
                    --c, ++won;
                    ans.push_back('S');
                } else {
                    nc[curr] = true;
                }
            }
            else {
                if (a) {
                    --a, ++won;
                    ans.push_back('R');
                } else {
                    nc[curr] = true;
                }
            }
            if (nc[curr]){
                ans.push_back('X');
            }
            ++curr;
        }
        int need = n/2+(n%2?1:0);
        if (won >= need){
            for (int i=0;i<n;++i){
                if (nc[i]){
                    if (a){
                        --a;
                        ans[i] = 'R';
                    }
                    else if (b){
                        --b;
                        ans[i] = 'P';
                    }
                    else {
                        --c;
                        ans[i] = 'S';
                    }
                }
            }
            cout<<"YES\n"<<ans<<'\n';
        } else {
            cout<<"NO\n";
        }
        for (int i=0;i<n;++i)
            nc[i]=false;
    }
    return 0;
}
