#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<pair<int,int>>lens;
    string s;
    int n = 4;
    for (int i=1;i<=n;++i){
        cin>>s;
        lens.push_back(make_pair(s.size()-2,i));
    }
    sort(lens.begin(), lens.end());
    int pos = 0, ans;
    if (lens[0].first != lens[1].first){
        if (lens[0].first * 2 <= lens[1].first){
            ++pos;
            ans = lens[0].second;
        }
    }
    if (lens[3].first != lens[2].first){
        if (lens[2].first * 2 <= lens[3].first){
            ++pos;
            ans = lens[3].second;
        }
    }
    if (pos == 1){
        cout<<(char)((-1+ans)+'A')<<'\n';
    } else {
        cout<<"C\n";
    }
    return 0;
}
