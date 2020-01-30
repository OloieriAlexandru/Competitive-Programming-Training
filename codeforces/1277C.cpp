#include <bits/stdc++.h>
#define nmax 150005
using namespace std;
char s[nmax];
int n;
bool del[nmax];
vector<int>ans;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        ans.clear();
        n = strlen(s);
        for (int i=0;i<n;++i){
            if (!strncmp(s+i,"twone",5)){
                del[i+2] = true;
                i += 4;
                continue;
            }
            if (!strncmp(s+i,"two", 3) && !del[i] && !del[i+1] && !del[i+2]){
                del[i+1] = true;
                i += 2;
                continue;
            }
            if (!strncmp(s+i,"one",3) && !del[i] && !del[i+1] && !del[i+2]){
                del[i+1] = true;
                i += 2;
                continue;
            }
        }
        for (int i=0;i<n;++i){
            if (del[i]){
                ans.push_back(i);
            }
        }
        for (int i=0;i<n;++i){
            del[i] = false;
        }
        cout<<ans.size()<<'\n';
        for (auto x:ans){
            cout<<(x+1)<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
