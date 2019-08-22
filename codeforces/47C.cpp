#include <bits/stdc++.h>
#define nmax 66
using namespace std;
vector<string>v;
const int n = 6;
int perm[n], ln[n], w, h;
bool uz[n];
char mat[nmax][nmax];
vector<string>ans, act;
bool solExists;
bool checkSetVertical(string &s, int line, int col)
{
    for (int i=0;i<s.size();++i)
        if (s[i] != mat[line+i][col] && mat[line+i][col] != '.') return false;
    return true;
}
void setVertical(string &s, int line, int col)
{
    for (int i=0;i<s.size();++i)
        mat[line+i][col] = s[i];
}
bool checkSetHorizontal(string &s, int line, int col)
{
    for (int i=0;i<s.size();++i)
        if (s[i] != mat[line][col+i] && mat[line][col+i] != '.') return false;
    return true;
}
void setHorizontal(string &s, int line, int col)
{
    for (int i=0;i<s.size();++i)
        mat[line][col+i] = s[i];
}
bool check()
{
    for (int i=0;i<nmax;++i)
        for (int j=0;j<nmax;++j)
            mat[i][j] = '.';
    for (int i=0;i<6;++i)
        ln[i] = v[perm[i]].size();
    setHorizontal(v[perm[0]], 0, 0);
    if (!checkSetVertical(v[perm[1]], 0, 0)) return false;
    setVertical(v[perm[1]], 0, 0);
    if (ln[2] < 5 || ln[2] < ln[1] ||!checkSetVertical(v[perm[2]], 0, ln[0]-1)) return false;
    setVertical(v[perm[2]], 0, ln[0]-1);
    if (ln[3] < 5 || ln[3] < ln[0] || !checkSetHorizontal(v[perm[3]], ln[1]-1, 0)) return false;
    setHorizontal(v[perm[3]], ln[1]-1, 0);
    if (!checkSetVertical(v[perm[4]], ln[1]-1, ln[3]-1)) return false;
    setVertical(v[perm[4]], ln[1]-1, ln[3]-1);
    if (!checkSetHorizontal(v[perm[5]], ln[2]-1, ln[0]-1)) return false;
    setHorizontal(v[perm[5]], ln[2]-1, ln[0]-1);
    h = ln[2];
    w = ln[3];
    if (ln[0] + ln[5] - 1 != w) return false;
    if (ln[1] + ln[4] - 1 != h) return false;
    return true;
}
void gen(int k)
{
    if (k == n)
    {
        if (check())
        {
            act.clear();
            for (int i=0;i<h;++i)
            {
                string nw;
                for (int j=0;j<w;++j)
                    nw.push_back(mat[i][j]);
                act.push_back(nw);
            }
            if (!solExists)
                solExists = true, ans = act;
            else
            if (act < ans)
                ans = act;
        }
        return;
    }
    for (int i=0;i<n;++i)
    {
        if (uz[i]) continue;
        uz[i] = true;
        perm[k] = i;
        gen(k+1);
        uz[i] = false;
    }
}
int main()
{
    for (int i=0;i<n;++i)
    {
        string act;
        cin>>act;
        v.push_back(act);
    }
    sort(v.begin(), v.end());
    gen(0);
    if (!solExists)
        cout<<"Impossible\n";
    else
    {
        for (auto x:ans)
            cout<<x<<'\n';
    }
    return 0;
}
