#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstring>
#define lld long long
using namespace std;

vector<int>masks;
string act;
map<int,int>m;
int n;

int fv[26];

int getMask()
{
    memset(fv, 0, sizeof(fv));
    int ret = 0;
    int lg = act.length();
    for (int i=0;i<lg;++i)
    {
        ++fv[act.at(i)-'a'];
    }
    for (int i=0;i<26;++i)
    {
        if (fv[i]%2)
        {
            ret|=(1<<i);
        }
    }
    return ret;
}

lld ans;

int main()
{
    cin>>n;
    for (int i =1;i<=n;i++)
    {
        cin>>act;
        int mask = getMask();
        masks.push_back(mask);
        ++m[mask];
        //cout<<mask<<'\n';
    }
    for (auto i=0u;i<masks.size();++i)
    {
        int act = masks[i];
        ans+=(m[act]-1);
        for (int i=0;i<26;++i)
        {
            int x = act^(1<<i);
            ans+=(m[x]);
        }
    }
    ans/=2;
    cout<<ans<<'\n';
    return 0;
}
