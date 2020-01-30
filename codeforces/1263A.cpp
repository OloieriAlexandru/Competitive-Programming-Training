#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x, ans=0;
        vector<int>v;
        for (int i=0;i<3;++i){
            cin>>x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        int dif = v[2] - v[1];
        if (dif >= v[0]){
            ans += v[0];
            v[2] -= v[0];
            ans += min(v[1],v[2]);
        } else {
            ans += dif;
            v[0] -= dif;
            v[2] -= dif;
            int sb1 = v[0]/2;
            int sb2 = v[0]/2;
            if (v[0]%2){
                ++sb2;
            }
            int sub1 = min(v[1],sb1);
            int sub2 = min(v[2],sb2);
            ans += sub1 + sub2;
            v[1] -= sub1;
            v[2] -= sub2;
            ans += min(v[1],v[2]);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
