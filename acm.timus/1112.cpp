#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define mp make_pair
#define pii pair<int,int>
#define pb push_back

using namespace std;

int n;
vector<pii>v;
vector<int>indexAns;
int lft, rght;

int main()
{
    cin>>n;
    for (int i=1; i<=n; ++i)
    {
        cin >> lft >> rght;
        if (lft > rght)
        {
            swap(lft, rght);
        }
        v.pb(mp(lft, rght));
    }
    sort(v.begin(), v.end(), [](pii a, pii b)
    {
        if (a.second == b.second)
        {
            return a.first > b.first;
        }
        return a.second < b.second;
    });
    int ans = 1;
    int big = v[0].second;
    indexAns.push_back(0);
    for (int i=0;i<v.size();++i)
    {
        if (v[i].first>=big)
        {
            indexAns.push_back(i);
            big = v[i].second;
            ++ans;
        }
    }
    cout<<ans<<'\n';
    for (int i=0;i<indexAns.size();++i)
    {
        cout<<v[indexAns[i]].first<<' '<<v[indexAns[i]].second<<'\n';
    }
    return 0;
}