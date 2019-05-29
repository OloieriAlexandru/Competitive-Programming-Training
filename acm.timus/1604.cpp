#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <functional>
#define pii pair<int,int>
#define mp make_pair

using namespace std;

int n;
int k;
priority_queue<pii, vector<pii>, less<pii> >hp;

int main()
{
    cin>>n;
    for (int i=1; i<=n; ++i)
    {
        cin>>k;
        hp.push(mp(k, i));
    }
    while (!hp.empty())
    {
        pii first = hp.top();
        cout<<first.second<<' ';
        --first.first;
        hp.pop();
        if (!hp.empty())
        {
            pii second = hp.top();
            hp.pop();
            cout<<second.second<<' ';
            --second.first;
            if (second.first)
            {
                hp.push(second);
            }
        }
        if (first.first)
        {
            hp.push(first);
        }
    }
    return 0;
}