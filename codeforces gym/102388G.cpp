#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, a, b, n;
    cin>>t;
    while(t--)
    {
        cin>>n>>a>>b;
        if (n<=a){
            cout<<"1\n";
            continue;
        }
        int d=a-b;
        if (d<=0){
            cout<<"-1\n";
            continue;
        }
        int ans=0;
        while(true){
            n-=a;
            ++ans;
            if(n<=0){
                break;
            }
            n+=b;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
