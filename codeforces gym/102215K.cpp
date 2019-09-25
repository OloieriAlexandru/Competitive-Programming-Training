#include <bits/stdc++.h>
using namespace std;
string s;
string v1;
string v2;
char ch1, ch2, ch3;
bool ok, st1, st2;
char lit[] = {0, 'R', 'G', 'B'};
int main()
{
    cin>>s;
    for (int i=1; i<=3 && !ok; ++i)
        for (int j=1; j<=3 && !ok; ++j)
            for (int k=1; k<=3 && !ok; ++k)
            {
                if (i == j || i == k || j == k) continue;
                v1.clear();
                v2.clear();
                ch1 = lit[i];
                ch2 = lit[j];
                ch3 = lit[k];
                st1 = st2 = false;
                int index;
                for (index=0; index<s.size(); ++index)
                {
                    if (s[index] == ch1 && !st1) continue;
                    if (s[index] == ch2 && !st2) continue;
                    if (s[index] == ch3 && st2) continue;
                    if (s[index] == ch3 && !st2)
                    {
                        st2 = true;
                        continue;
                    }
                    if (s[index] == ch2 && st2)
                    {
                        st1 = true;
                        continue;
                    }
                    if (s[index] == ch1 && st1)
                        break;
                }
                if (index == s.size())
                {
                    ok = true;
                    //cout<<ch1<<' '<<ch2<<' '<<ch3<<'\n';
                    continue;
                }
                st1 = st2 = false;
                for (index = 0; index < s.size();++index)
                {
                    if (s[index] == ch3) continue;
                    if (s[index] == ch1 && !st1) continue;
                    if (s[index] == ch2 && st1) continue;
                    if (s[index] == ch2 && !st1)
                    {
                        st1 = true;
                        continue;
                    }
                    if (s[index] == ch1 && st1) break;
                }
                if (index == s.size())
                {
                    ok = true;
                    //cout<<ch1<<' '<<ch2<<' '<<ch3<<'\n';
                    continue;
                }
            }
    if (ok)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}
