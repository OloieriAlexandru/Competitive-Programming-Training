#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
queue<pair<string,int>>q;
vector<pair<char,string>>v;
unordered_set<string>found;
int n;
char start, ch;
string word, repl;
bool match(const string& s, int idx, const string& look){
    if (idx+look.size()-1>s.size()){
        return false;
    }
    for (int i=0;i<look.size();++i){
        if (s[idx+i]!=look[i]){
            return false;
        }
    }
    return true;
}
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>start>>word;
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>ch>>repl;
        v.pb(mp(ch,repl));
    }
    q.push(make_pair(word,0));
    found.insert(word);
    while (!q.empty()){
        auto act = q.front();
        q.pop();
        if (act.first.size() == 1 && act.first[0] == start){
            cout<<act.second<<'\n';
            return 0;
        }
        for (int i=0;i<act.first.size();++i){
            for (int j=0;j<v.size();++j){
                if (match(act.first,i,v[j].second)){
                    string add;
                    for (int k=0;k<i;++k){
                        add.push_back(act.first[k]);
                    }
                    add.push_back(v[j].first);
                    for (int k=i+v[j].second.size();k<act.first.size();++k){
                        add.push_back(act.first[k]);
                    }
                    if (!found.count(add)){
                        q.push(make_pair(add, act.second+1));
                        found.insert(add);
                    }
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
