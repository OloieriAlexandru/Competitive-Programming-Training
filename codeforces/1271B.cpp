#include <bits/stdc++.h>
#define nmax 205
using namespace std;
int n;
string s;
bool tryy(vector<int>&v, char req){
    v.clear();
    string cp = s;
    for (int i=0;i<cp.size()-1;++i){
        if (cp[i] != req){
            v.push_back(i+1);
            cp[i] = req;
            cp[i+1] = (cp[i+1] == 'B' ? 'W' : 'B');
            //cout<<cp<<'\n';
        }
    }
    int sb = 0, sw = 0;
    for (auto x:cp){
        if (x == 'B'){
            ++sb;
        } else {
            ++sw;
        }
    }
    return (sb == n || sw == n);
}
void anss(vector<int>&ans){
    cout<<ans.size()<<'\n';
    for (auto x:ans){
        cout<<x<<' ';
    }
    cout<<'\n';
}
int main()
{
    vector<int>ans;
    cin>>n>>s;
    if (!tryy(ans,'B')){
        if (!tryy(ans,'W')){
            cout<<"-1\n";
        } else {
            anss(ans);
        }
    } else {
        anss(ans);
    }
    return 0;
}
