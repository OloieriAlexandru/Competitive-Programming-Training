#include <bits/stdc++.h>
#define lld long long
using namespace std;
int t;
lld a, b, n, s;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>n>>s;
        swap (a, b);
        bool ok = false;
        if (b * n < s){
            if (b * n + a >= s){
                ok = true;
            } else {
                ok = false;
            }
        } else {
            if (s % n == 0){
                ok = true;
            } else {
                lld dv = s / n;
                lld v2 = dv * n;
                if (v2 + a >= s){
                    ok = true;
                } else {
                    ok = false;
                }
            }
        }
        if (ok){
            cout<<"YES\n";
        } else {
            cout<<"NO\n";
        }
    }
    return 0;
}
