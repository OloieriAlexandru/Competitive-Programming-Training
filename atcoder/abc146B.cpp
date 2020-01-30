#include <bits/stdc++.h>
#define lld long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define nmax
#define mod
using namespace std;

int main()
{
    string s;
    int n;
    cin>>n;
    cin>>s;
    for (auto &x:s){
        int val = x;
        val += n;
        int dep = val - 'Z', nc;
        if (dep > 0){
            nc = 'A' - 1 + dep;
        } else {
            nc = val;
        }
        x = (char)nc;
    }
    cout<<s<<'\n';
    return 0;
}
