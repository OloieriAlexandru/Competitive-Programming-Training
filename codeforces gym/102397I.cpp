#include <iostream>

using namespace std;

int main()
{
    int n;
    string s;
    int fv[5] = {0};
    cin>>n>>s;
    for (auto x:s){
        ++fv[x-'a'];
    }
    int maxx = -1, minn = 999999999;
    for (int i=0;i<5;++i){
        maxx=max(maxx,fv[i]);
        minn=min(minn,fv[i]);
    }
    cout<<minn<<' '<<maxx<<'\n';
    return 0;
}
