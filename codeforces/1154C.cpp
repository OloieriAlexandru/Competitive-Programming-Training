#include <bits/stdc++.h>
using namespace std;
int fish[7], rabbit[7], chicken[7];
int a, b, c, ans, act;
int main()
{
    fish[0] = fish[3] = fish[6] = 1;
    rabbit[1] = rabbit[5] = 1;
    chicken[2] = chicken[4] = 1;
    cin>>a>>b>>c;
    int weeks = a / 3;
    weeks = min(weeks, b / 2);
    weeks = min(weeks, c / 2);
    a -= weeks * 3;
    b -= weeks * 2;
    c -= weeks * 2;
    ans += weeks * 7;
    int actt = 0;
    for (int i=0;i<7;++i){
        int ca = a;
        int cb = b;
        int cc = c;
        int j = i;
        act = 0;
        while (true){
            ca -= fish[j];
            cb -= rabbit[j];
            cc -= chicken[j];
            ++j;
            ++act;
            if (j == 7){
                j = 0;
            }
            if (ca < 0 || cb < 0 || cc < 0){
                break;
            }
        }
        actt = max(actt, act);
    }
    cout<<ans+actt-1<<'\n';
    return 0;
}
