#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>>ans;
int b, w, t, start, act;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&b,&w);
        ans.clear();
        if (b >= w)
            start = 1;
        else start = 2;
        if (b > w) swap(b, w);
        act = start;
        while (b)
        {
            ans.push_back(make_pair(2, act));
            ++act;
            ans.push_back(make_pair(2,act));
            ++act;
            --b, --w;
        }
        if (w)
        {
            ans.push_back(make_pair(2,act));
            ++act;
            --w;
        }
        for (int i=start+1; i<act && w; i+=2)
        {
            ans.push_back(make_pair(1,i));
            --w;
        }
        for (int i=start+1; i<act && w; i+=2)
        {
            ans.push_back(make_pair(3,i));
            --w;
        }
        if (b == 0 && w == 0)
        {
            cout<<"YES\n";
            for (int i=0; i<ans.size(); ++i)
                cout<<ans[i].first<<' '<<ans[i].second<<'\n';
        }
        else cout<<"NO\n";
    }
        return 0;
}
