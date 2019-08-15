#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>>positives_e;
vector<pair<int,int>>negatives_e;
int n, r, x, y;
int main()
{
    cin>>n>>r;
    for (int i=1; i<=n; ++i)
    {
        cin>>x>>y;
        if (y >= 0) positives_e.push_back(make_pair(x,y));
        else negatives_e.push_back(make_pair(max(x,abs(y)),y));
    }
    sort(positives_e.begin(), positives_e.end(), [](pair<int,int> a, pair<int,int> b)
    {
        return a.first < b.first;
    });
    sort(negatives_e.begin(), negatives_e.end(), [](pair<int,int> a, pair<int,int> b)
    {
        return a.first + a.second > b.first + b.second;
    });
    for (int i=0; i<positives_e.size(); ++i)
    {
        if (r < positives_e[i].first)
        {
            cout<<"NO\n";
            return 0;
        }
        r += positives_e[i].second;
    }
    for (int i=0; i<negatives_e.size(); ++i)
    {
        if (r < negatives_e[i].first)
        {
            cout<<"NO\n";
            return 0;
        }
        r += negatives_e[i].second;
    }
    if (r < 0)
    {
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    return 0;
}
