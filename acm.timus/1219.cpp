#include <bits/stdc++.h>
#define mil 1000000
using namespace std;
string ans;
map<char,int>mp1;
map<pair<char,char>,int>mp2;
map<pair<char,pair<char,char>>,int>mp3;
int main()
{
    //ofstream fout("out.txt");
    srand(time(NULL));
    bool ok = false;
    while (!ok){
        ans.clear();
        mp1.clear();
        mp2.clear();
        mp3.clear();
        for (int i=1;i<=mil;++i){
            int nr = rand()%26;
            ans.push_back((char)(nr+'a'));
        }
        ++mp1[ans[0]];
        ++mp1[ans[1]];
        ++mp2[make_pair(ans[0],ans[1])];
        ok=true;
        /*for (int i=0;i<100;++i){
            cout<<ans[i];
        }
        cout<<'\n';*/
        for (int i=2;i<mil;++i){
            ++mp1[ans[i]];
            if (mp1[ans[i]] > 40000){
                ok=false;
                break;
            }
            ++mp2[make_pair(ans[i-1],ans[i])];
            if (mp2[make_pair(ans[i-1],ans[i])] > 2000){
                ok=false;
                break;
            }
            ++mp3[make_pair(ans[i-2],make_pair(ans[i-1],ans[i]))];
            if (mp3[make_pair(ans[i-2],make_pair(ans[i-1],ans[i]))] > 100){
                ok=false;
                break;
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}
