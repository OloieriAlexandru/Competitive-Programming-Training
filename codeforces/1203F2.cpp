#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>>positives_e;
vector<pair<int,int>>negatives_e;
int n, r, x, y, ans;
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
        if (r < positives_e[i].first) continue;
        r += positives_e[i].second;
        ++ans;
    }
    int neg = negatives_e.size();
    vector<vector<int>>dp(neg + 2, vector<int>(r + 2, 0));
    dp[0][r] = ans;
    for (int i=0;i<neg;++i)
    {
        for (int j = 0; j<=r;++j)
        {
            if (j >= negatives_e[i].first && j + negatives_e[i].second >= 0)
                dp[i+1][j + negatives_e[i].second] = max(dp[i+1][j+negatives_e[i].second], dp[i][j] + 1);
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
        }
    }
    for (int i=0;i<=r;++i)
        ans = max(ans, dp[neg][i]);
    cout<<ans<<'\n';
    return 0;
}
