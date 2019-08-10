#include <bits/stdc++.h>
#define inf 999999999
#define nmax 300111
using namespace std;
int t;
string s;
int xx[nmax], yy[nmax];
int minx[nmax], maxx[nmax], miny[nmax], maxy[nmax];
int main()
{
    cin>>t;
    while(t--)
    {
        int x = 0, y = 0;
        cin>>s;
        if (s.size() == 1)
        {
            cout<<"2\n";
            continue;
        }
        int xmin = 0, ymin = 0, xmax = 0, ymax = 0;
        xx[0] = yy[0] = 0;
        for (int i=0; i<s.size(); ++i)
        {
            switch(s[i])
            {
            case 'W':
                ++y;
                ymin = min(ymin, y);
                ymax = max(ymax, y);
                break;
            case 'A':
                --x;
                xmin = min(xmin, x);
                xmax = max(xmax, x);
                break;
            case 'S':
                --y;
                ymin = min(ymin, y);
                ymax = max(ymax, y);
                break;
            case 'D':
                ++x;
                xmin = min(xmin, x);
                xmax = max(xmax, x);
                break;
            }
            xx[i+1] = x;
            yy[i+1] = y;
        }
        int nm = s.size()+1;
        minx[nm] = inf;
        maxx[nm] = -inf;
        miny[nm] = inf;
        maxy[nm] = -inf;
        for (int i=s.size(); i>=0; --i)
        {
            minx[i] = minx[i+1];
            maxx[i] = maxx[i+1];
            miny[i] = miny[i+1];
            maxy[i] = maxy[i+1];
            minx[i] = min(minx[i], xx[i]);
            maxx[i] = max(maxx[i], xx[i]);
            miny[i] = min(miny[i], yy[i]);
            maxy[i] = max(maxy[i], yy[i]);
        }
        minx[nm] = x;
        maxx[nm] = x;
        miny[nm] = y;
        maxy[nm] = y;
        long long w = xmax - xmin + 1;
        long long h = ymax - ymin + 1;
        long long ans = w * h;
        bool ok1 = false, ok2 = false, ok3 = false, ok4 = false;
        for (int i=0; i<=s.size(); ++i)
            if (xx[i] == xmax)
            {
                if (minx[i+1] != xmin) ok1 = true;
                break;
            }
        for (int i=0; i<=s.size(); ++i)
            if (xx[i] == xmin)
            {
                if (maxx[i+1] != xmax) ok3 = true;
                break;
            }
        for (int i=0; i<=s.size(); ++i)
            if (yy[i] == ymax)
            {
                if (miny[i+1] != ymin) ok2 = true;
                break;
            }
        for (int i=0; i<=s.size(); ++i)
            if (yy[i] == ymin)
            {
                if (maxy[i+1] != ymax) ok4 = true;
                break;
            }
        if ((ok1 || ok3) && w > 2)
            ans = min(ans, 1LL * max(1LL,w-1) * h);
        if ((ok2 || ok4) && h > 2)
            ans = min(ans, 1LL * max(1LL,h-1) * w);
        cout<<ans<<'\n';
    }
    return 0;
}
