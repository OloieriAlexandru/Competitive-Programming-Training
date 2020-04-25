#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
#define nmax
using namespace std;
int main()
{
    freopen("xorcrypt.in","r",stdin);
    freopen("xorcrypt.out","w",stdout);
    string s1, s2;
    std::getline(cin, s1);
    std::getline(cin, s2);
    for (int i=0;i<s1.size();++i){
        bitset<8> v1(s1[i]);
        bitset<8> v2(s2[i]);
        cout<<(v1^v2)<<' ';
    }
    cout<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
