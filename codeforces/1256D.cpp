#include <bits/stdc++.h>
using namespace std;
string s;
vector<int>zeros;
int main()
{
    int t, n;
    cin>>t;
    while(t--)
    {
        long long k;
        cin>>n>>k;
        cin>>s;
        zeros.clear();
        for (int i=0;i<s.size();++i){
            if (s[i] == '0'){
                zeros.push_back(i);
            }
        }
        int curr = 0;
        for (int i=0;i<s.size();++i){
            if (s[i] == '0') {
                continue;
            }
            while (curr < zeros.size() && zeros[curr] < i)
                ++curr;
            if (curr < zeros.size()){
                int d = abs(zeros[curr]-i);
                if (d <= k){
                    k -= d;
                    swap(s[i],s[zeros[curr++]]);
                }
            }
        }
        cout<<s<<'\n';
    }
    return 0;
}
