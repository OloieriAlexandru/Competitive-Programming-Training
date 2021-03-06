#include <bits/stdc++.h>
#define nmax 1000005
using namespace std;
bool inRoom[nmax];
int n, x, vx, curr, lst;
vector<int>ans;
set<int>st;
int main()
{
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x;
        if (x<0){
            vx = -x;
            if (!inRoom[vx]){
                cout<<"-1\n";
                return 0;
            }
            inRoom[vx]=0;
            --curr;
            if (!curr){
                ans.push_back(i-lst);
                lst=i;
                st.clear();
            }
        } else {
            if (inRoom[x]){
                cout<<"-1\n";
                return 0;
            }
            if (st.count(x)){
                cout<<"-1\n";
                return 0;
            }
            st.insert(x);
            inRoom[x]=1;
            ++curr;
        }
    }
    if (curr){
        cout<<"-1\n";
        return 0;
    }
    cout<<ans.size()<<'\n';
    for (auto x:ans){
        cout<<x<<' ';
    }
    cout<<'\n';
    return 0;
}
