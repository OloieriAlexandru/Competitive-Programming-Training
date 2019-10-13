#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
map<char,char>mapp;
set<char>st;
void init()
{
    vector<pair<string,string>>v;
    v.pb(mp("CARS","Unil"));
    v.pb(mp("cars","EPFL"));
    v.pb(mp("IuVEJxTXs UvOHhng yZKfAYmaqolM","vpVZzBNtL SCubWma ocIYneAPqxDs"));
    v.pb(mp("NtGQibw djPrCpek FWzL","hRkMGgJ fHrFUQTj XOwd"));
    v.pb(mp("aySBaPyb RM gzYMynY","PolyProg is awesome"));
    for (auto x:v)
    {
        for (int i=0; i<x.first.size(); ++i)
        {
            mapp[x.first[i]] = x.second[i];
            st.insert(x.second[i]);
        }
    }
    for (char ch = 'a';ch<='z';++ch)
    {
        if (!st.count(ch))
            mapp['D'] = ch;
    }
    for (char ch = 'A';ch<='Z';++ch)
    {
        if (!st.count(ch))
            mapp['D'] = ch;
    }
}
int main()
{
    int n;
    string s;
    init();
    cin>>n;
    for (int i=1; i<=n; ++i)
    {
        cin>>s;
        for (auto &x:s)
            x = mapp[x];
        cout<<s<<' ';
    }
    //for (auto x:mapp)
    //    cout<<x.first<<' '<<x.second<<'\n';
    cout<<'\n';
    return 0;
}
