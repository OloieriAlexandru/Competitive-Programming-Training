#include <bits/stdc++.h>
#define nmax 26
using namespace std;
int fv[nmax];
int nrimp;
char ch;
string s;
string p1, p2;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        cin>>s;
        memset(fv,0,sizeof(fv));
        for (auto x:s)
            ++fv[x-'a'];
        nrimp = 0;
        p1.clear();
        p2.clear();
        for (int i=0; i<26; ++i)
        {
            if (fv[i]%2)
            {
                ++nrimp;
                ch = i + 'a';
            }
            for (int j=0; j<fv[i]/2; ++j)
            {
                p1.push_back(i+'a');
                p2.push_back(i+'a');
            }
        }
        sort(p1.begin(), p1.end());
        sort(p2.begin(), p2.end());
        reverse(p2.begin(), p2.end());
        if (nrimp > 1)
            cout<<"impossible\n";
        else
        {
            cout<<p1;
            if (nrimp) cout<<ch;
            cout<<p2<<'\n';
        }
    }
    return 0;
}
