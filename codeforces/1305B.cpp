#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
#define nmax
using namespace std;
vector<vector<int>>ans;
int main()
{
    string s;
    cin>>s;
    while (true){
        int st = 0, dr = s.size()-1;
        while (st < s.size() && s[st] == ')'){
            ++st;
        }
        if (st == s.size()){
            break;
        }
        while (dr >= 0 && s[dr] == '('){
            --dr;
        }
        if (dr == -1){
            break;
        }
        vector<int>add;
        unordered_set<int>del;
        while (st < dr && st < s.size() && dr >= 0){
            add.pb(st+1);
            add.pb(dr+1);
            del.insert(st);
            del.insert(dr);
            ++st;
            while (st < s.size() && s[st] == ')'){
                ++st;
            }
            --dr;
            while (dr >= 0 && s[dr] == '('){
                --dr;
            }
        }
        sort(add.begin(),add.end());
        if (!add.size()){
            break;
        }
        ans.push_back(add);
        string cs;
        for (int i=0;i<s.size();++i){
            if (!del.count(i)){
                cs.pb(s[i]);
            }
        }
        s = cs;
    }
    cout<<ans.size()<<'\n';
    for (int i=0;i<ans.size();++i){
        cout<<ans[i].size()<<'\n';
        for (int j=0;j<ans[i].size();++j){
            cout<<ans[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
