#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    vector<int>fv(26,0);
    for (auto x:s){
        ++fv[x-'a'];
    }
    int diff = 0, m1 = 0;
    for (auto x:fv){
        if (!x){
            continue;
        }
        ++diff;
        if (x > 1){
            ++m1;
        }
    }
    if (diff == 2 || diff == 3 || diff == 4){
        if (diff == 2){
            if (m1 > 1){
                cout<<"Yes\n";
            } else {
                cout<<"No\n";
            }
        } else if (diff == 3){
            if (m1){
                cout<<"Yes\n";
            } else {
                cout<<"No\n";
            }
        } else {
            cout<<"Yes\n";
        }
    } else {
        cout<<"No\n";
    }
    return 0;
}
