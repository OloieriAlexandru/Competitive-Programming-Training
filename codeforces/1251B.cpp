#include <bits/stdc++.h>
using namespace std;
string s;
vector<pair<int,pair<int,int>>>v;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int par = 0, impar = 0, g = 0;
        for (int i=1;i<=n;++i)
        {
            int z = 0, u = 0;
            cin>>s;
            for (auto x:s){
                if (x == '0'){
                    ++z;
                } else {
                    ++u;
                }
            }
            if (s.size()%2){
                ++impar;
            } else {
                ++par;
                if (z % 2 || u % 2){
                    ++g;
                }
            }
        }
        if (!impar && g % 2){
            cout<<n-1<<'\n';
        } else {
            cout<<n<<'\n';
        }
    }
    return 0;
}
