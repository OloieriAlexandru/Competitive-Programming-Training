#include <bits/stdc++.h>
#define nmax 11
#define pb push_back
using namespace std;
vector<int>cifs[nmax];
vector<int>ans;
int n;
int main()
{
    cifs[2].pb(2);
    cifs[3].pb(3);
    cifs[4].pb(3);
    cifs[4].pb(2);
    cifs[4].pb(2);
    cifs[5].pb(5);
    cifs[6].pb(5);
    cifs[6].pb(3);
    cifs[7].pb(7);
    cifs[8].pb(7);
    cifs[8].pb(2);
    cifs[8].pb(2);
    cifs[8].pb(2);
    cifs[9].pb(7);
    cifs[9].pb(3);
    cifs[9].pb(3);
    cifs[9].pb(2);
    cin>>n;
    for (int i=1; i<=n; ++i)
    {
        char ch;
        int ich;
        cin>>ch;
        ich = ch - '0';
        for (auto x:cifs[ich])
            ans.pb(x);
    }
    sort(ans.begin(), ans.end(),[](int a, int b)
    {
        return a > b;
    });
    for (auto x:ans)
        cout<<x;
    cout<<'\n';
    return 0;
}
