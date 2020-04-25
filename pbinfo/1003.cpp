#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
#define nmax
using namespace std;
int b1, b2;
lld v1, v2;
string s1, s2;
lld convert(const string& s, int b){
    lld bb = 1, res = 0;
    for (int i=s.size()-1;i>=0;--i){
        res += (s[i]-'0') * bb;
        bb *= b;
    }
    return res;
}
int main()
{
    freopen("baze1.in","r",stdin);
    freopen("baze1.out","w",stdout);

    cin>>b1>>b2;
    cin>>s1>>s2;

    v1 = convert(s1, b1);
    v2 = convert(s2, b2);

    cout<<v1+v2<<'\n';

    fclose(stdin);
    fclose(stdout);
    return 0;
}
