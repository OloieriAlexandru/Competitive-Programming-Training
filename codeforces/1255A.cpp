#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, a, b, ans, need;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        ans=0;
        need = abs(a-b);
        ans += need/5;
        need %= 5;
        if (need == 4 || need == 3){
            ans += 2;
        } else if (need){
            ++ans;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
