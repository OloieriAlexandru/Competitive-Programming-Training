#include <iostream>

using namespace std;

int main()
{
    int n, cn1 = 0, cn2 = 0;
    string s;
    cin>>n;
    cin>>s;
    for (int i=0;i<n-1;++i){
        if (s[i] != s[i+1]){
            if (s[i] == 'S'){
                ++cn1;
            } else {
                ++cn2;
            }
        }
    }
    if (cn1 > cn2){
        cout<<"Yes\n";
    } else {
        cout<<"No\n";
    }
    return 0;
}
