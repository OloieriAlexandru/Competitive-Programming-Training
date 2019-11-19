#include <bits/stdc++.h>
using namespace std;
string s;
char wh[128], ch1, ch2;
int n, m;
int main()
{
    cin>>n>>m;
    cin>>s;
    for (char ch='a'; ch<='z'; ++ch)
    {
        wh[ch]=ch;
    }
    while(m--)
    {
        cin>>ch1>>ch2;
        for (int i='a'; i<='z'; ++i)
        {
            if (wh[i]==ch1)
            {
                wh[i]=ch2;
            }
            else if (wh[i]==ch2)
            {
                wh[i]=ch1;
            }
        }
    }
    for (auto &x:s){
        x=wh[x];
    }
    cout<<s<<'\n';
    return 0;
}
